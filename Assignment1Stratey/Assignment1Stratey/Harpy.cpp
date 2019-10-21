#include "Harpy.h"
#include "Units.h"
#include "olcPixelGameEngine.h"
#include "Hero.h"
Harpy::Harpy(Hero* DungeonHero)
{
	CreateUnitSprite(new olc::Sprite("TroglodyteSprite.png"));
	SetStats(5 + DungeonHero->GetAttack(), 3 + DungeonHero->GetDefense(), 7);
	SetPositionX(38);
	SetPositionY(220);
}

Harpy::Harpy()
{
}
