#pragma once

namespace Tools
{
	struct Vec2f
	{
		float x;
		float y;
		Vec2f()
		{
			x = 0.0f;
			y = 0.0f;
		}
		Vec2f(float X, float Y)
		{
			x = X;
			y = Y;
		}
	};

	struct Vec3f
	{
		float x;
		float y;
		float z;
		Vec3f()
		{
			x = 0.0f;
			y = 0.0f;
			z= 0.0f;
		}
		Vec3f(float X, float Y, float Z)
		{
			x = X;
			y = Y;
			z = Z;
		}
	};

	struct mat4x4
	{
		float m[4][4] = { 0.0f };
	};

}