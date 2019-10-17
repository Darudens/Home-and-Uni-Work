#pragma once

namespace olc
{
	class Sprite;
}

class ThePredator
{
public:
	ThePredator();
	~ThePredator();
public:
	int HP;
	float speed;
	float PredatorPositionY;
	float PredatorPositionX;
	olc::Sprite *PredatorSprite;
};

