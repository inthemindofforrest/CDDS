#pragma once
#include "Sprite.h"


class BUTTON : public SPRITE
{
public:
	void Draw();// This Draw function will override the base classes Draw.
	bool CheckForClick();

	BUTTON(const std::string *filename, const Vector2 & position, const  int cellCount = 1);
	BUTTON();
	~BUTTON();
};