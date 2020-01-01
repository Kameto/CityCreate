#pragma once
#include "BaseArea.h"
class RentalArea :
	public BaseArea
{
public:
	RentalArea();
	RentalArea(int,int,int);
	~RentalArea();
	void Draw();
};