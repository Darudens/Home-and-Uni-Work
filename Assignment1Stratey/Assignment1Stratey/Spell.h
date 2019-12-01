#pragma once
#include <string>
namespace olc
{
	class Sprite;
}

class Spell
{
public:
	virtual void CastSpell(int W, int H, bool SpellBookOpen, bool SpellSelected) = 0;
	virtual int GetManaRequired() = 0;
	virtual int ReturnDamage() = 0;
	virtual olc::Sprite* GetSprite() = 0;
	virtual void AssignSprite(olc::Sprite* ThisSpell) = 0;
	virtual void SetSpellName(std::string name) = 0;
	virtual std::string ReturnSpellName() = 0;
	virtual void DeleteSprite() = 0;
};

