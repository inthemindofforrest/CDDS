#include "functions.h"



void DeathUpdate(WIZARD * Wizard, int WizardSize, CORPS *Corp, int CorpSize)
{

	for (int i = 0; i < WizardSize; i++)
	{
		if (Wizard[i].Health <= 0)
		{
			CORPS * TempCorps = Corp;
			Corp = new CORPS[CorpSize + 1];
			for (int i = 0; i < CorpSize; i++)
			{
				Corp[i] = TempCorps[i];
			}
			//delete TempCorps;

			Corp[sizeof(Corp) / sizeof(CORPS)].DeathTexture = Wizard[i].DeathTexture;
			Corp[sizeof(Corp) / sizeof(CORPS)].Gold = Wizard[i].Gold;
			Corp[sizeof(Corp) / sizeof(CORPS)].Name = Wizard[i].Name;
			Corp[sizeof(Corp) / sizeof(CORPS)].Rect = Wizard[i].Rect;
		}
	}

}