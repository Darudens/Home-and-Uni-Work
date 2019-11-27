#pragma once
#include "Spell.h"

class FireBall : public Spell
{
public:
	FireBall();
	int GetManaRequired() override;
	int ReturnDamage() override;
	void AssignSprite(olc::Sprite* ThisSpell) override;
	olc::Sprite* GetSprite() override;
	void CastSpell() override;

private:
	int ManaRequired = 7;
	int Damage = 10;
	olc::Sprite* FireBallSprite;
};

