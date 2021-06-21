#include "Minotaur.h"
#include "Units.h"
#include "olcPixelGameEngine.h"
#include "Hero.h"
Minotaur::Minotaur(Hero* DungeonHero)
{
	CreateUnitSprite(new olc::Sprite("Minotaur.png"));
	SetStats(50, 3 + DungeonHero->GetDefense(), 5, 14 + DungeonHero->GetAttack());
	SetPositionX(38);
	SetPositionY(320);
	SetAllianceStatusToFriendly();
}

Minotaur::Minotaur()
{
}
