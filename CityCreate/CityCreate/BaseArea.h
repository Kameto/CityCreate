#pragma once
#include <DxLib.h>
#include <string>
#include <vector>

#include "MyRand.h"

#define ESTRING(var) #var
#define RELEASE(x) { if((x) != nullptr){ delete (x); (x) = nullptr; } }

using namespace std;

typedef enum class AreaSize
{
	mAS_NULL,		// �����l
	mSmall,			// ���G���A
	mModerate,		// ���G���A
	mLarge,			// ��G���A
	SizeNum
}ASize;

class BaseArea
{
public:
	BaseArea()					// �R���X�g���N�^
	{
		AreaTag = ASize::mAS_NULL;
		acp[0] = acp[1] = 0;
		range = 0;
		width = 0;
		height = 0;
	};
	BaseArea(int _x, int _y)	// �����t���R���X�g���N�^
	{
		acp[0] = _x;
		acp[1] = _y;
		AreaTag = ASize::mAS_NULL;
		range = 0;
		width = 0;
		height = 0;
	}
	virtual ~BaseArea()			// �f�X�g���N�^
	{
		AreaTag = ASize::mAS_NULL;
		acp[0] = acp[1] = 0;
		range = 0;
		width = 0;
		height = 0;
	};
	virtual void Draw() = 0;	// �`��
	ASize AreaTag;				// �T�C�X�^�O
	int acp[2];					// �G���A�������W
	int range;					// �͈̓T�C�Y
	int width;					// ���T�C�Y
	int height;					// �c�T�C�Y

protected:
	void AreaSet(int,int,int);	// �y�n�ݒ�
};