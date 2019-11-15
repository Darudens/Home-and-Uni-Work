#pragma once
#include "olcPixelGameEngine.h"
namespace olc
{
	class Sprite;
}
class Units : public olc::PixelGameEngine
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

	void attack(int atk)
	{
		//TODO
	}

	void SetUnitPosition(int X, int Y)
	{
		if (GetKey(olc::Key::K).bPressed)
		{
			PosX = GetMouseX();
			PosY = GetMouseY();
		}
	}
	//void DrawSpeedGrid(int spd, int X, int Y)
	//{
	//	for (int x = 0; x < spd; x++)
	//		DrawRect(X, Y, 42, 42, olc::BLACK);
	//}

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

