#include <DxLib.h>
#include "shot.h"
#include "math.h"

void calTalisman(Bullet* PlayerShot)
{
	for (int i = 0; i < 5; i++)
	{
		if ((PlayerShot + i)->exist)
		{
			//–³Ž‹‚ÅOK
			(PlayerShot + i)->cal_x = (PlayerShot + i)->speed;
			//ŒvŽZ‚Ì“s‡ãfloat‚Å‘¬“x‚ðŽæ‚Á‚Ä‚¢‚é‚Ì‚ÅAintŒ^‚É•ÏŠ·‚µ‚ÄƒvƒŒƒCƒ„[‚ÌÀ•W‚É‰ÁŽZ
			(PlayerShot + i)->x += static_cast<int>((PlayerShot + i)->speed);

			//’e‚Ì“–‚½‚è”»’è
			(PlayerShot + i)->coll_top		= (PlayerShot + i)->y + P_TALISMAN_COLL_TOP;
			(PlayerShot + i)->coll_bottom	= (PlayerShot + i)->y + P_TALISMAN_COLL_BOTTOM;
			(PlayerShot + i)->coll_right	= (PlayerShot + i)->x + P_TALISMAN_COLL_RIGHT;
			(PlayerShot + i)->coll_left		= (PlayerShot + i)->x + P_TALISMAN_COLL_LEFT;
		}

		//’e‚Ì‘¶Ýƒtƒ‰ƒO‚ªÜ‚ê‚½ê‡AƒQ[ƒ€‚ÉŠ±Â‚µ‚È‚¢‰æ–ÊŠO‚ÌÀ•W‚É’e‚ð‰B‚·
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

//‘S•ûŒü‘Î‰ž’e‚Ì•`‰æŠÖ”
void drawTest(Bullet* Test, int testB_handle)
{
	Test->x = static_cast <int>(Test->cal_x);
	Test->y = static_cast <int>(Test->cal_y);

	DrawRotaGraph(Test->x, Test->y,1,-Test->angle*(3.1415926535 / 180), testB_handle, TRUE);
}

//‘S•ûŒü‘Î‰ž’e‚ÌˆÚ“®ƒeƒXƒg—pŠÖ”
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