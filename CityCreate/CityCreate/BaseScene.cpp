#include "BaseScene.h"

SceneName BaseScene::nowScene = SceneName::eSetScene;

SceneName BaseScene::GetNowScene()
{
	return BaseScene::nowScene;
}