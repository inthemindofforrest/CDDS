#include "Player.h"
#include <iostream>

PLAYER::PLAYER()
{

}
PLAYER::~PLAYER()
{

}

PLAYER::PLAYER(Texture2D texture, Rectangle rect, int speed, int health)
{
	Rect = rect;
	Texture = texture;
	Health = health;
	Speed = speed;
	Animator = 0;
	Rotation = 0;
	Scale = 3;
	Blink = true;
}

void PLAYER::Update(float deltaTime)
{
	Draw();
	Move(deltaTime);
}

void PLAYER::Move(float deltaTime)
{
	//Player Pressed Controls
	{
		if (IsKeyDown(KEY_W))
			Rect.y += -Speed * deltaTime;
		if (IsKeyDown(KEY_S))
			Rect.y += Speed * deltaTime;
		if (IsKeyDown(KEY_A))
			Rect.x += -Speed * deltaTime;
		if (IsKeyDown(KEY_D))
			Rect.x += Speed * deltaTime;
	}
	//Player Restrictions
	{
		if (Rect.x < 0)
			Rect.x = 0;
		if (Rect.x + Rect.width > GetScreenWidth())
			Rect.x = GetScreenWidth() - Rect.width;
		if (Rect.y < 0)
			Rect.y = 0;
		if (Rect.y + Rect.height > GetScreenHeight())
			Rect.y = GetScreenHeight() - Rect.height;
	}

}

void PLAYER::Draw()
{
	if(Blink)
		DrawTextureEx(ClosedEyesTexture, { Rect.x, Rect.y }, (float)Rotation, Scale, WHITE);
	else
		DrawTextureEx(Animation, { Rect.x, Rect.y }, (float)Rotation, Scale, WHITE);
	if (((int)Animator) > 1)
	{
		Blink = false;
		if (((int)Animator) % 3 <= .25f)
			DrawTextureEx(Animation, { Rect.x, Rect.y }, (float)Rotation, Scale, WHITE);
		else
			DrawTextureEx(Texture, { Rect.x, Rect.y }, (float)Rotation, Scale, WHITE);

	}
	if (((int)Animator) % 10 == 0)
	{
		DrawTextureEx(ClosedEyesTexture, { Rect.x, Rect.y }, (float)Rotation, Scale, WHITE);
		Animator = 1.75f;
		Blink = true;
	}
	Animator += GetFrameTime();
}

Rectangle PLAYER::GetRect()
{
	return Rect;
}

int PLAYER::GetHealth()
{
	return Health;
}

void PLAYER::UpdateTexture(Texture2D texture, Texture2D ClosedEyes, Texture2D Anim)
{
	Texture = texture;
	ClosedEyesTexture = ClosedEyes;
	Animation = Anim;
}