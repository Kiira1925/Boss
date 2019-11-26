#include <DxLib.h>
#include "gimmick.h"
#include "map.h"
#include "player.h"
#include "shot.h"

void drawShootRange(int shootrange_handle, int target_handle, int gate_handle, Gimmick Shooting[2])
{
	DrawGraph(Shooting[0].gate_x, Shooting[0].gate_y, gate_handle, TRUE);
	DrawGraph(Shooting[0].range_x, Shooting[0].range_y, shootrange_handle, TRUE);
	if (!Shooting[0].hit) { DrawRectGraph(Shooting[0].target_x, Shooting[0].target_y, 0, 0, 60, 60, target_handle, TRUE); }
	else { DrawRectGraph(Shooting[0].target_x, Shooting[0].target_y, 60, 0, 60, 60, target_handle, TRUE); }
}

void collShootRange(Character* Player, Gimmick* Shooting, Bullet* PlayerShot,MapData Map)
{
	//スクロール
	Shooting->range_x = ABS_SHOOTRANGE_POS_X + Map.draw_position_x;
	Shooting->target_x = ABS_TARGET_POS_X + Map.draw_position_x;
	Shooting->gate_x = ABS_GATE_POS_X + Map.draw_position_x;

	////シュートレンジの上部分
	//縦
	if (Shooting->range_x < Player->x + PLAYER_COLL_RIGHT && Shooting->range_x + SHOOTRANGE_WIDTH > Player->x + PLAYER_COLL_LEFT &&
		Shooting->range_y < Player->y + PLAYER_COLL_BOTTOM && Shooting->range_y + 30 > Player->y + PLAYER_COLL_TOP)
	{
		if (Player->speed_y > 0) { Player->y = Shooting->range_y - PLAYER_COLL_BOTTOM; }
	}
	//横
	if (Shooting->range_x < Player->x + PLAYER_COLL_RIGHT && Shooting->range_x + SHOOTRANGE_WIDTH > Player->x + PLAYER_COLL_LEFT &&
		Shooting->range_y < Player->y + PLAYER_COLL_BOTTOM && Shooting->range_y + 30 > Player->y + PLAYER_COLL_TOP)
	{
		if (Player->speed_x > 0) { Player->x = Shooting->range_x - PLAYER_COLL_RIGHT; }
		if (Player->speed_x < 0) { Player->x = Shooting->range_x + SHOOTRANGE_WIDTH - PLAYER_COLL_LEFT; }
	}

	////シュートレンジの下部分
	//縦
	if (Shooting->range_x < Player->x + PLAYER_COLL_RIGHT && Shooting->range_x + SHOOTRANGE_WIDTH > Player->x + PLAYER_COLL_LEFT &&
		Shooting->range_y+90 < Player->y + PLAYER_COLL_BOTTOM && Shooting->range_y + SHOOTRANGE_HEIGHT > Player->y + PLAYER_COLL_TOP)
	{
		if (Player->speed_y < 0)
		{
			Player->y = Shooting->range_y+SHOOTRANGE_HEIGHT - PLAYER_COLL_TOP;
			Player->speed_y = 0;
		}
	}
	//横
	if (Shooting->range_x < Player->x + PLAYER_COLL_RIGHT && Shooting->range_x + SHOOTRANGE_WIDTH > Player->x + PLAYER_COLL_LEFT &&
		Shooting->range_y + 90 < Player->y + PLAYER_COLL_BOTTOM && Shooting->range_y + SHOOTRANGE_HEIGHT > Player->y + PLAYER_COLL_TOP)
	{
		if (Player->speed_x > 0) { Player->x = Shooting->range_x - PLAYER_COLL_RIGHT; }
		if (Player->speed_x < 0) { Player->x = Shooting->range_x + SHOOTRANGE_WIDTH - PLAYER_COLL_LEFT; }
	}

	////ゲート
	//横
	if (Shooting->gate_x < Player->x + PLAYER_COLL_RIGHT && Shooting->gate_x + GATE_WIDTH > Player->x + PLAYER_COLL_LEFT &&
		Shooting->gate_y + 90 < Player->y + PLAYER_COLL_BOTTOM && Shooting->gate_y + GATE_HEIGHT > Player->y + PLAYER_COLL_TOP)
	{
		if (Player->speed_x > 0) { Player->x = Shooting->gate_x - PLAYER_COLL_RIGHT; }
		if (Player->speed_x < 0) { Player->x = Shooting->gate_x + GATE_WIDTH - PLAYER_COLL_LEFT; }
	}
	//縦
	if (Shooting->gate_x < Player->x + PLAYER_COLL_RIGHT && Shooting->gate_x + GATE_WIDTH > Player->x + PLAYER_COLL_LEFT &&
		Shooting->gate_y + 90 < Player->y + PLAYER_COLL_BOTTOM && Shooting->gate_y + GATE_HEIGHT > Player->y + PLAYER_COLL_TOP)
	{
		if (Player->speed_y < 0)
		{
			Player->y = Shooting->gate_y + GATE_HEIGHT - PLAYER_COLL_TOP;
			Player->speed_y = 0;
		}
	}

	//弾の当たり判定
	for (int i = 0; i<5; i++)
	{
		if ((PlayerShot + i)->exist)
		{
			//シュートレンジとの当たり判定
			if (Shooting->range_x < (PlayerShot + i)->coll_right && Shooting->range_x + SHOOTRANGE_WIDTH >(PlayerShot + i)->coll_left &&
				Shooting->range_y < (PlayerShot + i)->coll_bottom && Shooting->range_y + 30 >(PlayerShot + i)->coll_top ||
				Shooting->range_x < (PlayerShot + i)->coll_right && Shooting->range_x + SHOOTRANGE_WIDTH >(PlayerShot + i)->coll_left &&
				Shooting->range_y + 90 < (PlayerShot + i)->coll_bottom && Shooting->range_y + SHOOTRANGE_HEIGHT > (PlayerShot + i)->coll_top)
			{
				(PlayerShot + i)->exist = false;
			}
			//的との当たり判定
			if (Shooting->target_x < (PlayerShot + i)->coll_right && Shooting->target_x + 60 >(PlayerShot + i)->coll_left &&
				Shooting->target_y < (PlayerShot + i)->coll_bottom && Shooting->target_y + 60 >(PlayerShot + i)->coll_top)
			{
				Shooting->hit = true;
				(PlayerShot + i)->exist = false;
			}
		}
	}

	if (Shooting->hit)
	{
		if (Shooting->gate_y > -GATE_HEIGHT) { Shooting->gate_y -= 5; }
		if (Shooting->gate_y < -GATE_HEIGHT) { Shooting->gate_y = -GATE_HEIGHT; }
	}

	if (Player->y + PLAYER_COLL_BOTTOM == Shooting->range_y && Player->x + PLAYER_COLL_RIGHT > Shooting->range_x && Player->x + PLAYER_COLL_TOP < Shooting->range_x + SHOOTRANGE_WIDTH)
	{
		Player->on_ground = true;
	}
}