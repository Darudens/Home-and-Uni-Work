#pragma once
#include "PickUp.h"
#include "Hero.h"
#include "Spell.h"
class PickUpSpell : public PickUp
{
private:
		Spell* spellToAdd;
public:
		PickUpSpell();
		PickUpSpell(Spell* spell) : spellToAdd(spell) {}
		void Collect(Hero* hero) override
		{
			hero->ReturnSpellBook()->AddSpell(spellToAdd);
		}
		void CheckItemCollision(int X, int Y, int X2, int Y2, bool &Active, Hero *hero) override
		{
			if (X <= X2 && Y <= Y2 && Active == true)
			{
				Collect(hero);
				Active = false;
				spellToAdd->DeleteSprite();
			}
		}
};

