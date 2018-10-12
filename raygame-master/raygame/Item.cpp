#include "Item.h"


ITEMS::ITEMS()
{
	ItemName = "";
	Quality = 0;
	Range = 0;
	AttackDamage = 0;
	Position = { 0,0 };
}

ITEMS::ITEMS(string itemName, int quality, int range, string textureName, int attackDamage, Vector2 positon)
{
	ItemName = itemName;
	Quality = quality;
	Range = range;
	Texture = LoadTexture(textureName.c_str());
	AttackDamage = attackDamage;
	Position = positon;
}