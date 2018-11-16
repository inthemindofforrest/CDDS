//main.cpp
#include<iostream>
#include <string>
#include <time.h>

#include "raylib.h"
#include "GameState.h"

int main()
{
	srand(time(NULL));
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "\"Game\"");
	SetTargetFPS(60);



	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		BeginDrawing();
		ClearBackground(BLACK);
		switch (GameState::GetInstance().GetState())
		{
		default:
			break;
		}


		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	CloseWindow();
	return 0;
}
