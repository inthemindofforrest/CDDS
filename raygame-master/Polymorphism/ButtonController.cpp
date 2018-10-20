#include "ButtonController.h"

BUTTON::BUTTON(const Rectangle rect, const std::string & fileName)
{
	Rect = rect;
	Texture = LoadTexture(fileName.c_str());
}

BUTTON::~BUTTON()
{
	UnloadTexture(Texture);
}

void BUTTON::Draw()
{
	DrawTexture(Texture, (int)Rect.x, (int)Rect.y, WHITE);
}

bool BUTTON::Clicked()
{
	if (IsMouseButtonPressed(0) && CheckCollisionPointRec({ (float)GetMouseX(), (float)GetMouseY() }, Rect))
	{
		return true;
	}
	return false;
}