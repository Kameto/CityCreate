#include "LandArea.h"

LandArea::LandArea()
	: BaseArea()
{
	wSize = hSize = 0;
	wSize = hSize = 1;
	this->AreaSet(wSize, hSize, 512);
	for (int i = 0; i < 10; i++)
	{
		int _ren = MyRand::GetRand() % 10;
		if (i == 0)
		{
			this->rental.push_back(new RentalArea(this->acp[0] + (this->range / 2) - _ren, this->acp[1] + (this->range / 2) - _ren, _ren));
		}
		else
		{
			if (rental.at(i)->range + _ren >=  this->range)
			{
				this->rental.push_back(new RentalArea(this->acp[0] + (this->range) - _ren, this->acp[1] + (this->range / 2) - _ren, rental.at(i)->range + _ren));
			}
			else
			{
				this->rental.push_back(new RentalArea(this->acp[0] + (this->range / 2) - _ren, this->acp[1] + (this->range / 2) - _ren, rental.at(i)->range + _ren));
			}
		}
	}
}

LandArea::LandArea(int _x, int _y)
	: BaseArea(_x, _y)
{
	wSize = hSize = 0;
	wSize = (MyRand::GetRand() % 10) + 1;
	hSize = (MyRand::GetRand() % 10) + 1;
	this->AreaSet(wSize, hSize, 512);
	for (int i = 0; i < 10; i++)
	{
		this->rental.push_back(new RentalArea(_x, _y, this->range / 4));
	}
}

LandArea::LandArea(int _x, int _y, int _range)
	: BaseArea(_x, _y)
{
	wSize = hSize = 0;
	wSize = (MyRand::GetRand() % 10) + 1;
	hSize = (MyRand::GetRand() % 10) + 1;
	this->AreaSet(wSize, hSize, _range);
	for (int i = 0; i < 10; i++)
	{
		this->rental.push_back(new RentalArea(MyRand::GetRand() % 10, MyRand::GetRand() % 10, this->range / 4));
	}
}

LandArea::~LandArea()
{
	if (!rental.empty())
	{
		for (int i = 0, n = (unsigned) rental.size(); i < n; i++)
		{
			RELEASE(rental.at(i));
		}
		rental.erase(rental.begin(), rental.end());
	}
	rental.shrink_to_fit();
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

	if (!rental.empty())
	{
		for (int i = 0, n = (unsigned)rental.size(); i < n; i++)
		{
			rental.at(i)->Draw();

			DrawFormatString(1600, 128 +  i * 32, 0xFFFFFF, "%d = x : %d, y : %d", i, rental.at(i)->acp[0], rental.at(i)->acp[1]);
		}
	}


}