#include "DeathObject.h"

DEATHOBJECT::DEATHOBJECT()
{
}

DEATHOBJECT::DEATHOBJECT(Texture2D texture, Rectangle rect, int speed, int rotation, float scale)
{
	Texture = texture;
	Rect.width *= scale;
	Rect.height *= scale;
	Rect = rect;
	Speed = rand() % 50 + 10; 
	Rotation = rotation;
	Scale = scale;

	Active = true;
}

DEATHOBJECT::~DEATHOBJECT()
{
}

void DEATHOBJECT::Update(float deltaTime)
{
	MoveObject(deltaTime);
	Draw();
}

void DEATHOBJECT::MoveObject(float deltaTime)
{
	//Object Pressed Controls
	{
			Rect.y += Speed * deltaTime;
			Rect.x += Speed * deltaTime;
	}
	//Object Restrictions
	{
		if (Rect.y + Rect.height > GetScreenHeight())
			Active = false;
	}
}

void DEATHOBJECT::Draw()
{
	if(Active)
		DrawTextureEx(Texture, { Rect.x, Rect.y }, (float)Rotation, Scale, RED);
}

Rectangle DEATHOBJECT::GetRect()
{
	return Rect;
}

bool& DEATHOBJECT::IsActive()
{
	return Active;
}
