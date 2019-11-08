#include <Dxlib.h>
#include "map.h"

//--マップチップ割当内容--
//	0	:	空白(透明色)
//	1	:	地面
//	2	:	壁

int map_data[18][32]
{
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void drawMapChip(MapData Map,int sprite_handle)
{
	for (int Ver = 0; Ver < CHIP_MAX_Y; Ver++)
	{
		for (int Hor = 0; Hor < CHIP_MAX_X; Hor++)
		{
			DrawRectGraph((Map.draw_position_x + (CHIP_SIZE*Hor)), (Map.draw_position_y + (CHIP_SIZE*Ver)),
				CHIP_SRC_X + (CHIP_SIZE * map_data[Ver][Hor]), CHIP_SRC_Y, CHIP_SIZE, CHIP_SIZE, sprite_handle, true);
		}
	}
}

void setPlayerCollWithChip(MapData Map, Character* Player)
{

	Player->on_ground = false;
	//チップ当たり判定処理
	for (int Ver = 0; Ver < CHIP_MAX_Y; Ver++)
	{
		for (int Hor = 0; Hor < CHIP_MAX_X; Hor++)
		{
			int chip_left;
			int chip_right;
			int chip_top;
			int chip_bottom;
			int player_coll_left;
			int player_coll_right;
			int player_coll_top;
			int player_coll_bottom;

			if (map_data[Ver][Hor] > 0)
			{
				//マップチップ4点座標
				chip_left = Hor*CHIP_SIZE + Map.draw_position_x;
				chip_right = (Hor + 1)*CHIP_SIZE + Map.draw_position_x;
				chip_top = Ver*CHIP_SIZE + Map.draw_position_y;
				chip_bottom = (Ver + 1)*CHIP_SIZE + Map.draw_position_y;
				//プレイヤー当たり判定部4点座標
				player_coll_left = Player->x + PLAYER_COLL_LEFT;
				player_coll_right = Player->x + PLAYER_COLL_RIGHT;
				player_coll_top = Player->y + PLAYER_COLL_TOP;
				player_coll_bottom = Player->y + PLAYER_COLL_BOTTOM;

				if (player_coll_left < chip_right && player_coll_right > chip_left && player_coll_top < chip_bottom && player_coll_bottom > chip_top)
				{
					//縦方向の押し戻し
					if (Player->speed_y != 0)
					{
						if (Player->speed_y > 0)
						{
							if (player_coll_left < chip_right && player_coll_right > chip_left && player_coll_top+120 < chip_bottom && player_coll_bottom > chip_top)
							{
								//判定のあったチップの上方向にチップが存在しなければ処理を行う
								if (map_data[Ver - 1][Hor] == 0)
								{
									Player->y = chip_top - PLAYER_COLL_BOTTOM;
								}
							}
						}
						if (Player->speed_y < 0)
						{
							if (player_coll_left < chip_right && player_coll_right > chip_left && player_coll_top < chip_bottom && player_coll_bottom-120 > chip_top)
							{
								//判定のあったチップの下方向にチップが存在しなければ処理を行う
								if (map_data[Ver + 1][Hor] == 0)
								{
									Player->y = chip_bottom - PLAYER_COLL_TOP;
									Player->speed_y = 0;
								}
							}
						}
					}
				}
				//押し戻し後のプレイヤー座標を再取得
				player_coll_left = Player->x + PLAYER_COLL_LEFT;
				player_coll_right = Player->x + PLAYER_COLL_RIGHT;
				player_coll_top = Player->y + PLAYER_COLL_TOP;
				player_coll_bottom = Player->y + PLAYER_COLL_BOTTOM;

				if (player_coll_left < chip_right && player_coll_right > chip_left && player_coll_top < chip_bottom && player_coll_bottom > chip_top)
				{
					//横方向の押し戻し処理
					if (Player->speed_x != 0)
					{
						if (Player->speed_x > 0)
						{
							//判定のあったチップの左方向にチップが存在しなければ処理を行う
							if (map_data[Ver][Hor - 1] == 0)
							{
								Player->x = chip_left - PLAYER_COLL_RIGHT;
							}
						}
						if (Player->speed_x < 0)
						{
							//判定のあったチップの右方向にチップが存在しなければ処理を行う
							if (map_data[Ver][Hor + 1] == 0)
							{
								Player->x = chip_right - PLAYER_COLL_LEFT;
							}
						}
					}
				}
				//押し戻し後のプレイヤー座標を再取得
				player_coll_left = Player->x + PLAYER_COLL_LEFT;
				player_coll_right = Player->x + PLAYER_COLL_RIGHT;
				player_coll_top = Player->y + PLAYER_COLL_TOP;
				player_coll_bottom = Player->y + PLAYER_COLL_BOTTOM;

				//接地判定
				if (player_coll_bottom == chip_top && player_coll_right > chip_left && player_coll_left < chip_right)
				{
					Player->on_ground = true;
				}
			}
		}
	}
}
