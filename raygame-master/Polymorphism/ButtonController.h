#pragma once
#include "raylib.h"
#include <iostream>
#include <string>

#include "Player.h"
#include "Barbarian.h"
#include "Wizard.h"

class BUTTON
{
public:

	Rectangle Rect;
	Texture2D Texture;

	void Draw();
	bool Clicked();
	virtual void Update(PLAYER ** Player) = 0;

	BUTTON();
	~BUTTON();

	BUTTON(const Rectangle rect, const std::string & fileName);
};