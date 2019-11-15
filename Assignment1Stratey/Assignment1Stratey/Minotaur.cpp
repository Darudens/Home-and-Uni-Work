#include "Minotaur.h"
#include "Units.h"
#include "olcPixelGameEngine.h"
#include "Hero.h"
Minotaur::Minotaur(Hero* DungeonHero)
{
	CreateUnitSprite(new olc::Sprite("Minotaur.png"));
	SetStats(5 + DungeonHero->GetAttack(), 3 + DungeonHero->GetDefense(), 5);
	SetPositionX(38);
	SetPositionY(320);
}

Minotaur::Minotaur()
{
}
