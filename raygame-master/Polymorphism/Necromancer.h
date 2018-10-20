#pragma once
#include "Enemy.h"


class NECROMANCER : public ENEMY
{
public:
	void moveTo();
	void Update();


	NECROMANCER(const std::string fileName, Vector2 Position, float Speed, PLAYER * Player);

	~NECROMANCER();
};
