#include "Potion.h"


POTION::POTION(string name, int hpModifier, int quality, int useByDates)
{
	Name = name;
	HPModifier = hpModifier;
	Quality = quality;
	UseByDate = useByDates;
}