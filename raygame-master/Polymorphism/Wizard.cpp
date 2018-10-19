#include "Wizard.h"

WIZARD::WIZARD(const std::string & fileName, Vector2 Position, float Speed) : PLAYER(fileName)
{
	position = Position;
	speed = Speed;
}

void WIZARD::moveTo()
{
	Vector2 Direction = { position.x - destination.x, position.y - destination.y };

	/*position.x += Direction.x;
	position.y += Direction.y;*/
	position.x = destination.x;
	position.y = destination.y;
}

void WIZARD::Update()
{
	Draw();
	moveTo();

	if (IsMouseClicked())
	{
		destination = { (float)GetMouseX(), (float)GetMouseY() };
	}
}