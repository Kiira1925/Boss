//#include <DxLib.h>
//#include "player.h"
//#include "scarecrow.h"
//
#include"system.h"
#include"main.h"

void drawPlayer(Character* Player, int sprite_handle, int shake_power)
{
	if (Player->attack_state == None && Player->on_ground == true)
	{
		if (Player->speed_x == 0)
		{
			Player->anime_frame_num = (Player->anime_timer % 40) / 10;
			if (Player->direction == Right) { DrawRectGraph(Player->x + shake_power, Player->y + shake_power, PLAYER_SRC_X + (PLAYER_WIDTH*Player->anime_frame_num), PLAYER_SRC_Y, PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE); }
			if (Player->direction == Left) { DrawRectGraph(Player->x + shake_power, Player->y - shake_power, PLAYER_SRC_X + (PLAYER_WIDTH*Player->anime_frame_num), PLAYER_SRC_Y, PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE, TRUE); }
		}
		if (Player->speed_x > 0)
		{
			Player->anime_frame_num = (Player->anime_timer % 30) / 10;
			DrawRectGraph(Player->x + shake_power, Player->y - shake_power, PLAYER_SRC_X + (PLAYER_WIDTH*Player->anime_frame_num), PLAYER_SRC_Y + PLAYER_HEIGHT, PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE);
		}
		if (Player->speed_x < 0)
		{
			Player->anime_frame_num = (Player->anime_timer % 30) / 10;
			DrawRectGraph(Player->x + shake_power, Player->y - shake_power, PLAYER_SRC_X + (PLAYER_WIDTH*Player->anime_frame_num), PLAYER_SRC_Y + PLAYER_HEIGHT, PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE, TRUE);
		}
	}
	if (Player->attack_state == GrAttack1)
	{
		if (Player->direction == Right)
		{
			if (Player->attack_timer < 5) { DrawRectGraph(Player->x + shake_power, Player->y + shake_power, PLAYER_SRC_X, (PLAYER_SRC_Y + PLAYER_HEIGHT * 3), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE); }
			else { DrawRectGraph(Player->x + shake_power, Player->y - shake_power, PLAYER_SRC_X + PLAYER_WIDTH, (PLAYER_SRC_Y + PLAYER_HEIGHT * 3), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE); }
		}
		if (Player->direction == Left)
		{
			if (Player->attack_timer < 5) { DrawRectGraph(Player->x + shake_power, Player->y - shake_power, PLAYER_SRC_X, (PLAYER_SRC_Y + PLAYER_HEIGHT * 3), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE, TRUE); }
			else { DrawRectGraph(Player->x + shake_power, Player->y - shake_power, PLAYER_SRC_X + PLAYER_WIDTH, (PLAYER_SRC_Y + PLAYER_HEIGHT * 3), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE, TRUE); }
		}
	}

	if (Player->on_ground == false)
	{
		if (Player->speed_y < 0)
		{
			if (Player->direction == Right) { DrawRectGraph(Player->x + shake_power, Player->y + shake_power, PLAYER_SRC_X + PLAYER_WIDTH, (PLAYER_SRC_Y + PLAYER_HEIGHT * 2), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE); }
			if (Player->direction == Left) { DrawRectGraph(Player->x + shake_power, Player->y + shake_power, PLAYER_SRC_X + PLAYER_WIDTH, (PLAYER_SRC_Y + PLAYER_HEIGHT * 2), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE, TRUE); }
		}
		//if (Player->speed_y >= -10 && Player->speed_y < 10)
		//{
		//	DrawRectGraph(Player->x + shake_power, Player->y + shake_power, PLAYER_SRC_X + PLAYER_WIDTH, (PLAYER_SRC_Y + PLAYER_HEIGHT * 2), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE);
		//}
		else
		{
			if (Player->direction == Right) { DrawRectGraph(Player->x + shake_power, Player->y + shake_power, PLAYER_SRC_X + PLAYER_WIDTH * 2, (PLAYER_SRC_Y + PLAYER_HEIGHT * 2), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE); }
			if (Player->direction == Left) { DrawRectGraph(Player->x + shake_power, Player->y + shake_power, PLAYER_SRC_X + PLAYER_WIDTH * 2, (PLAYER_SRC_Y + PLAYER_HEIGHT * 2), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE, TRUE); }

		}
	}

	Player->anime_timer++;
}

