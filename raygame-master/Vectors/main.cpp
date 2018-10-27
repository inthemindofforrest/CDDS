#include "raylib.h"
#include "tVector.h"
#include "tStack.h"
#include "Queue.h"
#include "SpellCaster.h"
#include "Player.h"
#include "Enemy.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 640;
	int screenHeight = 640;

	InitWindow(screenWidth, screenHeight, "Inheritance");

	SetTargetFPS(60);

	//TVECTOR<IMAGE> Images;
	Texture2D texture = LoadTexture("ImageTexture.png");

	tQueue<SPELLS> Spells;
	tStack<SPELLS> Second;
	ENEMY * Enemy = new ENEMY(texture, { 100,100,(float)texture.width,(float)texture.height });

	PLAYER * Player = new PLAYER(texture, {0,0,(float)texture.width, (float)texture.height});

	//--------------------------------------------------------------------------------------

	//HideCursor();


	// Main game loop
	while (!WindowShouldClose())
	{
		// Draw
		BeginDrawing();
		ClearBackground(BLACK);
		
		if (IsKeyPressed(KEY_Q))
		{
			SPELLS * NewSpell = new SPELLS(texture,_Water);
			Spells.push(*NewSpell);
		}
		if (IsKeyPressed(KEY_W))
		{
			SPELLS * NewSpell = new SPELLS(texture, _Fire);
			Spells.push(*NewSpell);
		}
		if (IsKeyPressed(KEY_E))
		{
			SPELLS * NewSpell = new SPELLS(texture, _Earth);
			Spells.push(*NewSpell);
		}
		if (IsKeyPressed(KEY_R))
		{
			SPELLS * NewSpell = new SPELLS(texture, _Lightning);
			Spells.push(*NewSpell);
		}

		if (IsKeyPressed(KEY_T))
		{
			SPELLS * NewSpell = new SPELLS(texture, _Water);
			Second.push(*NewSpell);
		}
		if (IsKeyPressed(KEY_Y))
		{
			SPELLS * NewSpell = new SPELLS(texture, _Fire);
			Second.push(*NewSpell);
		}
		if (IsKeyPressed(KEY_U))
		{
			SPELLS * NewSpell = new SPELLS(texture, _Earth);
			Second.push(*NewSpell);
		}
		if (IsKeyPressed(KEY_I))
		{
			SPELLS * NewSpell = new SPELLS(texture, _Lightning);
			Second.push(*NewSpell);
		}

		if (IsKeyPressed(KEY_SPACE))
		{
			Spells.pop();
		}
		if (IsKeyPressed(KEY_BACKSPACE))
		{
			Second.pop();
		}

		for (size_t i = 0; i < Spells.size(); i++)
		{
			Spells[i].Update({ i * (float)texture.width,(float)texture.height });
		}
		for (size_t i = 0; i < Second.size(); i++)
		{
			Second[i].Update({ i * (float)texture.width,0 });
		}

		if (IsMouseButtonPressed(0))
		{
			if(!(*Enemy).IsClicked())
				(*Player).AddToQueue({ (float)GetMouseX(), (float)GetMouseY() });
			else
			{
				(*Player).SelectEnemy((*Enemy).GetPosition());
			}
			
		}

		(*Player).Update();
		(*Enemy).Update();

		EndDrawing();
	}

	// De-Initialization

	CloseWindow();
	return 0;
}