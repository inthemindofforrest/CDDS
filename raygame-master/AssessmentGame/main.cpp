//main.cpp
#include<iostream>
#include <string>
#include <time.h>

#include "raylib.h"

int main()
{
	srand(time(NULL));
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	SetTargetFPS(60);



	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		BeginDrawing();
		ClearBackground(BLACK);



		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	CloseWindow();
	return 0;
}
