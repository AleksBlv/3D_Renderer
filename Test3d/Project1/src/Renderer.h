#pragma once

#include "Model.h"
#include <iostream>

class Renderer
{
public:

	void prepare();
	void render(Model* model);
};

