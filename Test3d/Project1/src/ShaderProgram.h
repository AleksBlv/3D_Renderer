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
	void loadVec4(int location, float x, float y, float z, float alpha);
	void load1f(int location, float x);
	
	
};

