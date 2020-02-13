#pragma once

#include "Model.h"
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <sstream>
#include <fstream>
#include <string>
#include "tools/Tools.h"
#include <iostream>
#include "fromGit/glm/vec2.hpp"
#include "fromGit/glm/vec3.hpp"



class Loader
{

public:
	Model* loadToVAO(std::vector<float>&verteces, std::vector<int>& indices, std::vector<float>& textures, std::vector<float>& normals);
	Model* loadObj(const GLchar* fPath);
private:
	void storeDataInVAO(int attribpointer, int coordinateSize, std::vector<float>& data);
	GLuint bindIndices(std::vector<int>& indices);
	void unbindVAO();
	GLuint createVAO();
	
};

void splitString(std::string str, char demiter, std::vector<std::string>& outStr);
void processData(std::vector<int> vertexData, std::vector<int>& indices, std::vector<glm::vec2>& textures, std::vector<glm::vec3>& normals,
	std::vector<float>& dataTextures, std::vector<float>& dataNormals);
