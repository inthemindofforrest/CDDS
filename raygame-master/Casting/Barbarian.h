#pragma once
#include "raylib.h"

#include <string>

using namespace std;

class BARBARIAN
{
public:
	BARBARIAN();
	BARBARIAN(const string &name, int health, int attack, int gold, Rectangle rect);

	string Name;
	int Health;
	int Attack;
	int Gold;

	Rectangle Rect;
	Texture2D Texture;
	Texture2D DeathTexture;

	void Draw();

private:

};