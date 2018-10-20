#include "Enemy.h"

ENEMY::ENEMY(const std::string & fileName)
{
	mySprite = LoadTexture(fileName.c_str());
	position = { 0,0 };
	destination = { 0,0 };
	speed = 0;
}
ENEMY::ENEMY()
{

}
ENEMY::~ENEMY()
{
	UnloadTexture(mySprite);
}

void ENEMY::Draw()
{
	DrawTexture(mySprite, (int)position.x, (int)position.y, WHITE);
}

void ENEMY::moveTo() {};
void ENEMY::Update() {};
