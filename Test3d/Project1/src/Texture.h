#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
class Texture
{
private:
	unsigned int textureID;
	unsigned char* localBuffer;
	int tWidth, tHeight, tBBP;
	float shineDumper = 1;
	float reflectivity = 0;
public:
	Texture(const GLchar* filePath);
	~Texture();
	float getShineDumper() { return shineDumper; }
	float getReflectivity() { return reflectivity; }
	void setShineDumper(float dump) { shineDumper = dump; }
	void setReflectivity(float reflect) { reflectivity = reflect; }
	void bind(unsigned int slot);
	void unbind();
	unsigned int getID();

};

