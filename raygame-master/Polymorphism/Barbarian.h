#pragma once
#include "Player.h"

class BARBARIAN : public PLAYER
{
public:

	BARBARIAN();
	BARBARIAN(const std::string & fileName, Vector2 Position, float Speed);

	void moveTo();
	void Update();
};