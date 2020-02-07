#pragma once

#include "Model.h"
#include"Entity.h"
#include "Matrices.h"
#include <iostream>
#include "Display.h"
#include "ShaderProgram.h"

class Renderer
{
private:
	const float FOV = 70;
	const float NEAR_PLANE = 0.1f;
	const float FAR_PLANE = 1000;
	Display* display;
	glm::mat4x4* projectionMatrix;

	void createProjectionMatrix();
public:
	Renderer(Display* display, ShaderProgram* shader);
	void prepare();
	void render(Entity* entity, ShaderProgram* shader);
};

