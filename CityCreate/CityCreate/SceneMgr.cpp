#include "SceneMgr.h"

SceneMgr::SceneMgr()
{
	this->mpScene	 = new DrawScene();
	this->preScene	 = this->mpScene->GetNowScene();
}

SceneMgr::~SceneMgr()
{
	RELEASE(this->mpScene);
}

void SceneMgr::ChangeScene()
{
	RELEASE(this->mpScene);

	switch (this->mpScene->GetNowScene())
	{
	case SName::eSetScene:
		this->mpScene = new SetScene();
		break;
	case SName::eDrawScene:
		this->mpScene = new DrawScene();
		break;
	default:
		break;
	}
}

void SceneMgr::SceneUpdate()
{
	this->preScene = this->mpScene->GetNowScene();
	this->mpScene->Update();
	if (this->preScene != this->mpScene->GetNowScene())
	{
		this->ChangeScene();
	}
}

void SceneMgr::SceneDraw()
{
	this->mpScene->Draw();
}