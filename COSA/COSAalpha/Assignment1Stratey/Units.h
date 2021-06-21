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

	void setDefence(int def)
	{
		armour += def;
	}

	void SetPositionX(int X)
	{
		PosX = X;
	}

	void SetPositionY(int Y)
	{
		PosY = Y;
	}

	void TakeDamage(int DamageTaken)
	{
		health -= DamageTaken;
	}

	void SetAllianceStatusToEnemy()
	{
		IsEnemy = true;
	}
	
	void SetAllianceStatusToFriendly()
	{
		IsEnemy = false;
	}

	void SetUnitID(int ID)
	{
		UnitID = ID;
	}

	void DeleteUnitSprite()
	{
		delete UnitSprite;
	}

	int CalculateDamage(int atk, int def)
	{
		return atk - def;
	}

	int CalculateDistanceToNearestenemy(int UnitPosX, int UnitPosY, int EnemyUnitPosX, int EnemyUnitPosY)
	{
		return UnitPosX - EnemyUnitPosY + UnitPosY - EnemyUnitPosY;
	}

	int GetUnitID()
	{
		return UnitID;
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

	int GetHeath()
	{
		return health;
	}

	int GetSpeed()
	{
		return speed;
	}

	int GetAttack()
	{
		return attack;
	}

	int GetArmour()
	{
		return armour;
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
	int UnitID;
	olc::Sprite* UnitSprite;
};

