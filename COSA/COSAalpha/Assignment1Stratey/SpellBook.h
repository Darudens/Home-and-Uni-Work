#pragma once
#include "olcPixelGameEngine.h"
#include <list>
class Spell;
class SpellBook
{
public:
	SpellBook();
	void AssignSpellBookSprite(olc::Sprite* ThisSpellBookSprite);
	void AddSpell(Spell* NewSpell)
	{
		Spells.push_back(NewSpell);
	}
	olc::Sprite* ReturnSpellBookSprite();
	int ReturnSpellBookSize() { return Spells.size(); };
	const std::list<Spell*>& GetSpells() const
	{
		return Spells;
	}
private:
	olc::Sprite* SpellBookSprite;
	std::list<Spell*> Spells;
};
