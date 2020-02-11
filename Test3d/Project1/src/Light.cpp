#include "Light.h"


Light::Light(glm::vec3 pos, glm::vec3 colour)
{
	position = pos;
	color = colour;
}

glm::vec3 Light::getColor()
{
	return color;
}

void Light::setColor(glm::vec3 colour)
{
	color = colour;
}

glm::vec3 Light::getPosition()
{
	return position;
}

void Light::setPosition(glm::vec3 pos)
{
	position = pos;
}
