#include "Maap.h"

MAAP::MAAP()
{
	enabled = false;
	texture = LoadTexture("Maap.png");
	Position = { 0,0 };
	PlayerControl = false;
}

MAAP::MAAP(bool Enabled, const string FileName, bool NewPlayerControl)
{
	enabled = Enabled;
	texture = LoadTexture(FileName.c_str());
	Position = { 100,100 };
	PlayerControl = NewPlayerControl;
}

MAAP::~MAAP()
{

}

void MAAP::refresh()
{
	DrawTexture(texture, Position.x, Position.y, WHITE);
}
void MAAP::Move()
{
	if (PlayerControl)
	{
		Position.x = GetMouseX();
		Position.y = GetMouseY();
	}
}