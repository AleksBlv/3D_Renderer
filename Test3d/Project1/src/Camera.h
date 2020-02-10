#pragma once

#include "fromGit/glm/vec3.hpp"
#include "fromGit/glm/ext/matrix_transform.hpp"
#include "Display.h"

class Camera
{
private:
	glm::vec3 Position;
	float pitch;
	float yaw;
	float roll;
	GLFWwindow* window;
	const float SPEED = 0.5f;
public:
	Camera(GLFWwindow* wnd, glm::vec3 pos);
	inline float getPitch() { return pitch; }
	inline float getYaw() { return yaw; }
	inline float getRoll() { return roll; }
	inline glm::vec3 getPosition() { return Position; }
	void move();
};