#include "raylib.h"
#include "tVector.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 640;
	int screenHeight = 640;

	InitWindow(screenWidth, screenHeight, "Inheritance");

	SetTargetFPS(60);


	TVECTOR<int> original;
	original.push_back(4);
	original.push_back(5);
	original.push_back(6);

	TVECTOR<int> copy = original;
	original.pop_back(); // removes from the original array, but not the copy
	original.pop_back();
	original.pop_back();

	//--------------------------------------------------------------------------------------

	//HideCursor();


	// Main game loop
	while (!WindowShouldClose())
	{
		// Draw
		BeginDrawing();
		ClearBackground(BLACK);

		EndDrawing();
	}

	// De-Initialization
	CloseWindow();
	return 0;
}