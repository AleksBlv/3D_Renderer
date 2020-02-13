#include "Loader.h"
#include <Renderer.h>



Model* Loader::loadToVAO(std::vector<float>& verteces, std::vector<int>& indices, std::vector<float>& textures, std::vector<float>& normals)
{
	GLuint vaoID = createVAO();
	GLuint eboID = bindIndices(indices);
	storeDataInVAO(0, 3, verteces);
	storeDataInVAO(1, 2, textures);
	storeDataInVAO(2, 3, normals);
	unbindVAO();
	Model* model = new Model(vaoID, eboID, indices.size());
	return model;
}

Model* Loader::loadObj(const GLchar* fPath)
{
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> textures;
	std::vector<glm::vec3> normals;
	std::vector<int> indices;
	std::vector<float> dataVertices;
	std::vector<float> dataTextures;
	std::vector<float> dataNormals;

	bool resized = false;
	
	FILE* file = fopen(fPath, "r");
	if (file == NULL) {
		printf("Impossible to open the file !\n");
		return false;
	}
	while (true) 
	{

		char lineHeader[128];
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break;

		if (strcmp(lineHeader, "v") == 0)
		{
			glm::vec3 vertex;
			fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
			vertices.push_back(vertex);
		}
		else if (strcmp(lineHeader, "vt") == 0)
		{
			glm::vec2 uv;
			fscanf(file, "%f %f\n", &uv.x, &uv.y);
			textures.push_back(uv);
		}
		else if (strcmp(lineHeader, "vn")==0)
		{
			glm::vec3 normal;
			fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
			normals.push_back(normal);
		}
		else if (strcmp(lineHeader, "f")==0)
		{
			if (!resized)
			{
				dataTextures.resize(vertices.size() * 2);
				dataNormals.resize(vertices.size() * 3);
				resized = true;
			}

			std::vector <int> vert1;
			vert1.resize(3);
			std::vector <int> vert2;
			vert2.resize(3);
			std::vector <int> vert3;
			vert3.resize(3);

			fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vert1[0], &vert1[1], &vert1[2], &vert2[0], &vert2[1], &vert2[2], &vert3[0], &vert3[1], &vert3[2]);
			processData(vert1, indices, textures, normals, dataTextures, dataNormals);
			processData(vert2, indices, textures, normals, dataTextures, dataNormals);
			processData(vert3, indices, textures, normals, dataTextures, dataNormals);

		}
	}

	dataVertices.resize(vertices.size() * 3);
	

	int vertexPointer = 0;
	for (glm::vec3 vertex : vertices)
	{
		dataVertices[vertexPointer++] = vertex.x;
		dataVertices[vertexPointer++] = vertex.y;
		dataVertices[vertexPointer++] = vertex.z;
	}

	return loadToVAO(dataVertices, indices, dataTextures, dataNormals);
}

void Loader::storeDataInVAO(int attributePointer, int coordinateSize, std::vector<float>& data)
{
	GLuint vboID;
	glGenBuffers(1, &vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * data.size(), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(attributePointer, coordinateSize, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(attributePointer);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}


GLuint Loader::bindIndices(std::vector<int>& indices)
{
	GLuint eboID;
	glGenBuffers(1, &eboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * indices.size(), indices.data(), GL_STATIC_DRAW);
	return eboID;
}

void Loader::unbindVAO()
{
	glBindVertexArray(0);
}

GLuint Loader::createVAO()
{
	GLuint vaoID;
	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);
	return vaoID;
}

void splitString(std::string str, char delimiter, std::vector<std::string>& outStr)
{
	if (!outStr.empty())
	{
		outStr.clear();
	}
	std::string token;
	std::istringstream stream(str);
	while (std::getline(stream, token, delimiter))
	{
		outStr.push_back(token);
	}
}

void processData(std::vector<int> vertexData, std::vector<int>& indices, std::vector<glm::vec2>& textures, std::vector<glm::vec3>& normals,
	std::vector<float>& dataTextures, std::vector<float>& dataNormals)
{
	int currentVertexPointer = vertexData[0] - 1; /*std::stoi(vertexData[0]) - 1;*/
	indices.push_back(currentVertexPointer);
	glm::vec2 curretntTex = textures[vertexData[1] - 1];/*textures[std::stoi(vertexData[1]) - 1];*/
	dataTextures[currentVertexPointer * 2] = curretntTex.x;
	dataTextures[currentVertexPointer * 2 + 1] = 1 - curretntTex.y;
	glm::vec3 currentNorm = normals[vertexData[2] - 1]; /*normals[std::stoi(vertexData[2]) - 1];*/
	dataNormals[currentVertexPointer * 3] = currentNorm.x;
	dataNormals[currentVertexPointer * 3 + 1] = currentNorm.y;
	dataNormals[currentVertexPointer * 3 + 2] = currentNorm.z;
}
