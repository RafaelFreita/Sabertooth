#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <GL\glew.h>

class Drawable
{

private:
	GLuint VAO, VBO;

public:
	Drawable();
	~Drawable();

	GLuint getVAO() { return VAO; }
	GLuint getVBO() { return VBO; }

	void Draw();

	void Delete();

};

#endif