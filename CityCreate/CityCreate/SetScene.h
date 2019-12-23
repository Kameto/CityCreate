#pragma once
#include "BaseScene.h"
class SetScene :
	public BaseScene
{
public:
	SetScene();
	~SetScene();
	void Update();
	void Draw();

protected:
	void UI_Update();
	void UI_Draw();

private:
	int mapWidth;
	int mapHeight;
};