#pragma once
#include "BaseArea.h"

class LandArea
	: public BaseArea
{
public:
	LandArea();
	LandArea(int,int);
	LandArea(int,int,int);
	~LandArea();
	void Draw();

private:
	int wSize;
	int hSize;
};