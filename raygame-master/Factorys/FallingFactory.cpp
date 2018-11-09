#include "FallingFactory.h"

void FallingFactory::init()
{
	//Load in the various sprites
	spriteCount = 4;
	spriteMasters = new SimpleSprite[spriteCount];
	spriteMasters[0] = *(new SimpleSprite("Sprites/spaceMeteors_001.png", "rocky", 1));
	spriteMasters[1] = *(new SimpleSprite("Sprites/spaceMeteors_002.png", "rocky", 1));
	spriteMasters[2] = *(new SimpleSprite("Sprites/spaceMeteors_003.png", "rocky", 1));
	spriteMasters[3] = *(new SimpleSprite("Sprites/spaceMeteors_004.png", "rock", 1));
}

SimpleSprite * FallingFactory::getRandom()
{
	return &spriteMasters[rand() % spriteCount];
	//return nullptr;
}

SimpleSprite * FallingFactory::getFromType(const std::string & _sprType)
{
	int Count = 0;
 	SimpleSprite* newSimpleSprite = nullptr;

	for (size_t i = 0; i < spriteCount - 1; i++)
	{
		if (spriteMasters[i].sprType == _sprType)
		{
			SimpleSprite * Temp = new SimpleSprite[++Count];
			if (Count > 1)
			{
				for (size_t j = 0; j < Count - 2; j++)
					Temp[j] = newSimpleSprite[j];
			}
			Temp[i] = spriteMasters[i];
		}
	}
	if (Count != 0)
		return &newSimpleSprite[/*(rand() % Count) - 1*/ 0];
}

FallingFactory::FallingFactory()
{
}

void FallingFactory::operator=(FallingFactory const &)
{
}

FallingFactory::~FallingFactory()
{
}
