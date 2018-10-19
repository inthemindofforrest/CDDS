#pragma once
#include "ButtonController.h"

class BARBARIANBUTTON : public BUTTON
{
public:
	void Update(PLAYER ** Player);
	BARBARIANBUTTON(const Rectangle rect, const std::string & fileName);
};