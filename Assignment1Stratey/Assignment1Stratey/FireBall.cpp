#include "FireBall.h"
#include "Spell.h"
#include "olcPixelGameEngine.h"
#include <iostream>
FireBall::FireBall()
{
	AssignSprite(new olc::Sprite("Artifacts.png"));
	AssignAdventureSprite(new olc::Sprite("Artifacts.png"));
	SetSpellName("Fire Ball");
}
int FireBall::GetManaRequired() { return ManaRequired; };
int FireBall::ReturnDamage() { return Damage; };
void FireBall::AssignSprite(olc::Sprite* ThisSpell) { FireBallSprite = ThisSpell; };
void FireBall::AssignAdventureSprite(olc::Sprite* ThisSpell) { AdventureSprite = ThisSpell; };
olc::Sprite* FireBall::GetSprite() { return FireBallSprite; };
olc::Sprite* FireBall::GetAdventureSprite() { return AdventureSprite; }
void FireBall::CastSpell(int W, int H, bool SpellBookOpen, bool SpellSelected)
{
	if (GetMouse(0).bPressed && GetMouseX() <= H * W && SpellBookOpen == true)
	{
		SpellSelected = true;
		if (SpellSelected == true)
		{
			DrawPartialSprite(GetMouseX(), GetMouseY(), FireBallSprite, 55, 443, 47, 49, 1);
		}
	}
};
void FireBall::SetSpellName(std::string name){SpellName = name;}
std::string FireBall::ReturnSpellName(){return std::string(SpellName);}




