#include "Entity.h"

Entity::Entity(Model* model, glm::vec3 position, float rotX, float rotY, float rotZ, float scale) 
	: model(model), position(position), rotX(rotX), rotY(rotY), rotZ(rotZ), scale(scale)
{
}

void Entity::move(float dX, float dY, float dZ)
{
	position.x += dX;
	position.y += dY;
	position.z += dZ;
}

void Entity::rotate(float rX, float rY, float rZ)
{
	rotX += rX;
	rotY += rY;
	rotZ += rZ;
}

Model* Entity::getModel()
{
	return model;
}
