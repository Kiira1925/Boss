#pragma once
//インクルード

//定数定義
#define CHIP_SIZE		(60)
#define CHIP_SRC_X		(0)
#define CHIP_SRC_Y		(0)
#define CHIP_MAX_X		(32)
#define CHIP_MAX_Y		(18)

//構造体定義
struct MapData
{
	int draw_position_x;
	int draw_position_y;
};

//プロトタイプ宣言
void drawMapChip(MapData Map, int sprite_handle);
