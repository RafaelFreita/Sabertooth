#include "Camera.h"


Camera::Camera()
{
	// Perspective Values
	fov			= 60.0f;
	aspect		= 60.0f;
	nearPlane	= 0.1f;
	farPlane	= 200.0f;

	// Ortographic Values
	left		= 1.0f;
	right		= 1.0f;
	bottom		= 1.0f;
	top			= 1.0f;
	zNear		= 1.0f;
	zFar		= 1.0f;

}


Camera::~Camera()
{
}

void Camera::Update()
{
	switch ( currentMode )
	{
		case Perspective:
			projection = glm::perspective( fov, aspect, nearPlane, farPlane );
			break;
		case Ortographic:
			projection = glm::ortho( left, right, bottom, top, zNear, zFar );
			break;
	}
}

void Camera::SetMode( CameraMode cameraMode )
{
	currentMode = cameraMode;
}