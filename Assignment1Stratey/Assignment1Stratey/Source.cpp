#define OLC_PGE_APPLICATION
#include <iostream>
#include "olcPixelGameEngine.h"
#include "Units.h"
#include "troglodyte.h"
#include "Hero.h"
class COSA : public olc::PixelGameEngine
{
public:
	troglodyte TROGLODYTE;
	Hero DACE;
	COSA()
	{
		sAppName = "COSA";
		SetPixelMode(olc::Pixel::MASK);
		Background = new olc::Sprite("BattleBackground.png");
		DACE = Hero(20, 4, 3, 0, 0);
		DACE.CreateHeroSprite(new olc::Sprite("Heroes.png"));
		TROGLODYTE = troglodyte(&DACE);
	}
	olc::Sprite* Background;  //creating a pointer to background file.
	olc::Pixel GridColour = olc::GREEN; //pointer to grid colour.
public:
	//game loop
	bool OnUserCreate() override
	{
		DrawBackground();
		DrawGrid();
		DrawPartialSprite(DACE.GetPosX(), DACE.GetPosY(), DACE.GetSprite(), 34, 1782, 72, 118, 1);
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		
		DrawPartialSprite(TROGLODYTE.GetPositionX(), TROGLODYTE.GetPositionY(), TROGLODYTE.GetSprite(), 21, 13, 60, 91, 1);
		DrawReach(TROGLODYTE.GetPositionX(), TROGLODYTE.GetPositionY(), TROGLODYTE.GetSpeed());
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

	void DrawReach(int UnitPosX, int UnitPosY, int UnitSPD)
	{
		DrawRect(UnitPosX - 38, UnitPosY + 5, 42 * UnitSPD, 42 * UnitSPD, olc::YELLOW);
	}
};

int main()
{

	COSA NewCOSA; //creating an instance of world class calling window to display game
	if (NewCOSA.Construct(800, 556, 1, 1))
		NewCOSA.Start();
	return 0;
}