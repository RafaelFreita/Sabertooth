#ifndef CAMERA_H
#define CAMERA_H

#include <GL\glew.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

enum CameraMode {
	Perspective,
	Ortographic
};

class Camera
{
private:
	glm::mat4 projection;
	CameraMode currentMode;

	// Perspective Configurations
	GLfloat fov;
	GLfloat aspect;
	GLfloat nearPlane;
	GLfloat farPlane;

	// Ortographic Configurations
	GLfloat left;
	GLfloat right;
	GLfloat bottom;
	GLfloat top;
	GLfloat zNear;
	GLfloat zFar;

public:
	Camera();
	~Camera();

	Camera( CameraMode cameraMode ) : Camera() {
		SetMode( cameraMode );
	}

	void Update();

	void SetMode( CameraMode cameraMode );
	
};

#endif