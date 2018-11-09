#include "SimpleSprite.h"

void SimpleSprite::translate(Vector2 delta)
{
	pos.x += delta.x;
	pos.y += delta.y;
}

void SimpleSprite::draw()
{
	DrawTexturePro(texture, r1, r2, {-pos.x, -pos.y}, rot, WHITE);
	//std::cout << "Drawing object" << std::endl;
}

SimpleSprite::SimpleSprite()
{
}

SimpleSprite::SimpleSprite(const std::string & filename, const std::string _sprType, float scale)
{
	texture = LoadTexture(filename.c_str());
	sprType = _sprType;
	pos = { (float)(rand() % 100),(float)(rand() % 100) };
	r1 = { 0,0,(float)texture.width, (float)texture.height };
	r2 = { pos.x,pos.y,(float)texture.width * scale, (float)texture.height * scale };
	rot = 0;
}

SimpleSprite::~SimpleSprite()
{
}

void SimpleSprite::operator=(SimpleSprite const &copy)
{
	sprType = copy.sprType;
	pos = copy.pos;
	rot = copy.rot;
	r1 = copy.r1;
	r2 = copy.r2;
	texture = copy.texture;
}

void SimpleSprite::Resize(float newSize)
{
	r2 = { r1.x, r1.y, r1.width * newSize, r1.height * newSize };
}

SimpleSprite * SimpleSprite::Clone()
{
	return new SimpleSprite(*this);
}
