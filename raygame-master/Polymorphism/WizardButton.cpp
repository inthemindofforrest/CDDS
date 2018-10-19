#include "WizardButton.h"

void WIZARDBUTTON::Update(PLAYER ** Player)
{
	if (Clicked())
	{
		delete *Player;
		*Player = new WIZARD("WizardSprite.png", { 100, 100 }, 2);
	}
	Draw();
}

WIZARDBUTTON::WIZARDBUTTON(const Rectangle rect, const std::string & fileName)
	: BUTTON(rect, fileName)
{

}