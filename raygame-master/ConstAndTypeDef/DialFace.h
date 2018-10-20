#pragma once
#include "raylib.h"
#include <math.h>
static float currentAngle;
class DIALFACE
{
public:
	static const Vector2 position;
	static const float radius;
	static float Seconds;
	static float Minutes;
	static float Hours;

	static void DrawFace();
	void Tick();

}typedef clock;