#pragma once
//インクルード

//extern

//定数定義
#define DAMMY_WIDTH		(108)
#define DAMMY_HEIGHT	(108)

//構造体定義
struct ScareCrow
{
	int x, y;
	int hp;
};

//プロトタイプ宣言
struct MapData;
void drawScareCrow(ScareCrow dammy, MapData map, int dammy_handle,int shake_power);