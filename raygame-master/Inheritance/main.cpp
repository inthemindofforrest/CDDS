#include "Sprite.h"
#include "ButtonMaker.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 640;
	int screenHeight = 640;

	InitWindow(screenWidth, screenHeight, "Inheritance");

	SetTargetFPS(60);

	std::string SpriteFiles[]
	{
		"player_walk1.png",
		"player_walk2.png"
	};
	std::string ButtonFiles[]
	{
		"blue_sliderD.png",
		"blue_sliderL.png",
		"blue_sliderR.png",
		"blue_sliderU.png"
	};
	SPRITE Player(SpriteFiles, sizeof(SpriteFiles) / sizeof(SpriteFiles[0]), 2.5f);
	BUTTON UpButton(ButtonFiles, { 375, 0 }, 1);
	//--------------------------------------------------------------------------------------

	//HideCursor();

	// Main game loop
	while (!WindowShouldClose())
	{

		// Draw
		BeginDrawing();
		ClearBackground(BLACK);
		Player.Update((time_t)GetFrameTime());
		if (UpButton.CheckForClick())
		{

		}

		EndDrawing();
	}

	// De-Initialization
	CloseWindow();
	return 0;
}