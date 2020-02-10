#include "Camera.h"

Camera::Camera(GLFWwindow* wnd, glm::vec3 pos)
{
	window = wnd;
	Position = pos;
	yaw = 0;	//rotate by Y
	roll = 0;	//rotate by Z
	pitch = 0; //by X
}

void Camera::move()
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		float cs = cos(glm::radians(yaw-90));
		float sn = sin(glm::radians(yaw-90));
		Position.z += SPEED * sn;
		Position.x += SPEED * cs;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		float cs = cos(glm::radians(yaw + 90));
		float sn = sin(glm::radians(yaw + 90));
		Position.z += SPEED * sn;
		Position.x += SPEED * cs;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		float cs = cos(glm::radians(yaw));
		float sn = sin(glm::radians(yaw));
		Position.z += SPEED * sn;
		Position.x += SPEED * cs;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		float cs = cos(glm::radians(yaw));
		float sn = sin(glm::radians(yaw));
		Position.z -= SPEED * sn;
		Position.x -= SPEED * cs;
	}
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		pitch -= SPEED * 2;
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		pitch += SPEED * 2;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		yaw -= SPEED * 2;
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		yaw += SPEED * 2;
	}
	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
	{
		Position.y += SPEED;
	}
	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
	{
		Position.y -= SPEED;
	}
}
