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
}

void PLAYER::Update()
{
	DrawTexture(Texture, (int)Rect.x, (int)Rect.y, PURPLE);

	if (Rect.x != PositionQueue[PositionQueue.size()].x && 
		Rect.y != PositionQueue[PositionQueue.size()].y)
	{
		Rect.x += (PositionQueue[PositionQueue.size()].x - Rect.x) * GetFrameTime();
		Rect.y += (PositionQueue[PositionQueue.size()].y - Rect.y) * GetFrameTime();
	}
	else
		PositionQueue.pop();
	
}

