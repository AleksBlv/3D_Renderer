#pragma once

#include "Model.h"
#include"Entity.h"
#include "Matrices.h"
#include <iostream>

class Renderer
{
public:

	void prepare();
	void render(Entity* entity, ShaderProgram* shader);
};

