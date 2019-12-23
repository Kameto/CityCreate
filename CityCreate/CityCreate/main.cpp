#include <DxLib.h>
#include "SceneMgr.h"

#define RELEASE(x) { if((x) != nullptr){ delete (x); } (x) = nullptr; }

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
	
	Graphics* gr = new Graphics();
	Mouse* mos = new Mouse();
	DataFile* df = new DataFile();
	SceneMgr* smgr = new SceneMgr();
	Keyboard* key = new Keyboard();

	// メッセージループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_END) == 0)
	{
		ClearDrawScreen();
		key->KeyUpdate();
		mos->Update();
		smgr->SceneUpdate();
		smgr->SceneDraw();
		ScreenFlip();
	}
	RELEASE(key);
	RELEASE(smgr);
	RELEASE(df);
	RELEASE(mos);
	RELEASE(gr);

	InitGraph();
	DxLib_End();

	return 0;
}