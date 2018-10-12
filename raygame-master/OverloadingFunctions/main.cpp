#include "MyHero.h"
#include "Color.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	HideCursor();
	//MYHERO * Hero = new MYHERO("Bob", "He is cool.", 45, 1, 5, 100);
	//POTION * HealthPotion = new POTION("Health", 1, 100, 10);
	MyColor * Red = new MyColor(255, 0, 0, 255);
	MyColor * Green = new MyColor(0, 255, 0, 255);

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		*Red += *Green;

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(BLACK);
		//(*Hero).Update();

		//if (IsKeyPressed(KEY_SPACE))
			//*Hero += *HealthPotion;

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	//delete Hero;
	//delete HealthPotion;
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}