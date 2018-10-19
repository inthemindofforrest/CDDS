#include "BarbarianButton.h"

void BARBARIANBUTTON::Update(PLAYER ** Player)
{
	if (Clicked())
	{
		delete *Player;
		*Player = new BARBARIAN("BarbarianSprite.png", { 100, 100 }, 2);
	}
	Draw();
}

BARBARIANBUTTON::BARBARIANBUTTON(const Rectangle rect, const std::string & fileName)
	: BUTTON(rect, fileName)
{

}