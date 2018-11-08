#include "SimpleSprite.h"

void SimpleSprite::translate(Vector2 delta)
{
}

void SimpleSprite::draw()
{
	DrawTexturePro(texture, r1, r2, pos, rot, WHITE);
}

SimpleSprite::SimpleSprite()
{
}

SimpleSprite::SimpleSprite(const std::string & filename, const std::string _sprType, float scale)
{
}

SimpleSprite::~SimpleSprite()
{
}
