#include "Triangle.h"



Triangle::Triangle()
{
}


Triangle::~Triangle()
{
}

void Triangle::SetVerticesPositions(GLfloat positions[9])
{
	for (int i = 0; i < 9; i++){
		int pos = i + ((i % 3) * 3);
		vertices[i] = positions[i];
	}
}

void Triangle::SetVerticesColors(GLfloat colors[9])
{
	for (int i = 0; i < 9; i++) {
		int pos = i + ((i % 3) * 3) + 3;
		vertices[i] = colors[i];
	}
}

void Triangle::SetVerticesPositions(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3)
{
	vertices[0] = x1;
	vertices[1] = y1;
	vertices[2] = z1;

	vertices[6] = x2;
	vertices[7] = y2;
	vertices[8] = z2;

	vertices[12] = x3;
	vertices[13] = y3;
	vertices[14] = z3;
}

void Triangle::SetVerticesColors(GLfloat r1, GLfloat g1, GLfloat b1, GLfloat r2, GLfloat g2, GLfloat b2, GLfloat r3, GLfloat g3, GLfloat b3)
{
	vertices[3] = r1;
	vertices[4] = g1;
	vertices[5] = b1;

	vertices[9] = r2;
	vertices[10] = g2;
	vertices[11] = b2;

	vertices[15] = r3;
	vertices[16] = g3;
	vertices[17] = b3;
}

void Triangle::BindBuffers()
{
	glBindVertexArray( object.getVAO() );

	glBindBuffer( GL_ARRAY_BUFFER, object.getVBO() );
	glBufferData( GL_ARRAY_BUFFER, sizeof( GetVertices() ), vertices, GL_STATIC_DRAW );

	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid * ) 0 ) ;
	glEnableVertexAttribArray( 0 );

	glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)( 3 * sizeof(GLfloat) ) );
	glEnableVertexAttribArray( 1 );

	glBindVertexArray( 0 );
}

void Triangle::Draw()
{
	object.Draw();
}
