#pragma once
//インクルード
#include "player.h"

//定数定義
#define SCREEN_WIDTH			(1920)
#define SCREEN_HEIGHT			(1080)
#define CHIP_SIZE				(60)
#define CHIP_SRC_X				(0)
#define CHIP_SRC_Y				(0)
#define CHIP_MAX_X				(32)
#define CHIP_MAX_Y				(18)
#define MAP_MOVE_AMOUNT			((-Map.draw_position_x) / 60)
#define SCREEN_CENTER			(1920/2)
#define MOVEABLE_RANGE_LEFT		(400)
#define MOVEABLE_RANGE_RIGHT	(SCREEN_WIDTH-400)
#define BG_DEST_LIMIT_RIGHT		(0)
#define BG_DEST_LIMIT_LEFT		(-256*60+1920)
#define BG_SCROLL_SPEED			(10)

//構造体定義
struct MapData
{
	int draw_position_x;
	int draw_position_y;
};

//プロトタイプ宣言
void drawMapChip(MapData Map, int sprite_handle);
void setPlayerCollWithChip(MapData Map, Character* Player);
void loadMap();
void moveMapChip(MapData* Map);
void scrollMapChip(MapData* Map, Character* Player);
void drawGate(int gate_handle);
