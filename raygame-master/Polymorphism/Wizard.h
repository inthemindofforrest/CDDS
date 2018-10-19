#pragma once
#include "Player.h"

class WIZARD : public PLAYER
{
public:

	WIZARD();
	WIZARD(const std::string & fileName, Vector2 Position, float Speed);

	void moveTo();
	void Update();
};