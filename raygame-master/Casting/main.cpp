#include "functions.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 640;
	int screenHeight = 640;

	InitWindow(screenWidth, screenHeight, "WizBarCorps");

	SetTargetFPS(60);
	
	WIZARD Wizard[10];
	BARBARIAN Barbarian;
	CORPS Corps[1];
	//--------------------------------------------------------------------------------------

	//HideCursor();

	// Main game loop
	while (!WindowShouldClose())
	{

		// Draw
		BeginDrawing();
		ClearBackground(BLACK);
		DeathUpdate(Wizard, (sizeof(Wizard) / sizeof(WIZARD)), Corps,
			sizeof(Corps) / sizeof(CORPS));

		EndDrawing();
	}

	// De-Initialization
	CloseWindow();        
	return 0;
}