#include "DialFace.h"

void DIALFACE::DrawFace()
{
	DrawCircleLines(position.x, position.y, (int)radius * 2, WHITE);
	DrawLineEx({ position.x, position.y},
		{ (float)(position.x + 180 / PI * (cos((Seconds * 6) * (radius / 65)))),
		(float)(position.y + 180 / PI * (sin((Seconds * 6) * (radius / 65)))) }, 2, RED);
}
void DIALFACE::Tick()
{
	DrawFace();

	Seconds += GetFrameTime();
}