#ifndef SHADER_H
#define SHADER_H

#include <GL\glew.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <map>

#include "Texture.h"


class Shader
{
public:
	GLuint program;
	std::map<std::string, Texture> textures;
	GLint textureQtd;

public:
	Shader() { textureQtd = 0; }
	~Shader();

	Shader( const GLchar* vertexPath, const GLchar* fragmentPath ) : Shader() {

		// Get vertex and fragment shaders source codes from files' paths
		std::string vertexCode;
		std::string fragmentCode;
		std::ifstream vertexShaderFile;
		std::ifstream fragmentShaderFile;

		// Ensure ifstream objects can throw exceptions
		vertexShaderFile.exceptions( std::ifstream::badbit );
		fragmentShaderFile.exceptions( std::ifstream::badbit );

		try
		{
			vertexShaderFile.open( vertexPath );
			if ( !vertexShaderFile.is_open() ){
				std::cout << "ERROR::SHADER::VERTEX_SHADER_PATH" << std::endl;
			}

			fragmentShaderFile.open( fragmentPath );
			if ( !fragmentShaderFile.is_open() ){
				std::cout << "ERROR::SHADER::FRAGMENT_SHADER_PATH" << std::endl;
			}

			std::stringstream vShaderStream, fShaderStream;

			// Read files' contents into streams
			vShaderStream << vertexShaderFile.rdbuf();
			fShaderStream << fragmentShaderFile.rdbuf();

			vertexShaderFile.close();
			fragmentShaderFile.close();

			vertexCode = vShaderStream.str();
			fragmentCode = fShaderStream.str();

		}
		catch ( const std::ifstream::failure e )
		{
			std::cout << "ERROR::SHADER::FILE NOT SUCCESUFULLY READ" << std::endl;
		}

		const GLchar *vShaderCode = vertexCode.c_str();
		const GLchar *fShaderCode = fragmentCode.c_str();

		// Compile Shaders

		GLuint vertex, fragment;
		GLint success;
		GLchar infoLog[512];

		// Vertex Shader
		vertex = glCreateShader( GL_VERTEX_SHADER );
		glShaderSource( vertex, 1, &vShaderCode, nullptr );
		glCompileShader( vertex );

		// Print compile errors if any
		glGetShaderiv( vertex, GL_COMPILE_STATUS, &success );
		if ( !success )
		{
			glGetShaderInfoLog( vertex, 512, nullptr, infoLog );
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}


		// Fragment Shader
		fragment = glCreateShader( GL_FRAGMENT_SHADER );
		glShaderSource( fragment, 1, &fShaderCode, nullptr );
		glCompileShader( fragment );
		glGetShaderiv( fragment, GL_COMPILE_STATUS, &success );
		if ( !success )
		{
			glGetShaderInfoLog( fragment, 512, nullptr, infoLog );
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		}


		// Shader Program
		this->program = glCreateProgram();
		glAttachShader( this->program, vertex );
		glAttachShader( this->program, fragment );
		glLinkProgram( this->program );

		// Print Linking errors if there any
		glGetProgramiv( this->program, GL_LINK_STATUS, &success );
		if ( !success )
		{
			glGetProgramInfoLog( this->program, 512, nullptr, infoLog );
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}

		// Delete shaders (already linked, they're no longer necessary)
		glDeleteShader( vertex );
		glDeleteShader( fragment );

	}

	void Use()
	{
		glUseProgram( this->program );
	}

	void Delete() {
		glDeleteProgram( this->program );
	}

	void UseTexture( std::string textureName );
	void LoadTexture( char* path, char* textureUniformName, std::string textureName );

};

#endif