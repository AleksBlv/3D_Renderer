#pragma once

#include "Model.h"
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


class Loader
{

public:
	Model* loadToVAO(std::vector<float>&verteces, std::vector<int>& indices, std::vector<float>& textures);
	Model* loadObj(const GLchar* fPath);
private:
	void storeDataInVAO(int attribpointer, int coordinateSize, std::vector<float>& data);
	GLuint bindIndices(std::vector<int>& indices);
	void unbindVAO();
	GLuint createVAO();
};

