#include <DxLib.h>
#include "Keyboard.h"
#include "Mouse.h"
#include "SceneMgr.h"
#include "MyRand.h"

int _stdcall WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	SetMainWindowText("StageCreater");			// アプリケーション名

	SetOutApplicationLogValidFlag(false);		// logファイルの生成
#ifdef _DEBUG
	ChangeWindowMode(true);						// スクリーン設定
#else
	ChangeWindowMode(false);					// スクリーン設定
#endif

	SetGraphMode(1920, 1080, 32);				// 描画範囲
	SetFontSize(16);							// 文字サイズ設定
	if (DxLib_Init() == -1)						// Dxライブラリの初期化
	{
		return -1;
	}
	if (SetDrawScreen(DX_SCREEN_BACK) == -1)	// 背景描画設定
	{
		return -1;
	}
	SetMouseDispFlag(true);
	
	Mouse* mos = new Mouse();
	SceneMgr* smgr = new SceneMgr();
	Keyboard* key = new Keyboard();
	MyRand* rnd = new MyRand();

	// メッセージループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_END) == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();
		key->KeyUpdate();
		mos->Update();
		smgr->SceneUpdate();
		smgr->SceneDraw();
		ScreenFlip();
	}
	RELEASE(rnd);
	RELEASE(key);
	RELEASE(smgr);
	RELEASE(mos);

	InitGraph();
	DxLib_End();

	return 0;
}