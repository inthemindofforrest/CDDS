#pragma once
#include "raylib.h"
#include<random>

class DEATHOBJECT
{
private:
	Texture2D Texture;
	Rectangle Rect;

	int Health;
	int Speed;
	int Rotation;
	float Scale;

	bool Active;
public:
	DEATHOBJECT();
	DEATHOBJECT(Texture2D texture, Rectangle rect, int Speed, int Rotation, float Scale);
	~DEATHOBJECT();

	void Update(float deltaTime);
	void MoveObject(float deltaTime);
	void Draw();

	Rectangle GetRect();
	bool& IsActive();

	template<typename T>
	void Collison(T Object)
	{
		Rectangle Temp = Object.GetRect();
		if (CheckCollisionRecs(Temp, Rect))
				Active = false;
	}
};