#include "Loader.h"
#include <Renderer.h>
#include <iostream>

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
	
	//FILE* file = fopen(fPath, "r");
	//if (file == NULL) 
	//{
	//	std::cout << "Couldn't open file " << std::endl;
	//	return nullptr;
	//}
	//while (true)
	//{
	//	char lineHeader[512];

	//}

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


