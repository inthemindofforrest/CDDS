#pragma once
#include "raylib.h"


class PLAYER
{
private:
	Texture2D Texture;
	Texture2D ClosedEyesTexture;
	Texture2D Animation;
	Rectangle Rect;

	int Health;
	int Speed;
	int Rotation;
	float Scale;

	float Animator;
	bool Blink;
public:
	PLAYER();
	PLAYER(Texture2D texture, Rectangle rect, int speed, int Health);
	~PLAYER();

	void Update(float deltaTime);
	void Move(float deltaTime);
	void Draw();

	Rectangle GetRect();
	int GetHealth();

	void UpdateTexture(Texture2D texture, Texture2D ClosedEyes, Texture2D Anim);

	template<typename T>
	void Collison(T * Object, int Size)
	{
		for (int i = 0; i < Size; i++)
		{
			Rectangle Temp = Object[i].GetRect();
			if (CheckCollisionRecs(Temp, Rect))
				Health -= 100;
		}
	}
};