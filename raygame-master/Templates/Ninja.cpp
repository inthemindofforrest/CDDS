#include "Ninja.h"


void NINJA::Render()
{
	DrawTexture(Texture, Position.x, Position.y, WHITE);
}

void NINJA::Update(float deltaTime)
{
	if (PlayerControlled)
	{
		if (IsKeyDown(KEY_W))
			Position.y -= 1 * deltaTime * Speed;
		if (IsKeyDown(KEY_S))
			Position.y += 1 * deltaTime * Speed;
		if (IsKeyDown(KEY_A))
			Position.x -= 1 * deltaTime * Speed;
		if (IsKeyDown(KEY_D))
			Position.x += 1 * deltaTime * Speed;
	}
	Render();
}
NINJA::NINJA(const std::string & fileName, Vector2 position, float speed, bool playerControlled)
{
	Texture = LoadTexture(fileName.c_str());
	Position = { 0,0 };
	Speed = 20;
	PlayerControlled = true;
}