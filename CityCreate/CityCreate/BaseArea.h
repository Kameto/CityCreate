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
	mAS_NULL,		// 初期値
	mSmall,			// 小エリア
	mModerate,		// 中エリア
	mLarge,			// 大エリア
	SizeNum
}ASize;

class BaseArea
{
public:
	BaseArea()					// コンストラクタ
	{
		AreaTag = ASize::mAS_NULL;
		acp[0] = acp[1] = 0;
		range = 0;
		width = 0;
		height = 0;
	};
	BaseArea(int _x, int _y)	// 引数付きコンストラクタ
	{
		acp[0] = _x;
		acp[1] = _y;
		AreaTag = ASize::mAS_NULL;
		range = 0;
		width = 0;
		height = 0;
	}
	virtual ~BaseArea()			// デストラクタ
	{
		AreaTag = ASize::mAS_NULL;
		acp[0] = acp[1] = 0;
		range = 0;
		width = 0;
		height = 0;
	};
	virtual void Draw() = 0;	// 描画
	ASize AreaTag;				// サイスタグ
	int acp[2];					// エリア中央座標
	int range;					// 範囲サイズ
	int width;					// 横サイズ
	int height;					// 縦サイズ

protected:
	void AreaSet(int,int,int);	// 土地設定
};