void movePlayer(Character* Player, bool now_performance, XINPUT_STATE X_input)
{
	if (!now_performance && Player->attack_state == None)
	{
		if (CheckHitKey(KEY_INPUT_RIGHT) || X_input.ThumbLX > 15000)
		{
			if (Player->speed_x < PLAYER_SPEED_MAX) { Player->speed_x += 3; }
			Player->direction = Right;
		}
		else if (CheckHitKey(KEY_INPUT_LEFT) || X_input.ThumbLX < -15000)
		{
			if (Player->speed_x > -PLAYER_SPEED_MAX) { Player->speed_x -= 3; }
			Player->direction = Left;
		}
		else { Player->speed_x = 0; }
	}

	if (Player->speed_x > 50) { Player->speed_x = 50; }
	if (Player->speed_y > 50) { Player->speed_y = 50; }
	Player->x += Player->speed_x;
	Player->y += Player->speed_y;
}

//affectGravityよりも後に実行する
void exeJump(Character* Player, int gravity, bool checkPressButton)
{
	//通常ジャンプ
	if (checkPressButton && Player->on_ground == true && Player->jump_flag == false && Player->attack_state == None)
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

void attackPlayer(Character* Player, bool checkPressAttack, bool now_performance)
{
	//攻撃一段目
	if (Player->attack_state == None && Player->on_ground && checkPressAttack)
	{
		Player->attack_state = GrAttack1;
		if (Player->direction == Right) { Player->speed_x = 20; }
		if (Player->direction == Left) { Player->speed_x = -20; }
	}
	if (Player->attack_state == GrAttack1)
	{
		if (Player->speed_x > 0) { Player->speed_x -= 2; }
		if (Player->speed_x < 0) { Player->speed_x += 2; }
		Player->x += Player->speed_x;
		Player->attack_timer++;
		if (Player->attack_timer > 15)
		{
			Player->attack_state = None;
			Player->attack_timer = 0;
		}
	}

	if (now_performance == true)
	{
		Player->attack_state = None;
		Player->attack_timer = 0;
		Player->speed_x = 0;
	}
}

void collPlayerAttack(Character Player, ScareCrow Dammy, bool* shake_screen,MapData Map)
{
	if (Player.attack_state == GrAttack1)
	{
		if (Player.direction == Right)
		{
			if (Player.x + PLAYER_ATTACK1_COLL_RIGHT> Dammy.x + Map.draw_position_x && Player.x + PLAYER_ATTACK1_COLL_LEFT< Dammy.x + DAMMY_WIDTH + Map.draw_position_x &&
				Player.y + PLAYER_ATTACK1_COLL_TOP < Dammy.y + DAMMY_HEIGHT && Player.y + PLAYER_ATTACK1_COLL_BOTTOM >Dammy.y &&
				*shake_screen == false)
			{
				*shake_screen = true;
			}
		}
		if (Player.direction == Left)
		{
			if (Player.x + PLAYER_ATTACK1_COLL_RIGHT -(PLAYER_WIDTH/2)> Dammy.x + Map.draw_position_x && Player.x + PLAYER_ATTACK1_COLL_LEFT - (PLAYER_WIDTH / 2)< Dammy.x + DAMMY_WIDTH + Map.draw_position_x &&
				Player.y + PLAYER_ATTACK1_COLL_TOP < Dammy.y + DAMMY_HEIGHT && Player.y + PLAYER_ATTACK1_COLL_BOTTOM >Dammy.y &&
				*shake_screen == false)
			{
				*shake_screen = true;
			}
		}
	}
}