#pragma once
#include "Spell.h"
#include <string>
class FireBall : public Spell
{
public:
	FireBall();
	int GetManaRequired() override;
	int ReturnDamage() override;
	void AssignSprite(olc::Sprite* ThisSpell) override;
	olc::Sprite* GetSprite() override;
	void CastSpell() override;
	void SetSpellName(std::string name) override;
	std::string ReturnSpellName() override;
private:
	int ManaRequired = 7;
	int Damage = 10;
	std::string SpellName;
	olc::Sprite* FireBallSprite;
};

