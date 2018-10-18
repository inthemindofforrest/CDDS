#include "ButtonMaker.h"
#include "Sprite.h"

SPRITE::SPRITE()
{
	Texture = NULL;
	FrameRate = 25.0f;
	FrameCount = 1;
	Direction = 1;
	CurrentFrame = 1;
	PlayerControlled = true;
}
SPRITE::~SPRITE()
{
	for (int i = 0; i < FrameCount; i++)
	{
		UnloadTexture(Texture[i]);
	}
	delete Texture;
}
SPRITE::SPRITE(const std::string *fileName, const int cellCount, const float frameRate)
{
	Texture = new Texture2D[cellCount];
	for (int i = 0; i < cellCount; i++)
	{
		Texture[i] = LoadTexture(fileName[i].c_str());
	}
	FrameRate = frameRate;
	FrameCount = cellCount;
	Direction = 1;
	CurrentFrame = 0;
	PlayerControlled = true;
}
void SPRITE::Draw(time_t deltaTime)
{
	Timer++;

	if (Timer > GetFPS() / FrameRate)
	{
		Timer = 0;
		CurrentFrame++;
		if (CurrentFrame >= FrameCount)
		{
			CurrentFrame = 0;
		}
	}
	DrawTexture(Texture[CurrentFrame], x, y, WHITE);



	x += Direction;
}
void SPRITE::Update(time_t deltaTime)
{
	Draw(deltaTime);

	if (PlayerControlled)
	{
		if (IsKeyPressed(KEY_D))
		{
			Direction = 1;
		}
		if (IsKeyPressed(KEY_A))
		{
			Direction = -1;
		}
	}
}


BUTTON::BUTTON()
{
	Direction = 0;
	PlayerControlled = false;
}

BUTTON::~BUTTON()
{

}

BUTTON::BUTTON(const std::string *filename, const Vector2 & position, const  int cellCount)
{
	for(int i = 0; i < cellCount; i++)
		*Texture = LoadTexture(filename[i].c_str());
	x = position.x;
	y = position.y;
}

bool BUTTON::CheckForClick()
{
	if (IsMouseButtonDown(0) && 
		(GetMousePosition().x > x && GetMousePosition().x < x + Texture[0].width) &&
		(GetMousePosition().y > x && GetMousePosition().x < y + Texture[0].height))
	{
		return true;
	}
}

void BUTTON::Draw()
{
	DrawTexture(Texture[0], x, y, WHITE);
}