#include "Templates.h"
#include "GameObject.h"
#include "Ninja.h"


int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 640;
	int screenHeight = 640;

	InitWindow(screenWidth, screenHeight, "Inheritance");

	SetTargetFPS(60);
	//-------------------------------------------------------------------------------------
	NINJA newNinja("WizardSprite.png", { 0,0 }, 20, true);
	gameObject<NINJA> myNinja(&newNinja);



	//--------------------------------------------------------------------------------------

	//HideCursor();
	

	// Main game loop
	while (!WindowShouldClose())
	{

		// Draw
		BeginDrawing();
		ClearBackground(BLACK);
		myNinja.Update(GetFrameTime());

		EndDrawing();
	}

	// De-Initialization
	CloseWindow();
	return 0;
}