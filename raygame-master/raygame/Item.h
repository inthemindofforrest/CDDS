#pragma once
#include "raylib.h"
#include <string>

using std::string;

class ITEMS
{
private:
	string ItemName;
	int Quality;
	int Range;
	Texture2D Texture;
	int AttackDamage;
	Vector2 Position;

public:
	ITEMS();
	ITEMS(string itemName, int quality, int range, string textureName, int attackDamage, Vector2 positon);

};