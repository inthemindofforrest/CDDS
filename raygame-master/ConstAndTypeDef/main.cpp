#include "raylib.h"
#include "DialFace.h"


	Vector2 const DIALFACE::position = { 320, 320 };
	float const DIALFACE::radius = 25;
	float DIALFACE::Seconds = 0;
	float DIALFACE::Minutes = 0;
	float DIALFACE::Hours = 0;

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 640;
	int screenHeight = 640;

	InitWindow(screenWidth, screenHeight, "Inheritance");

	SetTargetFPS(60);

	

	clock MainClock;
	//--------------------------------------------------------------------------------------

	//HideCursor();


	// Main game loop
	while (!WindowShouldClose())
	{
		// Draw
		BeginDrawing();
		ClearBackground(BLACK);
		MainClock.Tick();
		
		EndDrawing();
	}

	// De-Initialization
	CloseWindow();
	return 0;
}