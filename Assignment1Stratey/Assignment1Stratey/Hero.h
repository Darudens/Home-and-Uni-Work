#pragma once
#include "SpellBook.h"
namespace olc
{
	class Sprite;
}
class Hero
{
public:
	Hero(int mana, int attack, int defense, int x, int y) : mana(mana),
		atk(attack), def(defense), PosX(x), PosY(y){}
	Hero();
	int GetAttack()
	{
		return atk;
	}
	int GetDefense()
	{
		return def;
	}
	int GetMana()
	{
		return mana;
	}
	int GetPosX()
	{
		return PosX;
	}
	int GetPosY()
	{
		return PosY;
	}
	int HeroCollider(int Height, int Width)
	{
		return Height + Width;
	}
	SpellBook* ReturnSpellBook()
	{
		return &HeroesSpellBook;
	}
	olc::Sprite* GetSprite()
	{
		return NewHeroClass;
	}
	void SetPositionX(int MousePosX)
	{
		PosX = MousePosX;
	}
	void SetPositionY(int MousePosY)
	{
		PosY = MousePosY;
	}
	void CreateHeroSprite(olc::Sprite* NewHeroSprite)
	{
		NewHeroClass = NewHeroSprite;
	}
private:
	int mana;
	int atk;
	int def;
	int PosX, PosY;
	SpellBook HeroesSpellBook;
	olc::Sprite* NewHeroClass;
};

