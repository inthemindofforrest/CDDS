#pragma once
#include "ButtonController.h"

class WIZARDBUTTON : public BUTTON
{
public:
	void Update(PLAYER ** Player);
	WIZARDBUTTON(const Rectangle rect, const std::string & fileName);
};