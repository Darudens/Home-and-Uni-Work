#pragma once
#include "olcPixelGameEngine.h"
namespace olc
{
	class Sprite;
}
class Units : public olc::PixelGameEngine
{
public:
	void SetStats(int hp, int def, int spd, int atk)
	{
		health = hp;
		armour = def;
		speed = spd;
		attack = atk;
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

	void DoAttack(int atk)
	{
		//TODO
	}

	void SetAllianceStatusToEnemy()
	{
		IsEnemy = true;
	}
	
	void SetAllianceStatusToFriendly()
	{
		IsEnemy = false;
	}

	int CalculateDistanceToNearestenemy(int UnitPosX, int UnitPosY, int EnemyUnitPosX, int EnemyUnitPosY)
	{
		return UnitPosX - EnemyUnitPosY + UnitPosY - EnemyUnitPosY;
	}

	bool ReturnAlianceStatus()
	{
		return IsEnemy;
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
	bool IsEnemy;
	int attack;
	int health;
	int armour;
	int speed;
	int PosX, PosY;
	olc::Sprite* UnitSprite;
};

