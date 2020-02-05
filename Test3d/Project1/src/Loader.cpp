#include "Loader.h"
#include <Renderer.h>



Model* Loader::loadToVAO(std::vector<float>& verteces, std::vector<int>& indices, std::vector<float>& textures)
{
	GLuint vaoID = createVAO();
	GLuint eboID = bindIndices(indices);
	storeDataInVAO(0, 3, verteces);
	storeDataInVAO(1, 2, textures);
	unbindVAO();
	Model* model = new Model(vaoID, eboID, indices.size());
	return model;
}

Model* Loader::loadObj(const GLchar* fPath)
{
	std::string str;
	std::ifstream file(fPath);
	
	std::vector<Tools::Vec3f> vertices;
	std::vector<Tools::Vec2f> textures;
	std::vector<Tools::Vec3f> normals;
	std::vector<int> indices;

	while (std::getline(file, str))
	{
		if (str.substr(0, 2) == "v ")
		{
			std::istringstream v(str.substr(2));
			Tools::Vec3f vert;
			float x, y, z;
			v >> x; v >> y; v >> z;
			vert = Tools::Vec3f(x, y, z);
			vertices.push_back(vert);

		}
		else if (str.substr(0, 2) == "vt")
		{
			std::istringstream v(str.substr(3));
			Tools::Vec2f text;
			float x, y;
			v >> x; v >> y;
			text = Tools::Vec2f(x, y);
			textures.push_back(text);
		}
		else if (str.substr(0, 2) == "vn")
		{
			std::istringstream v(str.substr(3));
			Tools::Vec3f norm;
			float x, y, z;
			v >> x; v >> y; v >> z;
			norm = Tools::Vec3f(x, y, z);
			normals.push_back(norm);
		}
		else if (str.substr(0, 2) == "f ")
		{
			std::vector < std::string> subStrings;
			splitString(str, ' ', subStrings);
			for (int i = 1; i < 4; i++)
			{
				int v, t, n;
				std::vector < std::string> subSubStrings;
				splitString(subStrings[i], '/', subSubStrings);
				indices.push_back(std::stoi(subSubStrings[0]));
				indices.push_back(std::stoi(subSubStrings[1]));
				indices.push_back(std::stoi(subSubStrings[2]));
			}


		}
	}


	return nullptr;
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
