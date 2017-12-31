#include "Drawable.h"



Drawable::Drawable()
{

	glGenVertexArrays( 1, &VAO );
	glGenBuffers( 1, &VBO );

}


Drawable::~Drawable()
{
}

void Drawable::Draw()
{
	glBindVertexArray( 0 );
	glDrawArrays( GL_TRIANGLES, 0, 3);
	glBindVertexArray( 0 );
}

void Drawable::Delete()
{
	glDeleteVertexArrays( 1, &VAO );
	glDeleteBuffers( 1, &VBO );
}
