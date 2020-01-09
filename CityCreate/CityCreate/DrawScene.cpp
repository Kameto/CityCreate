#include "DrawScene.h"

DrawScene::DrawScene()
{
	land.push_back(new LandArea(256, 256, 512));
}

DrawScene::~DrawScene()
{
	if (!land.empty())
	{
		for (int i = 0, n = (unsigned)land.size(); i < n; i++)
		{
			RELEASE(land.at(i));
		}
		land.erase(land.begin(), land.end());
	}
	land.shrink_to_fit();
}

void DrawScene::Update()
{
	this->UI_Update();
}

void DrawScene::Draw()
{
	if (!land.empty())
	{
		for (int i = 0, n = (unsigned)land.size(); i < n; i++)
		{
			land.at(i)->Draw();
		}
	}
	this->UI_Draw();
}

void DrawScene::UI_Update()
{
	if (Keyboard::GetKey(KEY_INPUT_A) == 1)
	{
		int num = (unsigned)land.size();
		land.push_back(new LandArea(256 + (num * land.at(0)->range), 256, land.at(0)->range));
	}
}

void DrawScene::UI_Draw()
{
	DrawFormatString(1600, 0, 0xFFFFFF, _T("Enter Key => SetScene"));
	DrawFormatString(1600, 32, 0xFFFFFF, _T("A Key => push_back"));
}