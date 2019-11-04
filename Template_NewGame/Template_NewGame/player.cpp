#include <DxLib.h>
#include "player.h"

void drawPlayer(Character* Player,int sprite_handle)
{
	if (Player->attack_state == None && Player->on_ground == true)
	{
		DrawRectGraph(Player->x, Player->y, PLAYER_SRC_X+(PLAYER_WIDTH*Player->anime_frame_num), PLAYER_SRC_Y, PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE);
	}

	if (Player->on_ground == false)
	{
		DrawRectGraph(Player->x, Player->y, PLAYER_SRC_X, 316, PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE);
	}

	Player->anime_frame_num = (Player->anime_timer % 30) / 10;
	Player->anime_timer++;
}

void movePlayer(Character* Player)
{
	Player->speed_x = 0;

	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		Player->speed_x = PLAYER_SPEED_MAX;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		Player->speed_x = -PLAYER_SPEED_MAX;
	}

	if (Player->speed_x > 50) { Player->speed_x = 50; }
	if (Player->speed_y > 50) { Player->speed_y = 50; }
	Player->x += Player->speed_x;
	Player->y += Player->speed_y;
}

void exeJump(Character* Player,int gravity)
{
	if (CheckHitKey(KEY_INPUT_SPACE) && Player->on_ground == true && Player->jump_flag == false)
	{
		Player->jump_flag = true;
		Player->jump_pow = PLAYER_JUMP_POW_MAX;
		Player->speed_y -= Player->jump_pow;
	}
	//Player->speed_y = (-Player->jump_pow) + gravity;

	//if (Player->jump_pow >= 0)
	//{
	//	Player->jump_pow -= PLAYER_DECAY_JUMP_POW;
	//}

	if (Player->speed_y > 0 && Player->jump_flag == true)
	{
		Player->jump_flag = false;
		//Player->jump_pow = 0;
	}
}

void affectGravity(Character* Player, int gravity)
{
	if (Player->on_ground == false)
	{
		Player->speed_y += gravity;
	}

	if (Player->speed_y > 100)
	{
		Player->speed_y = 100;
	}
	if (Player->on_ground == true)
	{
		Player->speed_y = 0;
	}
}