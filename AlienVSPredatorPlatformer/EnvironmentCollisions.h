#pragma once
class EnvironmentCollisions : public olc::PixelGameEngine
{
public:
	EnvironmentCollisions();
	~EnvironmentCollisions();
public:
	int StartingPositionX;
	int StartingPositionY;
	int width;
	int height;
	olc::Pixel colour;
};

