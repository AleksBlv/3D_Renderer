#include "Texture.h"
#include "fromGit/stb_image.h"

Texture::Texture(const GLchar* filePath)
	: localBuffer(nullptr), tWidth(0), tHeight(0), tBBP(0), textureID(0)
{
	//грузим данные в буфер
	stbi_set_flip_vertically_on_load(1);
	localBuffer = stbi_load(filePath, &tWidth, &tHeight, &tBBP, 4);

	//создаем текстуру, получаем ее id
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	//выставляем параметры
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//грузим данные в видеопамять?
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, tWidth, tHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer);
	glBindTexture(GL_TEXTURE_2D, textureID);

}

Texture::~Texture()
{
	glDeleteTextures(1, &textureID);
}

void Texture::bind(unsigned int slot)
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, textureID);
}

void Texture::unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

unsigned int Texture::getID()
{
	return textureID;
}
