#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <GL\glew.h>

class Drawable
{

protected:
	GLuint VAO, VBO;

	GLfloat *vertices;
	int verticesQtd;

public:
	Drawable();
	~Drawable();

	virtual void Create() = 0;

	void BindVertices();

	void SetVertices( GLfloat *vertices, int verticesQtd );

	void Draw();
	void Delete();

	GLuint getVAO() { return VAO; }
	GLuint getVBO() { return VBO; }

};

#endif