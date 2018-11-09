//FallingFactory.h
#pragma once
#include "raylib.h"
#include "SimpleSprite.h"


class FallingFactory
{
	static SimpleSprite* spriteMasters;
	static size_t spriteCount;
	
	FallingFactory();
	FallingFactory(FallingFactory const&);  // prevents external use
	void operator=(FallingFactory const&); // prevents external use

public:
	static void init();

	static SimpleSprite * getRandom();// returns a random sprite from all sprites loaded
	static SimpleSprite * getFromType(const std::string & _sprType);// Returns a random sprite from this type of sprites.
	
	~FallingFactory();
};