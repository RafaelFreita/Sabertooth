#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <GL\glew.h>

#include "Drawable.h"

class Triangle
{
private:

	Drawable object;
	GLfloat vertices[18] = {
		// Positions		// Colors
		0.0f, 0.0f, 0.0f,	0.0f, 0.0f, 0.0f,	// Bottom Right
		0.0f, 0.0f, 0.0f,	0.0f, 0.0f, 0.0f,	// Bottom Left
		0.0f, 0.0f, 0.0f,	0.0f, 0.0f, 0.0f,	// Top Center
	};

public:
	Triangle();
	~Triangle();

	GLfloat* GetVertices() { return vertices; }

	void SetVerticesPositions(GLfloat positions[9]);
	void SetVerticesColors(GLfloat colors[9]);

	void SetVerticesPositions(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3);
	void SetVerticesColors(GLfloat r1, GLfloat g1, GLfloat b1, GLfloat r2, GLfloat g2, GLfloat b2, GLfloat r3, GLfloat g3, GLfloat b3);
	
	void BindBuffers();

	void Draw();

};

#endif