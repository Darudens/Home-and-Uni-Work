#pragma once
#include "olcPixelGameEngine.h"
namespace olc
{
	class Sprite;
}
class Units
{
public:
	void SetStats(int hp, int def, int spd)
	{
		health = hp;
		armour = def;
		speed = spd;
	}

	void CreateUnitSprite(olc::Sprite* NewUnitSprite)
	{
		UnitSprite = NewUnitSprite;
	}

	void SetPositionX(int X)
	{
		PosX = X;
	}

	void SetPositionY(int Y)
	{
		PosY = Y;
	}

	int GetPositionX()
	{
		return PosX;
	}

	int GetPositionY()
	{
		return PosY;
	}

	int GetSpeed()
	{
		return speed;
	}

	olc::Sprite* GetSprite()
	{
		return UnitSprite;
	}

private:
	int health;
	int armour;
	int speed;
	int PosX, PosY;
	olc::Sprite* UnitSprite;
};

