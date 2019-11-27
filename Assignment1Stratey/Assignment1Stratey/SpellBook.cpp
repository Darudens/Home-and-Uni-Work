#include "SpellBook.h"
#include "Spell.h"
#include "olcPixelGameEngine.h"
SpellBook::SpellBook()
{
	AssignSpellBookSprite(new olc::Sprite("SpellBook.png"));
}
void SpellBook::AssignSpellBookSprite(olc::Sprite* ThisSpellBookSprite) { SpellBookSprite = ThisSpellBookSprite; };
olc::Sprite* SpellBook::ReturnSpellBookSprite() { return SpellBookSprite; };