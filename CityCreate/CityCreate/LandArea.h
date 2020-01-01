#pragma once
#include "BaseArea.h"
#include "RentalArea.h"

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
	vector<RentalArea*> rental;
};