#include "Barbarian.h"

BARBARIAN::BARBARIAN()
{
	Name = "";
	Attack = 0;
	Gold = 0;

	Rect = { 0,0,0,0 };
}

BARBARIAN::BARBARIAN(const string &name, int health, int attack, int gold, Rectangle rect)
{
	Name = name;
	Health = health;
	Attack = attack;
	Gold = gold;

	Rect = rect;
}

void BARBARIAN::Draw()
{
	DrawTexture(Texture, (int)Rect.x, (int)Rect.y, WHITE);
}