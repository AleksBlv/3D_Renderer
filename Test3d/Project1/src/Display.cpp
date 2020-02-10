#include "Display.h"

Display::Display(int width, int height,const char* title, int fpsLimit)
{
	WIDTH = width;
	HEIGHT = height;
	TITLE = title;
	FPS_CAP = fpsLimit;
	createWindow();
	timer = glfwGetTime();

}

void Display::update()
{

	glfwSwapBuffers(window);
	glfwPollEvents();
}

void Display::close()
{
	glfwTerminate();
}

bool Display::isCloseRequested()
{
	if (glfwWindowShouldClose(window))
	{
		return true;
	}
	else return false;
}

void Display::createWindow()
{

	if (!glfwInit())
	{
		std::cout << "Couldn't init GLFW" << std::endl;
		exit(-1);
	}
	window = glfwCreateWindow(WIDTH, HEIGHT, TITLE, 0, 0);
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Couldn't init glew!" << std::endl;
		exit(-1);
	}
	glfwGetFramebufferSize(window, &WIDTH, &HEIGHT);
	glViewport(0,0,WIDTH, HEIGHT);
	glfwSwapInterval(1);
	
}
