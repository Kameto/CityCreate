#include "RentalArea.h"

RentalArea::RentalArea()
	: BaseArea()
{

}

RentalArea::RentalArea(int _x, int _y, int _range)
	: BaseArea(_x, _y)
{
	this->AreaSet(_x, _y, _range);
}

RentalArea::~RentalArea()
{

}

void RentalArea::Draw()
{
	// ƒGƒŠƒA•\Ž¦
	DrawBox	 (acp[0] - (this->range / 2) + 4, acp[1] - (this->range / 2) + 4, acp[0] + (this->range / 2) - 4, acp[1] + (this->range / 2) - 4, 0xFF00F0, true);
	DrawBoxAA(acp[0] - (this->range / 2) + 4, acp[1] - (this->range / 2) + 4, acp[0] + (this->range / 2) - 4, acp[1] + (this->range / 2) - 4, 0xFFFFFF, false, 5.0f);
}