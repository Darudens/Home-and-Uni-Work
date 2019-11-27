#pragma once
#include "PickUp.h"
#include "Hero.h"
class Spell;
class PickUpSpell : public PickUp
{
private:
		Spell* spellToAdd;
public:
		PickUpSpell(Spell* spell) : spellToAdd(spell) {}
		void Collect(Hero* hero) override
		{
			hero->ReturnSpellBook()->AddSpell(spellToAdd);
		}

};

