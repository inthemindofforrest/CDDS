#include "Wizard.h"

WIZARD::WIZARD()
{
	Name = "";
	Mana = 0;
	Gold = 0;

	Rect = { 0,0,0,0 };
}


WIZARD::WIZARD(const string name,int health, int mana, int gold, Rectangle rect)
{
	Name = name;
	Health = health;
	Mana = mana;
	Gold = gold;

	Rect = rect;
}

void WIZARD::Draw()
{
	DrawTexture(Texture, (int)Rect.x, (int)Rect.y, WHITE);
}

void WIZARD::Update()
{

}