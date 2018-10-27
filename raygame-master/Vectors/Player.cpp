#include "Player.h"
#include<iostream>

void PLAYER::AddToQueue(Vector2 posistion)
{
	PositionQueue.push(posistion);
}

PLAYER::PLAYER() {}

PLAYER::PLAYER(Texture2D texture, Rectangle rect)
{
	Texture = texture;
	Rect = rect;
	Reverse = false;
}

void PLAYER::Update()
{
	int Limit = 5;
	
	if (PositionQueue.size() > 0)
	{
		for(size_t i = 0; i < PositionQueue.size() - 1; i++)
			DrawTexture(Texture, PositionQueue[i].x, PositionQueue[i].y, RED);
		DrawTexture(Texture, PositionQueue[PositionQueue.size() - 1].x, 
			PositionQueue[PositionQueue.size() - 1].y, GREEN);
	}
	/*if (PrevPositionStack.size() > 0)
		{
			for (size_t i = 0; i < PrevPositionStack.size(); i++)
				DrawTexture(Texture, PrevPositionStack[i].x, PrevPositionStack[i].y, DARKGRAY);
			if (Reverse)
				DrawTexture(Texture, PrevPositionStack[PrevPositionStack.size() - 1].x,
					PrevPositionStack[PrevPositionStack.size() - 1].y, GREEN);
		}*/
	if (PositionQueue.size() > 0 && !Reverse)
	{
		if (Rect.x - PositionQueue[PositionQueue.size() - 1].x >= Limit ||
			Rect.x - PositionQueue[PositionQueue.size() - 1].x <= -Limit)
		{
			Rect.x += (PositionQueue[PositionQueue.size() - 1].x - Rect.x) * GetFrameTime();

		}
		if (Rect.y - PositionQueue[PositionQueue.size() - 1].y >= Limit ||
			Rect.y - PositionQueue[PositionQueue.size() - 1].y <= -Limit)
		{
			Rect.y += (PositionQueue[PositionQueue.size() - 1].y - Rect.y) * GetFrameTime();
		}
		if (Rect.y - PositionQueue[PositionQueue.size() - 1].y <= Limit &&
			Rect.y - PositionQueue[PositionQueue.size() - 1].y >= -Limit &&
			Rect.x - PositionQueue[PositionQueue.size() - 1].x <= Limit &&
			Rect.x - PositionQueue[PositionQueue.size() - 1].x >= -Limit)
		{
			PrevPositionStack.push(PositionQueue[PositionQueue.size() - 1]);
			PositionQueue.pop();
		}
	}
	/*else if(Reverse)
	{
		if (Rect.x - PrevPositionStack[PrevPositionStack.size() - 1].x >= Limit ||
			Rect.x - PrevPositionStack[PrevPositionStack.size() - 1].x <= -Limit)
		{
			Rect.x += (PrevPositionStack[PrevPositionStack.size() - 1].x - Rect.x) * GetFrameTime();

		}
		if (Rect.y - PrevPositionStack[PrevPositionStack.size() - 1].y >= Limit ||
			Rect.y - PrevPositionStack[PrevPositionStack.size() - 1].y <= -Limit)
		{
			Rect.y += (PrevPositionStack[PrevPositionStack.size() - 1].y - Rect.y) * GetFrameTime();
		}
		if (Rect.y - PrevPositionStack[PrevPositionStack.size() - 1].y <= Limit &&
			Rect.y - PrevPositionStack[PrevPositionStack.size() - 1].y >= -Limit &&
			Rect.x - PrevPositionStack[PrevPositionStack.size() - 1].x <= Limit &&
			Rect.x - PrevPositionStack[PrevPositionStack.size() - 1].x >= -Limit)
		{
			PrevPositionStack.pop();
			Reverse = false;
		}
	}*/
	/*if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_Z) && 
		PrevPositionStack.size() > 0 && !Reverse)
	{
		PrevPositionStack.pop();
		Reverse = true;
	}*/


	DrawTexture(Texture, (int)Rect.x, (int)Rect.y, PURPLE);

}

void PLAYER::SelectEnemy(Vector2 EnemyPosition)
{
	for (size_t i = 0; i != PositionQueue.size();)
		PositionQueue.pop();
	PositionQueue.push(EnemyPosition);
}