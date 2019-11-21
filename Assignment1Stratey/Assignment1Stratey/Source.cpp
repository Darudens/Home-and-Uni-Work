#define OLC_PGE_APPLICATION
#include <iostream>
#include <vector>
#include "olcPixelGameEngine.h"
#include "Units.h"
#include "troglodyte.h"
#include "Minotaur.h"
#include "Harpy.h"
#include "Hero.h"
class COSA : public olc::PixelGameEngine
{
public:
	troglodyte TROGLODYTE;
	Minotaur MINOTAUR;
	Harpy HARPY;
	Hero DACE;
	bool Adventure;
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
		Background = new olc::Sprite("Adventure.png");
		DrawBackground();
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
			MoveByTurn();
		}
		return true;
	}
public:
	//Function to draw battlebackground determined by png file.
	void DrawBackground()
	{
		DrawSprite(0, 0, Background, 1);
	}
	//Function to draw grid for units to spawn and move around.
	void DrawGrid()
	{
		for (int x = 0; x < ScreenWidth(); x += 42)
			for (int y = 84; y < ScreenHeight(); y += 42)
			{
				DrawRect(x, y, 42, 42, GridColour);
			}
	}

	void DrawReach(int UnitPosX, int UnitPosY, int UnitSPD) //Draws area of available moves depending on creatures speed
	{
		DrawRect(UnitPosX - 38, UnitPosY + 5, 42 * UnitSPD, 42 * UnitSPD, olc::YELLOW);
	}

	/////////TODO: Create a function that will allow to move creatures around the board depending on their speed.//////////////
	int GetMouseX()
	{
		if (GetMouse(0).bPressed)
		{
			return GetMouseX();
		}
	}

	int GetMouseY()
	{
		if (GetMouse(0).bPressed)
		{
			return GetMouseY();
		}
	}

	void MoveByTurn()
	{
		DrawReach(BySpeed[UnitID]->GetPositionX(), BySpeed[UnitID]->GetPositionY(), BySpeed[UnitID]->GetSpeed());
		if (GetKey(olc::Key::C).bPressed)
		{
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