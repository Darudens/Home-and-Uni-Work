#pragma once
#include "Spell.h"
#include <string>
#include "olcPixelGameEngine.h"
class FireBall : public Spell, olc::PixelGameEngine
{
public:
	FireBall();
	int GetManaRequired() override;
	int ReturnDamage() override;
	void AssignSprite(olc::Sprite* ThisSpell) override;
	void AssignAdventureSprite(olc::Sprite* ThisSpell);
	olc::Sprite* GetSprite() override;
	olc::Sprite* GetAdventureSprite();
	void CastSpell(int W, int H, bool SpellBookOpen, bool SpellSelected) override;
	void SetSpellName(std::string name) override;
	std::string ReturnSpellName() override;
	void DeleteSprite() override { delete AdventureSprite; };
private:
	int ManaRequired = 7;
	int Damage = 10;
	std::string SpellName;
	olc::Sprite* FireBallSprite;
	olc::Sprite* AdventureSprite;
};

