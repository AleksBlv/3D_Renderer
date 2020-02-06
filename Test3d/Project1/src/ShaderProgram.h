#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "fromGit/glm/mat4x4.hpp"
#include "fromGit/glm/vec3.hpp"
#include "fromGit/glm/ext/matrix_transform.hpp"
#include <fromGit/glm/gtc/type_ptr.hpp>


class ShaderProgram
{
private:
	GLuint progID;
public:
	ShaderProgram();
	void loadShaders(const GLchar* vPath, const GLchar* fPath);
	GLuint getProgID();
	void Use();
	void Stop();
private:
	GLuint loadAndAttachShader(const GLchar* Path, int type);
public:
	void loadVec4(int location, float x, float y, float z, float alpha);
	void load1f(int location, float x);
	void loadMat4x4(int location, glm::mat4x4 matrix);
	
};

