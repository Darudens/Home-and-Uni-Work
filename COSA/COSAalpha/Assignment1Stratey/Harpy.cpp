#include "Harpy.h"
#include "Units.h"
#include "olcPixelGameEngine.h"
#include "Hero.h"
Harpy::Harpy(Hero* DungeonHero)
{
	CreateUnitSprite(new olc::Sprite("Harpy.png"));
	SetStats(14 , 3 + DungeonHero->GetDefense(), 7, 6 + DungeonHero->GetAttack());
	SetPositionX(38);
	SetPositionY(420);
	SetAllianceStatusToFriendly();
}

Harpy::Harpy()
{
}
