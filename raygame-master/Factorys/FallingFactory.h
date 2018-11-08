//FallingFactory.h
#pragma once
typedef size_t tiny_t;
#include "raylib.h"
#include "SimpleSprite.h"

class FallingFactory
{
	SimpleSprite* spriteMasters;
	tiny_t spriteCount;
	
	FallingFactory();
	FallingFactory(FallingFactory const&);  // prevents external use
	void operator=(FallingFactory const&); // prevents external use

public:
	void init();

	SimpleSprite * getRandom();// returns a random sprite from all sprites loaded
	SimpleSprite * getFromType(const std::string & _sprType);// Returns a random sprite from this type of sprites.

	
	~FallingFactory();
};