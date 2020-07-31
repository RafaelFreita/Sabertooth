#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "AssetManager.h"

class Texture
{
private:
	GLuint textureID;
	GLint textureLocation;
	GLshort textureNum;

public:
	Texture();
	Texture(char* path, char* textureUniformName, GLuint shaderProgram, GLint textureNum);
	~Texture();

	GLuint GetTextureId() { return textureID; }
	GLshort GetTextureNum() { return textureNum; }

};

#endif