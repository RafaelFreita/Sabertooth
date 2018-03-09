#include "Drawable.h"


Drawable::Drawable()
{
	glGenVertexArrays( 1, &VAO );
	glGenBuffers( 1, &VBO );
}


Drawable::~Drawable()
{
}

void Drawable::BindVertices()
{
	glBindVertexArray( VAO );

	glBindBuffer( GL_ARRAY_BUFFER, VBO );
	glBufferData( GL_ARRAY_BUFFER, sizeof( this->vertices ), this->vertices, GL_STATIC_DRAW );

	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof( GLfloat ), ( GLvoid * ) 0 );
	glEnableVertexAttribArray( 0 );
	glVertexAttribPointer( 1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof( GLfloat ), ( GLvoid * ) ( 3 * sizeof( GLfloat ) ) );
	glEnableVertexAttribArray( 1 );

	glBindVertexArray( 0 );
}

void Drawable::SetVertices( GLfloat * vertices, int verticesQtd )
{
	this->vertices = vertices;
	this->verticesQtd = verticesQtd;

	glBindVertexArray( VAO );

	glBindBuffer( GL_ARRAY_BUFFER, VBO );
	glBufferData( GL_ARRAY_BUFFER, sizeof( this->vertices ), this->vertices, GL_STATIC_DRAW );

	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof( GLfloat ), ( GLvoid * ) 0 );
	glEnableVertexAttribArray( 0 );
	glVertexAttribPointer( 1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof( GLfloat ), ( GLvoid * ) ( 3 * sizeof( GLfloat ) ) );
	glEnableVertexAttribArray( 1 );

	glBindVertexArray( 0 );
}

void Drawable::Draw()
{
	glBindVertexArray( VAO );
	glDrawArrays( GL_TRIANGLES, 0, verticesQtd );
	glBindVertexArray( 0 );
}

void Drawable::Delete()
{
	glDeleteVertexArrays( 1, &VAO );
	glDeleteBuffers( 1, &VBO );
}
