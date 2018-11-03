#include "raylib.h"
#include "Gamestate.h"
#include "Player.h"
#include "DeathObject.h"
#include <iostream>

int PlayerSelection();



int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);
	Texture2D PlayerTexture = LoadTexture("PlayerTexture.png");


	PLAYER Player(PlayerTexture, {100,100, 
		(float)PlayerTexture.width, (float)PlayerTexture.height}, 50, 100);
	DEATHOBJECT * Enemy = new DEATHOBJECT(PlayerTexture, { 500,100,
		(float)PlayerTexture.width, (float)PlayerTexture.height }, 100, 0, 2);

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		BeginDrawing();

		switch (GameState::GetInstance().getState())
		{
		case MainMenu:
		{
			ClearBackground(BLACK);
			DrawText("Press Space", (GetScreenWidth() / 2) - 200, (GetScreenHeight() / 2) - 10, 64, WHITE);
			if (IsKeyPressed(KEY_SPACE))
				GameState::GetInstance().setState(PlayerChoice);
		}
			break;
		case PlayerChoice:
		{
			ClearBackground(RAYWHITE);
			if (PlayerSelection() == 1)
			{
				Player.UpdateTexture(LoadTexture("Player1Texture.png"), LoadTexture("Player1ClosedEyes.png"), LoadTexture("Player1-2Texture.png"));
				GameState::GetInstance().setState(Gameplay);
			}
			else if (PlayerSelection() == 2)
			{
				Player.UpdateTexture(LoadTexture("Player2Texture.png"), LoadTexture("Player2ClosedEyes.png"), LoadTexture("Player2-2Texture.png"));
				GameState::GetInstance().setState(Gameplay);
			}
		}
			break;
		case Gameplay:
		{
			ClearBackground(DARKBLUE);
			Player.Update(GetFrameTime());
			Enemy->Update(GetFrameTime());

			Player.Collison<DEATHOBJECT>(Enemy, 1);
			Enemy->Collison<PLAYER>(Player);


			if (Player.GetHealth() <= 0)
				GameState::GetInstance().setState(GameOver);
		}
			break;
		case GameOver:
		{
			ClearBackground(RED);
		}
			break;
		default:
			break;
		}

		

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	CloseWindow();
	return 0;
}

int PlayerSelection()
{
	Rectangle GreenSelect = { (GetScreenWidth() / 10) * 1, (GetScreenHeight() / 10) * 2,(GetScreenWidth() / 10) * 3, (GetScreenHeight() / 10) * 6 };
	Rectangle RedSelect = { (GetScreenWidth() / 10) * 6, (GetScreenHeight() / 10) * 2,(GetScreenWidth() / 10) * 3, (GetScreenHeight() / 10) * 6 };

	static Texture2D Player1ClosedEyes = LoadTexture("Player1ClosedEyes.png");
	static Texture2D Player2ClosedEyes = LoadTexture("Player2ClosedEyes.png");

	static Texture2D Player1OpenedEyes = LoadTexture("Player1Texture.png");
	static Texture2D Player2OpenedEyes = LoadTexture("Player2Texture.png");


	DrawRectangleRec(GreenSelect, GREEN);
	DrawRectangleRec(RedSelect, RED);
	DrawText("Choose Player:", (GetScreenWidth() / 2) - 130, (GetScreenHeight() / 20) * 2, 36, BLACK);

	if (CheckCollisionPointRec(GetMousePosition(), GreenSelect))
	{
		DrawTextureEx(Player1OpenedEyes, { GreenSelect.x, (float)(GetScreenHeight() / 10) * 2.3f }, 0, 12, WHITE);
		if(IsMouseButtonPressed(0))
			return 1;
	}
	else
		DrawTextureEx(Player1ClosedEyes, { GreenSelect.x, (float)(GetScreenHeight() / 10) * 2.3f }, 0, 12, WHITE);
	if (CheckCollisionPointRec(GetMousePosition(), RedSelect))
	{
		DrawTextureEx(Player2OpenedEyes, { RedSelect.x, (float)(GetScreenHeight() / 10) * 2.3f }, 0, 12, WHITE);
		if (IsMouseButtonPressed(0))
			return 2;
	}
	else
		DrawTextureEx(Player2ClosedEyes, { RedSelect.x, (float)(GetScreenHeight() / 10) * 2.3f }, 0, 12, WHITE);
	return 0;
}