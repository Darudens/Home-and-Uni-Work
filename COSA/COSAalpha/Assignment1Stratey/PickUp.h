#pragma once
class Hero;
class PickUp
{
	virtual void Collect(Hero* hero) = 0;
	virtual void CheckItemCollision(int X, int Y, int X2, int Y2, bool &Active, Hero *hero) = 0;
};

