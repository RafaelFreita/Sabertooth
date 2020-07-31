#include "Shader.h"


Shader::~Shader()
{
}

void Shader::UseTexture(std::string textureName)
{
	glActiveTexture(GL_TEXTURE0 + textures[textureName].GetTextureNum());
	glBindTexture(GL_TEXTURE_2D, textures[textureName].GetTextureId());
}

void Shader::LoadTexture(char* path, char* textureUniformName, std::string textureName)
{
	Texture tempTexture(path, textureUniformName, program, textureQtd);
	textures[textureName] = tempTexture;
	textureQtd += 1;
}
