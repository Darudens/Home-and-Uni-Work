#define OLC_PGE_APPLICATION
#include <iostream>
#include <vector>
#include "olcPixelGameEngine.h"
#include "Units.h"
#include "troglodyte.h"
#include "Minotaur.h"
#include "Harpy.h"
#include "Hero.h"
#include "Skeleton.h"
#include "Spell.h"
#include "FireBall.h"
#include "SpellBook.h"
#define UNIT_OFFSET_X -46
#define UNIT_OFFSET_Y -60
class COSA : public olc::PixelGameEngine
{
public:
	troglodyte TROGLODYTE;
	Minotaur MINOTAUR;
	Harpy HARPY;
	Hero DACE;
	Skeleton SKELETON;
	FireBall FIREBALL;
	SpellBook SPELLBOOK;
	bool Adventure;
	bool SpellBookIsOpen;
	int UnitID = 0;
	COSA()
	{
		sAppName = "COSA";
		SetPixelMode(olc::Pixel::MASK);
		DACE = Hero(20, 4, 3, 0, 0);
		DACE.CreateHeroSprite(new olc::Sprite("Heroes.png"));
		TROGLODYTE = troglodyte(&DACE);
		MINOTAUR = Minotaur(&DACE);
		HARPY = Harpy(&DACE);
		BySpeed.push_back(&TROGLODYTE);
		BySpeed.push_back(&MINOTAUR);
		BySpeed.push_back(&HARPY);
		BySpeed.push_back(&SKELETON);
		std::sort(BySpeed.begin(), BySpeed.end(), &COSA::CompareSpeed); //Custom sort to which puts units in speed order to determin which creature goes first
	}
	olc::Sprite* Background;  //creating a pointer to background file.
	olc::Pixel GridColour = olc::GREEN; //pointer to grid colour.
	std::vector<Units*> BySpeed; //Vector of class Units
public:
	//game loop
	bool OnUserCreate() override //Function called once during the runtime creates static components
	{
		Adventure = true;
		Background = new olc::Sprite("AdventureBackground.png");
		DrawBackground();
		DrawPartialSprite(500, 350, FIREBALL.GetSprite(), 55, 443, 47, 49, 1);
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override //Function called every tick
	{

		if (GetKey(olc::Key::A).bPressed)
		{
			Adventure = false;
			Clear(olc::WHITE);
			Background = new olc::Sprite("BattleBackground.png");
		}
		if (Adventure == false)
		{
			DrawBackground();
			DrawPartialSprite(DACE.GetPosX(), DACE.GetPosY(), DACE.GetSprite(), 21, 15, 89, 125, 1);
			DrawPartialSprite(TROGLODYTE.GetPositionX(), TROGLODYTE.GetPositionY(), TROGLODYTE.GetSprite(), 21, 13, 60, 91, 1);
			DrawPartialSprite(MINOTAUR.GetPositionX(), MINOTAUR.GetPositionY(), MINOTAUR.GetSprite(), 21, 13, 60, 91, 1);
			DrawPartialSprite(HARPY.GetPositionX(), HARPY.GetPositionY(), HARPY.GetSprite(), 21, 13, 60, 91, 1);
			DrawPartialSprite(SKELETON.GetPositionX(), SKELETON.GetPositionY(), SKELETON.GetSprite(), 1040, 34, 64, 98);
			MoveByTurn();
		}
		DrawSpellBook();
		return true;
	}
public:
	//Function to draw battlebackground determined by png file.
	void DrawBackground()
	{
		DrawSprite(0, 0, Background, 1);
	}

	void DrawReach(int UnitPosX, int UnitPosY, int UnitSPD) //Draws area of available moves depending on creatures speed
	{
		DrawRect(UnitPosX + UNIT_OFFSET_X, UnitPosY + UNIT_OFFSET_Y, 42 * UnitSPD, 42 * UnitSPD, olc::YELLOW);
	}

	void DrawSpellBook()
	{
		if (GetKey(olc::Key::B).bHeld)
		{
			DrawPartialSprite(0, 0, SPELLBOOK.ReturnSpellBookSprite(), 0, 0, 619, 594, 1);
		}
	}

	/////////TODO: Create a function that will allow to move creatures around the board depending on their speed.//////////////
	void MoveByTurn()
	{
		int directionX;
		int directionY;
		DrawReach(BySpeed[UnitID]->GetPositionX(), BySpeed[UnitID]->GetPositionY(), BySpeed[UnitID]->GetSpeed());
		if (GetMouse(0).bPressed && BySpeed[UnitID]->ReturnAlianceStatus() == false 
			&& GetMouseX() < BySpeed[UnitID]->GetPositionX() + BySpeed[UnitID]->GetSpeed() * 42
			&& GetMouseY() < BySpeed[UnitID]->GetPositionY() + BySpeed[UnitID]->GetSpeed() * 42)
		{
			BySpeed[UnitID]->SetPositionX(GetMouseX() + UNIT_OFFSET_X);
			BySpeed[UnitID]->SetPositionY(GetMouseY() + UNIT_OFFSET_Y);
			UnitID += 1;
		}
		else if (BySpeed[UnitID]->ReturnAlianceStatus() == true)
		{
			directionX = BySpeed[0]->GetPositionX() - BySpeed[UnitID]->GetPositionX();
			directionY = BySpeed[0]->GetPositionY() - BySpeed[UnitID]->GetPositionY();
			BySpeed[UnitID]->SetPositionX(BySpeed[UnitID]->GetPositionX() + (directionX / BySpeed[UnitID]->GetSpeed()));
			BySpeed[UnitID]->SetPositionY(BySpeed[UnitID]->GetPositionY() + (directionY / BySpeed[UnitID]->GetSpeed()));
			UnitID += 1;
		}
		if (UnitID == BySpeed.size())
		{
			UnitID = 0;
		}

	}


	static bool CompareSpeed(Units* Unit1, Units* Unit2) //Function working as a parameter for "sort" function which compares the speed of all units
	{
		return(Unit1->GetSpeed() > Unit2->GetSpeed());
	}
};

int main()
{

	COSA NewCOSA; //creating an instance of world class calling window to display game
	if (NewCOSA.Construct(800, 556, 1, 1))
		NewCOSA.Start();
	return 0;
}