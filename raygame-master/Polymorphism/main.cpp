#include "Player.h"
#include "Barbarian.h"
#include "Wizard.h"

#include "Enemy.h"
#include "Necromancer.h"

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
	int TotalEnemies = 10;

	PLAYER * Player = new BARBARIAN("BarbarianSprite.png", { 100, 100 }, 2);;
	WIZARDBUTTON WizButton({ 0,0,100,100 }, "LeftButton.png");
	BARBARIANBUTTON BarButton({ 200,0,100,100 }, "RightButton.png");

	std::vector <ENEMY*> Enemy;

	//--------------------------------------------------------------------------------------

	//HideCursor();
	
	
	for (int i = 0; i < TotalEnemies; i++)
	{
		Enemy.push_back(new NECROMANCER("NecromancerSprite.png", { 0,0 }, 12, Player));
	}
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


		//---------------Spawn---Enemies-------------------------------------

 		if(IsKeyPressed(KEY_SPACE))
			for (auto EnemyInt = Enemy.begin(); EnemyInt < Enemy.end(); EnemyInt++)
			{
				if ((*EnemyInt)->IsAlive == false)
				{
					(*EnemyInt)->IsAlive = true;
					break;
				}
				if (EnemyInt == Enemy.end() - 1)
				{
					Enemy.push_back(new NECROMANCER("NecromancerSprite.png", { 0,0 }, 12, Player));
   				}
			}

		
		for (auto EnemyInt = Enemy.begin(); EnemyInt != Enemy.end(); EnemyInt++)
		{
			if ((*EnemyInt)->IsAlive == true)
			{
				(*EnemyInt)->Update();
			}
		}

		EndDrawing();
	}

	// De-Initialization
	delete Player;
	CloseWindow();
	return 0;
}