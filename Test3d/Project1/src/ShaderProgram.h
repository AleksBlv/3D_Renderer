#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


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
	
};

