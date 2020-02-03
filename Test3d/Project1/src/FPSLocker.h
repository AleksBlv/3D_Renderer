#pragma once

class FPSLocker
{
public:
	double fpsDelay;
	double startTime;

	FPSLocker(int fpsCap);
	void fpsStart();
	void fpsWait();
};

