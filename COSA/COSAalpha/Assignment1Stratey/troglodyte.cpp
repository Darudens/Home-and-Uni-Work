#include "troglodyte.h"
#include "Units.h"
#include "olcPixelGameEngine.h"
#include "Hero.h"
troglodyte::troglodyte(Hero* DungeonHero)
{
	CreateUnitSprite(new olc::Sprite("TroglodyteSprite.png"));
	SetStats(6, 3 + DungeonHero->GetDefense(), 4, 5 + DungeonHero->GetAttack());
	SetPositionX(38);
	SetPositionY(120);
	SetAllianceStatusToFriendly();
}

troglodyte::troglodyte()
{
}
