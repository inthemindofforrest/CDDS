#include "Necromancer.h"

void NECROMANCER::moveTo()
{
	Vector2 Direction = { ((*player).position.x - position.x) / abs((*player).position.x - position.x),
		((*player).position.y - position.y) / abs((*player).position.y - position.y) };

	position.x += Direction.x;
	position.y += Direction.y;

}

void NECROMANCER::Update()
{
	destination = (*player).position;
	moveTo();
	Draw();
}

NECROMANCER::NECROMANCER(const std::string fileName, Vector2 Position, float Speed, PLAYER * Player) : ENEMY(fileName)
{
	position = Position;
	speed = Speed;
	player = Player;
	IsAlive = false;
}

NECROMANCER::~NECROMANCER()
{

}