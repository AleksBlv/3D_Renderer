#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "fromGit/glm/mat4x4.hpp"
#include "fromGit/glm/vec3.hpp"
#include "fromGit/glm/ext/matrix_transform.hpp"
#include <fromGit/glm/gtc/type_ptr.hpp>
#include "Camera.h"
#include "Light.h"


class ShaderProgram
{
private:
	GLuint progID;
	int location_TransformationMatrix;
	int location_ProjectionMatrix;
	int location_ViewMatrix;
	int location_LightPosition;
	int location_LightColor;
public:
	ShaderProgram();
	void loadShaders(const GLchar* vPath, const GLchar* fPath);
	GLuint getProgID();
	void Use();
	void Stop();
private:
	GLuint loadAndAttachShader(const GLchar* Path, int type);
	GLuint getUniformLocation(const GLchar* uniformName);
	void bindAttributes();
	void bindAttribute(int attrib,const GLchar* attribName);
	void getAllUniformLocations();
public:
	void loadVec4(int location, float x, float y, float z, float alpha);
	void loadVec3f(int location, glm::vec3 vec);
	void load1f(int location, float x);
	void loadMat4x4(int location, const GLfloat* matrix);
	void loadTransformationMatrix(const GLfloat* transforMatrix);
	void loadProjectionMatrix(const GLfloat* projectionMatrix);
	void loadViewMatrix(Camera* camera);
	void loadLight(Light* light);
};

