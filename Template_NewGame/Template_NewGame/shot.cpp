#include <DxLib.h>
#include "shot.h"
#include "math.h"

void calTalisman(Bullet* PlayerShot)
{
	for (int i = 0; i < 5; i++)
	{
		if ((PlayerShot + i)->exist)
		{
			//無視でOK
			(PlayerShot + i)->cal_x = (PlayerShot + i)->speed;
			//計算の都合上floatで速度を取っているので、int型に変換してプレイヤーの座標に加算
			(PlayerShot + i)->x += static_cast<int>((PlayerShot + i)->speed);

			//弾の当たり判定
			(PlayerShot + i)->coll_top		= (PlayerShot + i)->y + P_TALISMAN_COLL_TOP;
			(PlayerShot + i)->coll_bottom	= (PlayerShot + i)->y + P_TALISMAN_COLL_BOTTOM;
			(PlayerShot + i)->coll_right	= (PlayerShot + i)->x + P_TALISMAN_COLL_RIGHT;
			(PlayerShot + i)->coll_left		= (PlayerShot + i)->x + P_TALISMAN_COLL_LEFT;
		}

		//弾の存在フラグが折れた場合、ゲームに干渉しない画面外の座標に弾を隠す
		if (!(PlayerShot + i)->exist)
		{
			(PlayerShot + i)->x = (PlayerShot + i)->y = -500;
		}
	}
}

void drawTalisman(Bullet PlayerShot[5],int bullet_handle)
{
	for (int i = 0; i < 5; i++)
	{
		if (PlayerShot[i].exist)
		{
			if (PlayerShot[i].direction == 0) { DrawGraph(PlayerShot[i].x, PlayerShot[i].y, bullet_handle, true); }
			if(PlayerShot[i].direction == 1) { DrawTurnGraph(PlayerShot[i].x, PlayerShot[i].y, bullet_handle, true); }
		}
	}
}

//全方向対応弾の描画関数
void drawTest(Bullet* Test, int testB_handle)
{
	Test->x = static_cast <int>(Test->cal_x);
	Test->y = static_cast <int>(Test->cal_y);

	DrawRotaGraph(Test->x, Test->y,1,-Test->angle*(3.1415926535 / 180), testB_handle, TRUE);
}

//全方向対応弾の移動テスト用関数
void calTest(Bullet* Test, float fsin[360],float fcos[360])
{
	if (CheckHitKey(KEY_INPUT_J)) { Test->angle -= 5; }
	if (CheckHitKey(KEY_INPUT_L)) { Test->angle += 5; }
	if (CheckHitKey(KEY_INPUT_I)) { Test->speed = 10; }
	else { Test->speed = 0; }
	if (Test->angle >= 360) { Test->angle -= 360; }
	if (Test->angle < 0) { Test->angle += 360; }

	Test->cal_x += fcos[Test->angle] * Test->speed;
	Test->cal_y -= fsin[Test->angle] * Test->speed;
}