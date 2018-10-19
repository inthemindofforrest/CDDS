#include "Player.h"
#include "Barbarian.h"
#include "Wizard.h"
#include "WizardButton.h"
#include "BarbarianButton.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 640;
	int screenHeight = 640;

	InitWindow(screenWidth, screenHeight, "Inheritance");

	SetTargetFPS(60);
	Rectangle rect = { 0,0,0,0 };

	PLAYER * Player = NULL;
	WIZARDBUTTON WizButton({ 0,0,100,100 }, "LeftButton.png");
	BARBARIANBUTTON BarButton({ 200,0,100,100 }, "RightButton.png");

	//--------------------------------------------------------------------------------------

	//HideCursor();

	// Main game loop
	while (!WindowShouldClose())
	{

		// Draw
		BeginDrawing();
		ClearBackground(BLACK);
		
		WizButton.Update(&Player);
		BarButton.Update(&Player);
		if(Player != NULL)
			(*Player).Update();
		EndDrawing();
	}

	// De-Initialization
	delete Player;
	CloseWindow();
	return 0;
}