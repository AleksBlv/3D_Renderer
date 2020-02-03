#include "FPSLocker.h"
#include <GLFW/glfw3.h>

FPSLocker::FPSLocker(int fpsCap)
{
	fpsDelay = (1000.0f / fpsCap) / 1000.0f;
}

void FPSLocker::fpsStart()
{
	startTime = glfwGetTime();
}

void FPSLocker::fpsWait()
{
	while ((glfwGetTime() - startTime) < fpsDelay)
		continue;
}
