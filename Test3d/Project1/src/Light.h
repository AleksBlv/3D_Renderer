#pragma once
#include "fromGit/glm/vec3.hpp"

class Light
{
private:
    glm::vec3 color;
    glm::vec3 position;
public:
    Light(glm::vec3 pos, glm::vec3 colour);
    glm::vec3 getColor();
    void setColor(glm::vec3 colour);
    glm::vec3 getPosition();
    void setPosition(glm::vec3 pos);

};

