#pragma once
#include "raylib.h"
#include "Queue.h"

class PLAYER
{
	Texture2D Texture;
	Rectangle Rect;
	tQueue<Vector2> PositionQueue;

public:

	PLAYER();
	PLAYER(Texture2D texture, Rectangle rect);

	void AddToQueue(Vector2 posistion);
	void Update();

};