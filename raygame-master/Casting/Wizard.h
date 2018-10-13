#pragma once
#include "raylib.h"
#include "raylib.h"
#include <string>

using namespace std;

class WIZARD
{
public:
	WIZARD();
	WIZARD(string name, int health, int mana, int gold, Rectangle rect);

	string Name;
	int Health;
	int Mana;
	int Gold;

	Rectangle Rect;
	Texture2D Texture;
	Texture2D DeathTexture;

	void Draw();
	void Update();

private:

};