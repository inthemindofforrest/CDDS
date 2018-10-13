#pragma once
#include "raylib.h"
#include "Wizard.h"
#include "Barbarian.h"
#include <string>

using namespace std;

class CORPS
{
public:
	CORPS();
	CORPS(WIZARD Wiz);
	CORPS(BARBARIAN Barbar);

	string Name;
	int Gold;

	Rectangle Rect;
	Texture2D DeathTexture;

	void Draw();
private:

};