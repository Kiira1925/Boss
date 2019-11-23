#include <DxLib.h>
#include "shot.h"

void calTalisman(Bullet* PlayerShot)
{
	for (int i = 0; i < 5; i++)
	{
		if ((PlayerShot + i)->exist)
		{
			(PlayerShot + i)->cal_x = (PlayerShot + i)->speed_x;
			(PlayerShot + i)->x += static_cast<int>((PlayerShot + i)->speed_x);

			(PlayerShot + i)->coll_top		= (PlayerShot + i)->y + P_TALISMAN_COLL_TOP;
			(PlayerShot + i)->coll_bottom	= (PlayerShot + i)->y + P_TALISMAN_COLL_BOTTOM;
			(PlayerShot + i)->coll_right	= (PlayerShot + i)->x + P_TALISMAN_COLL_RIGHT;
			(PlayerShot + i)->coll_left		= (PlayerShot + i)->x + P_TALISMAN_COLL_LEFT;
		}

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
			if(PlayerShot[i].direction==1) { DrawTurnGraph(PlayerShot[i].x, PlayerShot[i].y, bullet_handle, true); }
		}
	}
}