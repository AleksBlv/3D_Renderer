#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


class Display
{
private:
	int WIDTH, HEIGHT;
	int FPS_CAP;
	const char* TITLE;
	GLFWwindow* window;
	double timer;
public:
	Display(int width, int height, const char* title, int fpsLimit);
	void update();
	void close();
	bool isCloseRequested();
	int getWidth() { return WIDTH; }
	int getHeight() { return HEIGHT; }
	GLFWwindow* getWindow() { return window; }
private:
	void createWindow();

};

