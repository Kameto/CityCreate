#pragma once
#include "Keyboard.h"
#include "Mouse.h"
#include "MyRand.h"

#define RELEASE(x) { if((x) != nullptr){ delete (x); (x) = nullptr; } }

typedef enum class SceneName
{
	eSetScene,
	eDrawScene
}SName;

class BaseScene
{
public:
	BaseScene() {};
	virtual ~BaseScene()	 = 0;
	virtual void Update()	 = 0;
	virtual void Draw()		 = 0;
	static SceneName GetNowScene();

protected:
	virtual void UI_Update() = 0;
	virtual void UI_Draw() = 0;

	static SceneName nowScene;
};