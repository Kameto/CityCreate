#include "BaseArea.h"

void BaseArea::AreaSet(int _wid, int _hei, int _size)
{
	range = _size;
	width = _wid * this->range;
	height = _hei * this->range;
	ASize wTag, hTag;
	if (_wid <= 1) { wTag = ASize::mSmall; }
	else if (_wid >= 2 && _wid <= 5) { wTag = ASize::mModerate; }
	else { wTag = ASize::mLarge; }

	if (_hei <= 1) { hTag = ASize::mSmall; }
	else if (_hei >= 2 && _hei <= 5) { hTag = ASize::mModerate; }
	else { hTag = ASize::mLarge; }

	if (hTag > wTag) { AreaTag = hTag; }
	else if (hTag < wTag) { AreaTag = wTag; }
	else { AreaTag = hTag; }
};