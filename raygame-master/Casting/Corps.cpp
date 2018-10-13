#include "Corps.h"
#include "Wizard.h"
#include "Barbarian.h"
CORPS::CORPS()
{
	Name = "";
	Gold = 0;

	Rect = { 0,0,0,0 };
}

CORPS::CORPS(WIZARD Wiz)
{
	Name = Wiz.Name;
	Gold = Wiz.Gold;

	Rect = Wiz.Rect;
	DeathTexture = Wiz.DeathTexture;
}
CORPS::CORPS(BARBARIAN Barbar)
{
	Name = Barbar.Name;
	Gold = Barbar.Gold;

	Rect = Barbar.Rect;
	DeathTexture = Barbar.DeathTexture;
}

void CORPS::Draw()
{
	DrawTexture(DeathTexture, (int)Rect.x, (int)Rect.y, WHITE);
}

