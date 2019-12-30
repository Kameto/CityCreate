#pragma once
#include "BaseScene.h"
#include "LandArea.h"

class DrawScene :
	public BaseScene
{
public:
	DrawScene();
	~DrawScene();
	void Update();
	void Draw();

protected:
	void UI_Update();
	void UI_Draw();


private:
	vector<LandArea*> land;
};