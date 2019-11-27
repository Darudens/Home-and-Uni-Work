#pragma once
#include "olcPixelGameEngine.h"
class Spell;
class SpellBook
{
public:
	SpellBook();
	void AssignSpellBookSprite(olc::Sprite* ThisSpellBookSprite);
	olc::Sprite* ReturnSpellBookSprite();
private:
	olc::Sprite* SpellBookSprite;
};

