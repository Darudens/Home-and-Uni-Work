#include "FireBall.h"
#include "Spell.h"
#include "olcPixelGameEngine.h"
#include <iostream>
FireBall::FireBall()
{
	AssignSprite(new olc::Sprite("Artifacts.png"));
}
int FireBall::GetManaRequired() { return ManaRequired; };
int FireBall::ReturnDamage() { return Damage; };
void FireBall::AssignSprite(olc::Sprite* ThisSpell) { FireBallSprite = ThisSpell; };
olc::Sprite* FireBall::GetSprite() { return FireBallSprite; };
void FireBall::CastSpell() { std::cout << "Casting Fire Ball" << std::endl; };
