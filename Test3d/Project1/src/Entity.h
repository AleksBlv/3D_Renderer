#pragma once
#include "Model.h"
#include "ShaderProgram.h"
class Entity
{
private: 
	Model* model;
	glm::vec3 position;
	float rotX, rotY, rotZ;
	float scale;

public:
	Entity(Model* model, glm::vec3 position, float rotX, float rotY, float rotZ, float scale);
	void move(float dX, float dY, float dZ);
	void rotate(float rX, float rY, float rZ);
	Model* getModel();
	glm::vec3 getPosition() { return this->position; };
	void setPosition(glm::vec3 position) { this->position = position; }
	float getRotX() { return rotX; }
	void setRotX(float rotX) { this->rotX = rotX; }
	float getRotY() { return rotY; }
	void setRotY(float rotY) { this->rotY = rotY; }
	float getRotZ() { return rotZ; }
	void setRotZ(float rotZ) { this->rotZ = rotZ; }
	float getScale() { return scale; }
	void setScale(float scale) { this->scale = scale; }


};

