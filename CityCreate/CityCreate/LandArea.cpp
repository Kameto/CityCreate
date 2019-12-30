#include "LandArea.h"

LandArea::LandArea()
	: BaseArea()
{
	wSize = hSize = 0;
	wSize = hSize = 1;
	this->AreaSet(wSize, hSize, 512);
}

LandArea::LandArea(int _x, int _y)
	: BaseArea(_x, _y)
{
	wSize = hSize = 0;
	wSize = (MyRand::GetRand() % 10) + 1;
	hSize = (MyRand::GetRand() % 10) + 1;
	this->AreaSet(wSize, hSize, 512);
}

LandArea::LandArea(int _x, int _y, int _range)
	: BaseArea(_x, _y)
{
	wSize = hSize = 0;
	wSize = (MyRand::GetRand() % 10) + 1;
	hSize = (MyRand::GetRand() % 10) + 1;
	this->AreaSet(wSize, hSize, _range);
}

LandArea::~LandArea()
{

}

void LandArea::Draw()
{
	// エリア表示
	DrawBox(acp[0] - (this->range / 2), acp[1] - (this->range / 2), acp[0] + (this->range / 2), acp[1] + (this->range / 2), 0xFF00F0, true);
	DrawBoxAA(acp[0] - (this->range / 2), acp[1] - (this->range / 2), acp[0] + (this->range / 2), acp[1] + (this->range / 2), 0xFFFFFF, false, 5.0f);

	// タグ表示
	switch (this->AreaTag)
	{
	case AreaSize::mAS_NULL:
		DrawExtendFormatString(acp[0] - (this->range / 4), acp[1], 1.0, 1.0, 0xFFFFFF, "%s", ESTRING(mAS_NULL));
		break;
	case AreaSize::mSmall:
		DrawExtendFormatString(acp[0] - (this->range / 4), acp[1], 1.0, 1.0, 0xFFFFFF, "%s", ESTRING(mSmall));
		break;
	case AreaSize::mModerate:
		DrawExtendFormatString(acp[0] - (this->range / 4), acp[1], 1.0, 1.0, 0xFFFFFF, "%s", ESTRING(mModerate));
		break;
	case AreaSize::mLarge:
		DrawExtendFormatString(acp[0] - (this->range / 4), acp[1], 1.0, 1.0, 0xFFFFFF, "%s", ESTRING(mLarge));
		break;
	default:
		break;
	}
}