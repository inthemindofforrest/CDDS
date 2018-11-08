#include "raylib.h"
#include <iostream>


int main()
{
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
////main.cpp
//#include<iostream>
//#include <string>
//#include <time.h>
//
//#include "IBox.h"
//#include "IFactory.h"
//#include "Factory.h"
//
//int main() {
//	srand(time(NULL));
//	IBox* p = NULL;
//	p = Factory::GetInstance().Create("Red");
//	std::cout << "\nColor is: " << p->Color() << "\n";
//	delete p;
//	p = Factory::GetInstance().Create("Blue");
//	std::cout << "\nColor is: " << p->Color() << "\n";
//	delete p;
//	return 0;
//}
