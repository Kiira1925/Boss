#pragma once
//インクルード

//定数定義
#define BG_WIDTH	(256)
#define BG_HEIGHT	(144)

//構造体定義
struct BackGround
{
	int x1, y1;
	int x2, y2;

	int tree_x, tree_y;
	int temple_x, temple_y;

	int scroll_speed;
};

//プロトタイプ宣言
struct MapData;
void drawBG(int bg_handle, int bg2_handle, MapData Map, BackGround BG);
void scrollBG(BackGround* BG);
void scrollTree(BackGround* BG, MapData Map);