#pragma once
namespace olc
{
	class Sprite;
}

class Spell
{
public:
	virtual void CastSpell() = 0;
	virtual int GetManaRequired() = 0;
	virtual int ReturnDamage() = 0;
	virtual olc::Sprite* GetSprite() = 0;
	virtual void AssignSprite(olc::Sprite* ThisSpell) = 0;

};

