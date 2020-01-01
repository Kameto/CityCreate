#include <DxLib.h>
#include "Keyboard.h"
#include "Mouse.h"
#include "SceneMgr.h"
#include "MyRand.h"

int _stdcall WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	SetMainWindowText("StageCreater");			// �A�v���P�[�V������

	SetOutApplicationLogValidFlag(false);		// log�t�@�C���̐���
#ifdef _DEBUG
	ChangeWindowMode(true);						// �X�N���[���ݒ�
#else
	ChangeWindowMode(false);					// �X�N���[���ݒ�
#endif

	SetGraphMode(1920, 1080, 32);				// �`��͈�
	SetFontSize(16);							// �����T�C�Y�ݒ�
	if (DxLib_Init() == -1)						// Dx���C�u�����̏�����
	{
		return -1;
	}
	if (SetDrawScreen(DX_SCREEN_BACK) == -1)	// �w�i�`��ݒ�
	{
		return -1;
	}
	SetMouseDispFlag(true);
	
	Mouse* mos = new Mouse();
	SceneMgr* smgr = new SceneMgr();
	Keyboard* key = new Keyboard();
	MyRand* rnd = new MyRand();

	// ���b�Z�[�W���[�v
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