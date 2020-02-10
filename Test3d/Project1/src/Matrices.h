#pragma once
#include "Camera.h"

#include "fromGit/glm/mat4x4.hpp"
#include "fromGit/glm/vec3.hpp"
#include "fromGit/glm/ext/matrix_transform.hpp"
#include <fromGit/glm/gtc/type_ptr.hpp>

glm::mat4x4* createTransformationMatrix(glm::vec3 translation, float rx, float ry, float rz, float scale);
glm::mat4x4* createViewMatrix(Camera* camera);