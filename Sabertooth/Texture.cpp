#include "Texture.h"



Texture::Texture() : textureID(NULL), textureLocation(NULL), textureNum(NULL)
{
}

Texture::Texture(char* path, char* textureUniformName, GLuint shaderProgram, GLint textureNum)
{
	this->textureNum = textureNum;

	glGenTextures(1, &textureID);

	int width, height;
	unsigned char* image;

	textureLocation = glGetUniformLocation(shaderProgram, textureUniformName);

	glActiveTexture(GL_TEXTURE0 + this->textureNum);
	glBindTexture(GL_TEXTURE_2D, textureID);

	AssetManager::LoadImage(path);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glUniform1i(textureLocation, this->textureNum);

	glBindTexture(GL_TEXTURE_2D, 0);
}


Texture::~Texture()
{
}