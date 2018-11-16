//main.cpp
#include<iostream>
#include <string>
#include <time.h>
#include <vector>

#include "IBox.h"
#include "IFactory.h"
#include "Factory.h"
#include "FallingFactory.h"
#include "SimpleSprite.h"
#include "ObjectPooling.h"

SimpleSprite* FallingFactory::spriteMasters;
size_t FallingFactory::spriteCount;

int main()
{
	srand(time(NULL));
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	SetTargetFPS(60);

	FallingFactory::init();
	//std::vector<SimpleSprite> Objects;
	tObjectPool<SimpleSprite> Object(100);

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		BeginDrawing();
		ClearBackground(BLACK);

		if (IsKeyPressed(KEY_SPACE))//Instantiate new rock
		{
			{
			//SimpleSprite * Temp = new SimpleSprite[SizeOfRocks += 1];
			//if (SizeOfRocks > 1)
			//{
			//	for (int i = 0; i < SizeOfRocks - 1; i++)
			//	{
			//		Temp[i] = Object[i];
			//	}
			//}
			//Temp[SizeOfRocks - 1] = *FallingFactory::getFromType("rock")->Clone();
			////Temp[SizeOfRocks - 1] = *FallingFactory::getRandom()->Clone();

			//delete[] Object;
			//Object = Temp;
			//std::cout << Object[SizeOfRocks - 1].pos.x << ", " << Object[SizeOfRocks - 1].pos.y << std::endl;
		}
			//Objects.push_back(*FallingFactory::getRandom()->Clone());
			Object.recycle(FallingFactory::getRandom()->Clone());
		}

		//RockUpdate
		{
			for (int i = 0; i < Object.capacity(); i++)
			{
				if (Object.retrieve(i) != nullptr)
				{
					Object.retrieve(i)->draw();
					Object.retrieve(i)->translate({ -1,0 });

					if (Object.retrieve(i)->pos.x < 0)
						Object.DeactivateIndex(i);
				}
			}
		}

		EndDrawing();
		//----------------------------------------------------------------------------------
	}
	
	CloseWindow();
	return 0;
}
