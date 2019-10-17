#include "ThePredator.h"
#include "olcPixelGameEngine.h"



ThePredator::ThePredator()
{
	PredatorSprite = new olc::Sprite("ThePredatorSprite.png");
	speed = 50;
	PredatorPositionX = 595;
	PredatorPositionY = 0;
}


ThePredator::~ThePredator()
{
}
