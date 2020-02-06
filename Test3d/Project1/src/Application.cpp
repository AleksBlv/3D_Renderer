//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
#include <iostream>

#include"Display.h"
#include "Model.h"
#include "Loader.h"
#include "Renderer.h"
#include <vector>
#include "ShaderProgram.h"
#include "FPSLocker.h"

const int WIDTH = 1280;
const int HEIGHT = 720;
const int FPS_CAP = 60;
const char* TITLE = "3D Engine";

int main(void)
{ 
    Display display(WIDTH, HEIGHT, TITLE, FPS_CAP);

    float verteces[]{
     0.5f,  0.5f, 0.0f,  // Верхний правый угол
     0.5f, -0.5f, 0.0f,  // Нижний правый угол
    -0.5f, -0.5f, 0.0f,  // Нижний левый угол
    -0.5f,  0.5f, 0.0f   // Верхний левый угол
    };

    int indices[]{
        0, 1, 3,
        1, 2, 3
    };

    float textures_arr[]{
        1.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 0.0f,
        0.0f, 1.0f
    };

    std::vector<float> v;
    for (int i = 0; i < (sizeof(verteces) / sizeof(float)); i++)
    {
        v.push_back(verteces[i]);
    }

    std::vector<int> ind;

    for (int i = 0; i < (sizeof(indices) / sizeof(int)); i++)
    {
        ind.push_back(indices[i]);
    }

    std::vector<float> tex;
    for (int i = 0; i < sizeof(textures_arr) / sizeof(float); i++)
    {
        tex.push_back(textures_arr[i]);
    }

    Loader loader;
    Renderer renderer;
    loader.loadObj("res/models/stall.obj");
    Model* model;
    model = loader.loadToVAO(v, ind, tex);
    Texture texture("res/textures/cat.png");
    model->setTexture(&texture);

    ShaderProgram shader;
    shader.loadShaders("Shaders/fragmentShader.txt", 
        "Shaders/vertexShader.txt");

    loader.loadObj("res/models/stall.obj");
    

    FPSLocker lockFPS(60);
    /* Loop until the user closes the window */
    while (!display.isCloseRequested())
    {
        lockFPS.fpsStart();
        shader.Use();
        glm::mat4x4 m_rot(1.0f);
        m_rot = glm::translate(m_rot, glm::vec3(0.0f, 0.0f, 0.0f));
        m_rot = glm::rotate(m_rot, (GLfloat)glfwGetTime() * 1.0f, glm::vec3(0.0, 0.0, 1.0));
        m_rot = glm::scale(m_rot, glm::vec3(0.5f, 0.5f, 1.0f));
        int location = glGetUniformLocation(shader.getProgID(), "rotation_matrix");
        shader.loadMat4x4(location, m_rot);
       
        renderer.prepare();
        renderer.render(model);
        display.update();
        shader.Stop();
        lockFPS.fpsWait();
    }
    display.close();

    //glfwTerminate();
    return 0;
}