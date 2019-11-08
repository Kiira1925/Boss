#include <DxLib.h>
#include "player.h"

void drawPlayer(Character* Player, int sprite_handle)
{
	if (Player->attack_state == None && Player->on_ground == true)
	{
		if (Player->speed_x == 0)
		{
			Player->anime_frame_num = (Player->anime_timer % 40) / 10;
			if (Player->direction == Right) { DrawRectGraph(Player->x, Player->y, PLAYER_SRC_X + (PLAYER_WIDTH*Player->anime_frame_num), PLAYER_SRC_Y, PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE); }
			if (Player->direction == Left) { DrawRectGraph(Player->x, Player->y, PLAYER_SRC_X + (PLAYER_WIDTH*Player->anime_frame_num), PLAYER_SRC_Y, PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE, TRUE); }
		}
		if (Player->speed_x > 0)
		{
			Player->anime_frame_num = (Player->anime_timer % 30) / 10;
			DrawRectGraph(Player->x, Player->y, PLAYER_SRC_X + (PLAYER_WIDTH*Player->anime_frame_num), PLAYER_SRC_Y+128, PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE);
		}
		if (Player->speed_x < 0)
		{
			Player->anime_frame_num = (Player->anime_timer % 30) / 10;
			DrawRectGraph(Player->x, Player->y, PLAYER_SRC_X + (PLAYER_WIDTH*Player->anime_frame_num), PLAYER_SRC_Y + 128, PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE, TRUE);
		}
	}

	if (Player->on_ground == false)
	{
		if (Player->speed_y < 0)
		{
			DrawRectGraph(Player->x, Player->y, PLAYER_SRC_X, 316, PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE);
		}
		else
		{
			DrawRectGraph(Player->x, Player->y, PLAYER_SRC_X + PLAYER_WIDTH, 316, PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE);
		}
	}

	Player->anime_timer++;
}

void movePlayer(Character* Player)
{
	Player->speed_x = 0;

	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		Player->speed_x = PLAYER_SPEED_MAX;
		Player->direction = Right;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		Player->speed_x = -PLAYER_SPEED_MAX;
		Player->direction = Left;
	}

	if (Player->speed_x > 50) { Player->speed_x = 50; }
	if (Player->speed_y > 50) { Player->speed_y = 50; }
	Player->x += Player->speed_x;
	Player->y += Player->speed_y;
}

void exeJump(Character* Player, int gravity, bool checkPressButton)
{
	//通常ジャンプ
	if (checkPressButton && Player->on_ground == true && Player->jump_flag == false)
	{
		Player->jump_flag = true;
		Player->jump_pow = PLAYER_JUMP_POW_MAX;
		Player->speed_y -= Player->jump_pow;
	}
	//空中ジャンプ
	if (checkPressButton && Player->on_ground == false && Player->air_jump_flag == false)
	{
		Player->air_jump_flag = true;
		Player->jump_pow = PLAYER_JUMP_POW_MAX;
		Player->speed_y = 0;
		Player->speed_y -= Player->jump_pow;
	}

	if (Player->on_ground == true)
	{
		Player->jump_flag = false;
		Player->air_jump_flag = false;
		Player->jump_timer = 0;
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