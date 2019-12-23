#include <DxLib.h>
#include "SceneMgr.h"

#define RELEASE(x) { if((x) != nullptr){ delete (x); } (x) = nullptr; }

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
	
	Graphics* gr = new Graphics();
	Mouse* mos = new Mouse();
	DataFile* df = new DataFile();
	SceneMgr* smgr = new SceneMgr();
	Keyboard* key = new Keyboard();

	// ���b�Z�[�W���[�v
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