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
#define TEXT_OFFSET_X 30
#define TEXT_OFFSET_Y 95
class COSA : public olc::PixelGameEngine
{
public:
	troglodyte TROGLODYTE;
	Minotaur MINOTAUR;
	Harpy HARPY;
	Hero DACE;
	Skeleton SKELETON;
	SpellBook SPELLBOOK;
	FireBall FIREBALL;
	bool Adventure;
	bool SpellBookIsOpen = false;
	int UnitID = 0;
	COSA()
	{
		sAppName = "COSA";
		SetPixelMode(olc::Pixel::MASK);
		TROGLODYTE = troglodyte(&DACE);
		MINOTAUR = Minotaur(&DACE);
		HARPY = Harpy(&DACE);
		MouseSprite = new olc::Sprite("MouseCoursor.png");
		BySpeed.push_back(&TROGLODYTE);
		BySpeed.push_back(&MINOTAUR);
		BySpeed.push_back(&HARPY);
		BySpeed.push_back(&SKELETON);
		std::sort(BySpeed.begin(), BySpeed.end(), &COSA::CompareSpeed); //Custom sort to which puts units in speed order to determin which creature goes first
	}
	olc::Sprite* Background;  //creating a pointer to background file.
	olc::Sprite* MouseSprite;
	std::vector<Units*> BySpeed; //Vector of class Units
public:
	//game loop
	bool OnUserCreate() override //Function called once during the runtime creates static components
	{
		SetPixelMode(olc::Pixel::MASK);
		DACE = Hero(20, 4, 3, 700, 330);
		Adventure = true;
		Background = new olc::Sprite("AdventureBackground.png");
		DACE.CreateHeroSprite(new olc::Sprite("HeroAdventure.png"));
		//DACE.ReturnSpellBook()->AddSpell(FIREBALL);
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override //Function called every tick
	{
		if (Adventure == true)
		{
			DrawBackground();
			DrawPartialSprite(500, 350, FIREBALL.GetSprite(), 55, 443, 47, 49, 1);
			DrawPartialSprite(DACE.GetPosX(), DACE.GetPosY(), DACE.GetSprite(), 4044, 646, 68, 60, 1);
			MoveHero();
			DACE.ReturnSpellBook()->AddSpell(&FIREBALL);
		}
		if (GetKey(olc::Key::A).bPressed)
		{
			Adventure = false;
			Clear(olc::WHITE);
			DACE = Hero(20, 4, 3, 0, 0);
			Background = new olc::Sprite("BattleBackground.png");
			DACE.CreateHeroSprite(new olc::Sprite("Heroes.png"));
		}
		if (Adventure == false)
		{
			DrawBackground();
			DrawPartialSprite(DACE.GetPosX(), DACE.GetPosY(), DACE.GetSprite(), 21, 15, 89, 125, 1);
			DrawPartialSprite(TROGLODYTE.GetPositionX(), TROGLODYTE.GetPositionY(), TROGLODYTE.GetSprite(), 21, 13, 60, 91, 1);
			DrawPartialSprite(MINOTAUR.GetPositionX(), MINOTAUR.GetPositionY(), MINOTAUR.GetSprite(), 21, 13, 60, 91, 1);
			DrawPartialSprite(HARPY.GetPositionX(), HARPY.GetPositionY(), HARPY.GetSprite(), 21, 13, 60, 91, 1);
			//DrawString(HARPY.GetPositionX(), HARPY.GetPositionY(), std::string(std::to_string(HARPY.GetHeath())), olc::WHITE, 1);
			DrawPartialSprite(SKELETON.GetPositionX(), SKELETON.GetPositionY(), SKELETON.GetSprite(), 1040, 34, 64, 98);
			DrawHealth();
			BattleTurnFaze();
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

	int ReturnReach(int SizeInPixels, int UnitSPD)
	{
		return SizeInPixels * UnitSPD;
	}

	void DrawSpellBook()
	{
		if (GetKey(olc::Key::B).bPressed)
		{
			SpellBookIsOpen = !SpellBookIsOpen;
		}
		if (SpellBookIsOpen == true)
		{
			DrawPartialSprite(0, 0, SPELLBOOK.ReturnSpellBookSprite(), 0, 0, 619, 594, 1);
			DrawString(426, 420, std::string(std::to_string(DACE.GetMana())), olc::WHITE, 1);
			DrawPartialSprite(111, 92, FIREBALL.GetSprite(), 55, 443, 47, 49, 1);
			DrawString(110, 153, std::string(FIREBALL.ReturnSpellName()), olc::WHITE, 1);
			DrawString(110, 163, std::string("Mana required: ") + (std::to_string(FIREBALL.GetManaRequired())), olc::WHITE, 1);
			DrawString(110, 173, std::string("Damage: ") + (std::to_string(FIREBALL.ReturnDamage())), olc::WHITE, 1);
		}
	}


	void MoveHero()
	{
		if (GetMouse(0).bPressed)
		{
			DACE.SetPositionX(GetMouseX());
			DACE.SetPositionY(GetMouseY() + UNIT_OFFSET_Y);
		}
	}

	/////////TODO: Create a function that will allow to move creatures around the board depending on their speed.//////////////
	void BattleTurnFaze()
	{
		int directionX = BySpeed[0]->GetPositionX() - BySpeed[UnitID]->GetPositionX() - UNIT_OFFSET_X;
		int directionY = BySpeed[0]->GetPositionY() - BySpeed[UnitID]->GetPositionY();

		DrawReach(BySpeed[UnitID]->GetPositionX(), BySpeed[UnitID]->GetPositionY(), BySpeed[UnitID]->GetSpeed());
		BySpeed[UnitID]->SetUnitID(UnitID);
		if (GetMouse(0).bPressed && BySpeed[UnitID]->ReturnAlianceStatus() == false 
			&& GetMouseX() < BySpeed[UnitID]->GetPositionX() + BySpeed[UnitID]->GetSpeed() * 42
			&& GetMouseY() < BySpeed[UnitID]->GetPositionY() + BySpeed[UnitID]->GetSpeed() * 42)
		{
			BySpeed[UnitID]->SetPositionX(GetMouseX() + UNIT_OFFSET_X);
			BySpeed[UnitID]->SetPositionY(GetMouseY() + UNIT_OFFSET_Y);
			for (auto& b : BySpeed)
			{
				if (b->ReturnAlianceStatus() == true &&
					b->GetPositionX() <= BySpeed[UnitID]->GetPositionX() + ReturnReach(42, BySpeed[UnitID]->GetSpeed())
					&& b->GetPositionY() <= BySpeed[UnitID]->GetPositionY() + ReturnReach(42, BySpeed[UnitID]->GetSpeed()) && b->GetHeath() > 0)
				{
					b->TakeDamage(BySpeed[UnitID]->CalculateDamage(BySpeed[UnitID]->GetAttack(), b->GetArmour()));
					break;
				}
				else if (b->GetHeath() <= 0)
				{
					BySpeed.erase(BySpeed.begin() + b->GetUnitID());
				}
				else if (BySpeed[UnitID]->GetHeath() <= 0)
				{
					BySpeed.erase(BySpeed.begin() + BySpeed[UnitID]->GetUnitID());
				}
			}
			UnitID += 1;
		}
		else if (BySpeed[UnitID]->ReturnAlianceStatus() == true)
		{
			BySpeed[UnitID]->SetPositionX(BySpeed[UnitID]->GetPositionX() + directionX / BySpeed[UnitID]->GetSpeed());
			BySpeed[UnitID]->SetPositionY(BySpeed[UnitID]->GetPositionY() + directionY / BySpeed[UnitID]->GetSpeed());
			UnitID += 1;
		}
		if (GetKey(olc::Key::SPACE).bPressed)
		{
			BySpeed[UnitID]->setDefence(3);
			UnitID += 1;
		}
		if (UnitID == BySpeed.size())
		{
			UnitID = 0;
		}

	}

	void DrawHealth()
	{
		for (const auto&a : BySpeed)
		{
			DrawString(a->GetPositionX() + TEXT_OFFSET_X, a->GetPositionY() + TEXT_OFFSET_Y, std::string(std::to_string(a->GetHeath())), olc::BLACK, 1);
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