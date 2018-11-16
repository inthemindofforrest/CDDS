#include "SimpleSprite.h"

void SimpleSprite::translate(Vector2 delta)
{
	pos.x += delta.x;
	pos.y += delta.y;
	r2.x = pos.x;
	r2.y = pos.y;
}

void SimpleSprite::draw()
{
	//DrawTexturePro(texture, r1, r2, {pos.x, pos.y}, rot, WHITE);
	DrawTextureEx(texture, pos, rot, 1, WHITE);
	DrawRectangleLines(r2.x, r2.y, r2.width, r2.height, RED);
	//std::cout << "Drawing object" << std::endl;
}

SimpleSprite::SimpleSprite()
{
}

SimpleSprite::SimpleSprite(const std::string & filename, const std::string _sprType, float scale)
{
	texture = LoadTexture(filename.c_str());
	sprType = _sprType;
	pos = { (float)(rand() % 20 + GetScreenWidth()),(float)(rand() % GetScreenHeight()) };
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

bool SimpleSprite::operator==(SimpleSprite &Other)
{
	return (
		sprType == Other.sprType && (pos.x == Other.pos.x && pos.y == Other.pos.y) &&
		rot == Other.rot &&
		(r1.x == Other.r1.x &&r1.y == Other.r1.y &&r1.width == Other.r1.width &&r1.height == Other.r1.height) &&
		(r2.x == Other.r2.x &&r2.y == Other.r2.y &&r1.width == Other.r2.width &&r2.height == Other.r2.height));
}

void SimpleSprite::Resize(float newSize)
{
	r2 = { r1.x, r1.y, r1.width * newSize, r1.height * newSize };
}

SimpleSprite * SimpleSprite::Clone()
{
	return new SimpleSprite(*this);
}

