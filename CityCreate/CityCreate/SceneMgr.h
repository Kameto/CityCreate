#pragma once
#include "DrawScene.h"
#include "SetScene.h"

class SceneMgr
{
public:
	SceneMgr();
	~SceneMgr();
	void ChangeScene();
	void SceneUpdate();
	void SceneDraw();

private:
	BaseScene* mpScene;
	SName preScene;
};