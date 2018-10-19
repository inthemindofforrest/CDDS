#include "Player.h"

PLAYER::PLAYER(const std::string & fileName)
{
	mySprite = LoadTexture(fileName.c_str());
}

PLAYER::PLAYER()
{
}

PLAYER::~PLAYER()
{
	UnloadTexture(mySprite);
}

void PLAYER::Draw()
{
	DrawTexture(mySprite, position.x, position.y, WHITE);
}

bool PLAYER::IsMouseClicked()
{
	if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
	{
		return true;
	}
}

