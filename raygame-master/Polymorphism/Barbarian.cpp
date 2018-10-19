#include "Barbarian.h"

BARBARIAN::BARBARIAN(const std::string & fileName, Vector2 Position, float Speed) : PLAYER(fileName)
{
	position = Position;
	speed = Speed;
}

void BARBARIAN::moveTo()
{
	Vector2 Direction = { (destination.x - position.x) / abs(destination.x - position.x),
		(destination.y - position.y) / abs(destination.y - position.y) };

	if (position.x != destination.x)position.x += Direction.x;
	if (position.y != destination.y)position.y += Direction.y;
}

void BARBARIAN::Update()
{
	Draw();
	moveTo();

	if (IsMouseClicked())
	{
		destination = { (float)GetMouseX(), (float)GetMouseY() };
	}
}