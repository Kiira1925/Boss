#include <DxLib.h>
#include "boss.h"
#include "player.h"

void drawBoss(Enemy* Boss, int boss_handle, int shake_power_x, int shake_power_y)
{
	if (Boss->boss_attack_state == No && Boss->on_ground == true)
	{
		Boss->anime_frame_num = (Boss->anime_timer % 40) / 10;
		DrawRectGraph(Boss->x + shake_power_x, Boss->y + shake_power_y, BOSS_SRC_X + (BOSS_WIDTH*Boss->anime_frame_num), BOSS_SRC_Y, BOSS_WIDTH, BOSS_HEIGHT, boss_handle, TRUE, Boss->direction);
	}

	if (Boss->on_ground == false)
	{
		if (Boss->speed_y < 0)
		{
			DrawRectGraph(Boss->x + shake_power_x, Boss->y + shake_power_y, 576, 636, BOSS_WIDTH, BOSS_HEIGHT, boss_handle, TRUE);
		}
		if (Boss->speed_y < 0)
		{
			DrawRectGraph(Boss->x + shake_power_x, Boss->y + shake_power_y, 768, 636, BOSS_WIDTH, BOSS_HEIGHT, boss_handle, TRUE);
		}
	}

	Boss->anime_timer++;
}

void moveBoss(Character Player, Enemy* Boss)
{
	Boss->speed_x = 0;

	if (CheckHitKey(KEY_INPUT_D))
	{
		Boss->direction = TRUE;  //プレイヤーがボスより右にいたらボスは右を向く
		Boss->speed_x = BOSS_SPEED_MAX;
	}

	if (CheckHitKey(KEY_INPUT_A))
	{
		Boss->direction = FALSE; //プレイヤーがボスより左にいたらボスは左を向く
		Boss->speed_x = -BOSS_SPEED_MAX;
	}

	if (Boss->speed_x > 50) { Boss->speed_x = 50; }
	if (Boss->speed_y > 50) { Boss->speed_y = 50; }
	Boss->x += Boss->speed_x;
	Boss->y += Boss->speed_y;
}

void exeJump(Enemy* Boss, int gravity, bool checkPressButton)
{
	//通常ジャンプ
	if (checkPressButton && Boss->on_ground == true && Boss->jump_flag == false)
	{
		Boss->jump_flag = true;
		Boss->jump_pow = BOSS_JUMP_POW_MAX;
		Boss->speed_y -= Boss->jump_pow;
	}
	//空中ジャンプ
	if (checkPressButton && Boss->on_ground == false && Boss->air_jump_flag == false)
	{
		Boss->air_jump_flag = true;
		Boss->jump_pow = BOSS_JUMP_POW_MAX;
		Boss->speed_y = 0;
		Boss->speed_y -= Boss->jump_pow;
	}

	if (Boss->on_ground == true)
	{
		Boss->jump_flag = false;
		Boss->air_jump_flag = false;
		Boss->jump_timer = 0;
	}
}

void affectGravity(Enemy* Boss, int gravity)
{
	if (Boss->on_ground == false && Boss->x <= 1000)
	{
		Boss->speed_y += gravity;
	}

	if (Boss->speed_y > 100)
	{
		Boss->speed_y = 100;
	}
	if (Boss->on_ground == true)
	{
		Boss->speed_y = 0;
	}
}

//
//void boss_attack(Character* Player, Enemy* Boss)
//{
//    switch (Boss->boss_attack_state)
//    {
//    case 0:
//
//
//    }
//}