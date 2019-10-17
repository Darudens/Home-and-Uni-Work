#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "ThePredator.h"

class AlienVsPredator : public olc::PixelGameEngine
{
public:
	AlienVsPredator()
	{
		sAppName = "Alien VS Predator";
		SetPixelMode(olc::Pixel::MASK);
	}
public:
	bool OnUserCreate() override
	{
		BackGround = new olc::Sprite("Jungle.jpg");
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		DrawSprite(0, 0, BackGround, 1);
		DrawPartialSprite(0, 0, NewPredator.PredatorSprite, 630, 92, 155, 75, 1);
		DrawPartialSprite
		(
			NewPredator.PredatorPositionY,
			NewPredator.PredatorPositionX,
			NewPredator.PredatorSprite,
			13, 111, 66, 111, 1
		);
		DrawRect(0, 700, 1280, 20, olc::BLUE);
		Movement(fElapsedTime, &NewPredator.PredatorPositionX, &NewPredator.PredatorPositionY, NewPredator.speed, NewPredator.PredatorSprite);
		return true;
	}

	ThePredator NewPredator;
	olc::Sprite *BackGround;

	void Movement(float tick, float *positionY, float *positionX, float speed, olc::Sprite *sprite)
	{
		if (GetKey(olc::Key::W).bHeld)
			*positionY -= speed * tick;
		if (GetKey(olc::Key::S).bHeld)
			*positionY += speed * tick;
		if (GetKey(olc::Key::D).bHeld)
			*positionX += speed * tick;
		if (GetKey(olc::Key::A).bHeld)
			*positionX -= speed * tick;
	}
};

int main()
{
	AlienVsPredator Testing;
	if (Testing.Construct(1280, 720, 1, 1))
		Testing.Start();
	return 0;
}