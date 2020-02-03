#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
class Texture
{
private:
	unsigned int textureID;
	unsigned char* localBuffer;
	int tWidth, tHeight, tBBP;
public:
	Texture(const GLchar* filePath);
	~Texture();

	void bind(unsigned int slot);
	void unbind();
	unsigned int getID();

};

