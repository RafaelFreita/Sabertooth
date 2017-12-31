#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "Shader.h"
#include "Drawable.h"
#include "Triangle.h"

const GLint WIDTH = 800, HEIGHT = 600;

int main() {

#pragma region OpenGL Init
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_SAMPLES, 4);
#pragma endregion

#pragma region Basic Setup
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Sabertooth", nullptr, nullptr);

	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	if (window == nullptr) {
		std::cout << "Failed to create GLFW Window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) {
		std::cout << "Failed no init GLEW." << std::endl;
		return EXIT_FAILURE;
	}

	glViewport(0, 0, screenWidth, screenHeight);
#pragma endregion

	Shader coreShader("Shaders/Core/core.vert", "Shaders/Core/core.frag");

	GLfloat vertices[] = {
		// Positions		    // Colors
		+0.5f, -0.5f, +0.0f,	0.8f, 0.3f, 0.1f,
		-0.5f, -0.5f, +0.0f,	0.8f, 0.3f, 0.1f,
		+0.0f, +0.5f, +0.0f,	0.8f, 0.3f, 0.1f
	};

	GLuint VAO, VBO;

	glGenVertexArrays( 1, &VAO );
	glGenBuffers( 1, &VBO );

	glBindVertexArray( VAO );

	glBindBuffer( GL_ARRAY_BUFFER, VBO);
	glBufferData( GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW );

	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * ) 0 );
	glEnableVertexAttribArray( 0 );

	glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid *) ( 3 * sizeof( GLfloat ) ) );
	glEnableVertexAttribArray( 1 );

	glBindVertexArray( 0 );

	while (!glfwWindowShouldClose(window)) {
		
		glfwPollEvents();

#pragma region Input Handling

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, GLFW_TRUE);
		}

#pragma endregion

		glClearColor(0.4f, 0.8f, 0.65f, 1.0f);
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
		


		coreShader.Use();
		glBindVertexArray( VAO );
		glDrawArrays( GL_TRIANGLES, 0, 3 );
		glBindVertexArray( 0 );



		glfwSwapBuffers(window);
	}

	glfwTerminate();

	return EXIT_SUCCESS;
}