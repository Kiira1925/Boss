//#include <DxLib.h>
//#include "player.h"
//#include "scarecrow.h"
//
#include "system.h"
#include "main.h"

void drawPlayer(Character* Player, int sprite_handle, int shake_power_x, int shake_power_y)
{
	if (Player->attack_state == None && Player->on_ground == true)
	{
		if (Player->speed_x == 0)
		{
			Player->anime_frame_num = (Player->anime_timer % 40) / 10;
			if (Player->direction == Right) { DrawRectGraph(Player->x + shake_power_x, Player->y + shake_power_y, PLAYER_SRC_X + (PLAYER_WIDTH*Player->anime_frame_num), PLAYER_SRC_Y, PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE); }
			if (Player->direction == Left) { DrawRectGraph(Player->x + shake_power_x, Player->y - shake_power_y, PLAYER_SRC_X + (PLAYER_WIDTH*Player->anime_frame_num), PLAYER_SRC_Y, PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE, TRUE); }
		}
		if (Player->speed_x > 0)
		{
			Player->anime_frame_num = (Player->anime_timer % 30) / 10;
			DrawRectGraph(Player->x + shake_power_x, Player->y - shake_power_y, PLAYER_SRC_X + (PLAYER_WIDTH*Player->anime_frame_num), PLAYER_SRC_Y + PLAYER_HEIGHT, PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE);
		}
		if (Player->speed_x < 0)
		{
			Player->anime_frame_num = (Player->anime_timer % 30) / 10;
			DrawRectGraph(Player->x + shake_power_x, Player->y - shake_power_y, PLAYER_SRC_X + (PLAYER_WIDTH*Player->anime_frame_num), PLAYER_SRC_Y + PLAYER_HEIGHT, PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE, TRUE);
		}
	}

	if (Player->attack_state == BackStep)
	{
		if (Player->step_timer <= 10)
		{
			if (Player->direction == Right) { DrawRectGraph(Player->x + shake_power_x, Player->y + shake_power_y, PLAYER_SRC_X + PLAYER_WIDTH * 2, (PLAYER_SRC_Y + PLAYER_HEIGHT * 2), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE); }
			if (Player->direction == Left) { DrawRectGraph(Player->x + shake_power_x, Player->y + shake_power_y, PLAYER_SRC_X + PLAYER_WIDTH * 2, (PLAYER_SRC_Y + PLAYER_HEIGHT * 2), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE, TRUE); }
		}
		else
		{
			if (Player->direction == Right) { DrawRectGraph(Player->x + shake_power_x, Player->y + shake_power_y, PLAYER_SRC_X + (PLAYER_WIDTH*Player->anime_frame_num), PLAYER_SRC_Y, PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE); }
			if (Player->direction == Left) { DrawRectGraph(Player->x + shake_power_x, Player->y - shake_power_y, PLAYER_SRC_X + (PLAYER_WIDTH*Player->anime_frame_num), PLAYER_SRC_Y, PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE, TRUE); }
		}
	}

	if (Player->attack_state == GrAttack1)
	{
		if (Player->direction == Right)
		{
			if (Player->attack_timer < 10) { DrawRectGraph(Player->x + shake_power_x, Player->y + shake_power_y, PLAYER_SRC_X, (PLAYER_SRC_Y + PLAYER_HEIGHT * 3), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE); }
			else { DrawRectGraph(Player->x + shake_power_x, Player->y - shake_power_y, PLAYER_SRC_X + PLAYER_WIDTH * 1, (PLAYER_SRC_Y + PLAYER_HEIGHT * 3), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE); }
		}
		if (Player->direction == Left)
		{
			if (Player->attack_timer < 10) { DrawRectGraph(Player->x + shake_power_x, Player->y - shake_power_y, PLAYER_SRC_X, (PLAYER_SRC_Y + PLAYER_HEIGHT * 3), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE, TRUE); }
			else { DrawRectGraph(Player->x + shake_power_x, Player->y - shake_power_y, PLAYER_SRC_X + PLAYER_WIDTH * 1, (PLAYER_SRC_Y + PLAYER_HEIGHT * 3), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE, TRUE); }
		}
	}

	if (Player->attack_state == GrAttack2)
	{
		if (Player->direction == Right)
		{
			if (Player->attack_timer < 10) { DrawRectGraph(Player->x + shake_power_x, Player->y + shake_power_y, PLAYER_SRC_X + PLAYER_WIDTH * 2, (PLAYER_SRC_Y + PLAYER_HEIGHT * 3), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE); }
			else { DrawRectGraph(Player->x + shake_power_x, Player->y - shake_power_y, PLAYER_SRC_X + PLAYER_WIDTH * 3, (PLAYER_SRC_Y + PLAYER_HEIGHT * 3), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE); }
		}
		if (Player->direction == Left)
		{
			if (Player->attack_timer < 10) { DrawRectGraph(Player->x + shake_power_x, Player->y - shake_power_y, PLAYER_SRC_X + PLAYER_WIDTH * 2, (PLAYER_SRC_Y + PLAYER_HEIGHT * 3), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE, TRUE); }
			else { DrawRectGraph(Player->x + shake_power_x, Player->y - shake_power_y, PLAYER_SRC_X + PLAYER_WIDTH * 3, (PLAYER_SRC_Y + PLAYER_HEIGHT * 3), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE, TRUE); }
		}
	}

	if (Player->on_ground == false && Player->attack_state == None)
	{
		if (Player->speed_y < 0)
		{
			if (Player->direction == Right) { DrawRectGraph(Player->x + shake_power_x, Player->y + shake_power_y, PLAYER_SRC_X, (PLAYER_SRC_Y + PLAYER_HEIGHT * 2), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE); }
			if (Player->direction == Left) { DrawRectGraph(Player->x + shake_power_x, Player->y + shake_power_y, PLAYER_SRC_X, (PLAYER_SRC_Y + PLAYER_HEIGHT * 2), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE, TRUE); }
		}
		else
		{
			if (Player->direction == Right) { DrawRectGraph(Player->x + shake_power_x, Player->y + shake_power_y, PLAYER_SRC_X + PLAYER_WIDTH * 2, (PLAYER_SRC_Y + PLAYER_HEIGHT * 2), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE); }
			if (Player->direction == Left) { DrawRectGraph(Player->x + shake_power_x, Player->y + shake_power_y, PLAYER_SRC_X + PLAYER_WIDTH * 2, (PLAYER_SRC_Y + PLAYER_HEIGHT * 2), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE, TRUE); }

		}
	}

	Player->anime_timer++;
}

void drawEffect(Character Player, int sprite_handle, MapData Map)
{
	if (Player.jump_effect_flag == true)
	{
		DrawRectGraph(Player.jump_effect_posX+Map.draw_position_x, Player.jump_effect_posY, 512 + JUMP_EFFECT_WIDTH*(Player.jump_effect_timer / 5) ,0, JUMP_EFFECT_WIDTH, JUMP_EFFECT_HEIGHT, sprite_handle, TRUE);
	}
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
void exeJump(Character* Player, MapData Map, int gravity, bool checkPressButton)
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
		Player->jump_effect_flag = true;
		Player->jump_effect_posX = (Player->x - 64)-Map.draw_position_x;
		Player->jump_effect_posY = Player->y - 128;
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

	if (Player->jump_effect_flag == true)
	{
		Player->jump_effect_timer++;
		if (Player->jump_effect_timer > 20)
		{
			Player->jump_effect_flag = false;
			Player->jump_effect_timer = 0;
		}
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

void attackPlayer(Character* Player, bool checkPressAttack, bool checkPressStep, bool now_performance)
{
	if (Player->attack_state == None && Player->on_ground && checkPressAttack)
	{
		Player->attack_timer = 0;
		Player->attack_state = GrAttack1;
		if (Player->direction == Right) { Player->speed_x = 20; }
		if (Player->direction == Left) { Player->speed_x = -20; }
	}
	//////////	攻撃一段目	//////////
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

		//バックステップに派生
		if (Player->stepable == true && checkPressStep && Player->attack_timer > 3)
		{
			Player->attack_state = BackStep;
			Player->speed_x = 0;
			Player->speed_y = 0;
			Player->stepable = false;
			Player->step_timer = 0;
			Player->attack_timer = 0;
		}

		//攻撃二段目へ派生
		if (Player->attack_state == GrAttack1 && Player->attack_timer > 5 && checkPressAttack)
		{
			Player->attack_state = GrAttack2;
			Player->attack_timer = 0;
			if (Player->direction == Right) { Player->speed_x = -20; }
			if (Player->direction == Left)	{ Player->speed_x = 20; }
			Player->speed_y = -20;
		}
	}

	//////////	攻撃二段目	//////////
	if (Player->attack_state == GrAttack2)
	{
		if (Player->speed_x > 0) { Player->speed_x -= 2; }
		if (Player->speed_x < 0) { Player->speed_x += 2; }
		//Player->x += Player->speed_x;
		Player->attack_timer++;
		if (Player->attack_timer > 20)
		{
			Player->attack_state = None;
			Player->attack_timer = 0;
		}
	}

	//////////	バックステップ	//////////
	if (Player->stepable == true && checkPressStep)
	{
		Player->attack_state = BackStep;
		Player->speed_x = 0;
		Player->speed_y = 0;
		Player->stepable = false;
		Player->step_timer = 0;
		Player->attack_timer = 0;
	}

	if (Player->attack_state == BackStep)
	{
		if (Player->step_timer == 0)
		{
			if (Player->direction == Right) { Player->speed_x = -40; }
			if (Player->direction == Left) { Player->speed_x = 40; }
			Player->speed_y = -10;
		}
		if (Player->speed_x > 0) { Player->speed_x -= 2; }
		if (Player->speed_x < 0) { Player->speed_x += 2; }
		Player->attack_timer++;
		if (Player->attack_timer > 20) { Player->attack_state = None; }
	}
	if (Player->step_timer < 20) { Player->step_timer++; }
	if (Player->step_timer >= 20) { Player->stepable = true; }

	//////////	演出時のプレイヤーの行動を抑制	//////////
	if (now_performance == true)
	{
		Player->attack_state = None;
		Player->attack_timer = 0;
		Player->speed_x = 0;
	}
}

void collPlayerAttack(Character Player, ScareCrow Dammy, bool* shake_screen, MapData Map, HitState* Attack)
{
	if (Player.attack_state == GrAttack1)
	{
		if (Player.direction == Right)
		{
			if (Player.x + PLAYER_ATTACK1_COLL_RIGHT> Dammy.x + Map.draw_position_x && Player.x + PLAYER_ATTACK1_COLL_LEFT < Dammy.x + DAMMY_WIDTH + Map.draw_position_x &&
				Player.y + PLAYER_ATTACK1_COLL_TOP < Dammy.y + DAMMY_HEIGHT && Player.y + PLAYER_ATTACK1_COLL_BOTTOM >Dammy.y &&
				!Attack->hit_GrAttack1 && *shake_screen == false)
			{
				*shake_screen = true;
				Attack->hit_GrAttack1 = true;
			}
		}
		if (Player.direction == Left)
		{
			if (Player.x + PLAYER_ATTACK1_COLL_RIGHT - (PLAYER_WIDTH / 2) > Dammy.x + Map.draw_position_x && Player.x + PLAYER_ATTACK1_COLL_LEFT - (PLAYER_WIDTH / 2) < Dammy.x + DAMMY_WIDTH + Map.draw_position_x &&
				Player.y + PLAYER_ATTACK1_COLL_TOP < Dammy.y + DAMMY_HEIGHT && Player.y + PLAYER_ATTACK1_COLL_BOTTOM >Dammy.y &&
				!Attack->hit_GrAttack1 && *shake_screen == false)
			{
				*shake_screen = true;
				Attack->hit_GrAttack1;
			}
		}
	}

	//ヒットチェックの初期化
	if (Player.attack_state != GrAttack1) { Attack->hit_GrAttack1 = false; }
	if (Player.attack_state != GrAttack2) { Attack->hit_GrAttack2_1 = false, Attack->hit_GrAttack2_2 = false; }
	if (Player.attack_state != GrAttack3) { Attack->hit_GrAttack3 = false; }
}

void savePlayerPos(Character Player, AfterImage* AfterPlayer)
{
	for (int i = 0; i < 20; i++)
	{
		*(AfterPlayer->x + (19 - i)) = *(AfterPlayer->x + (18 - i));
		*(AfterPlayer->y + (19 - i)) = *(AfterPlayer->y + (18 - i));
	}
	*AfterPlayer->x = Player.x;
	*AfterPlayer->y = Player.y;
}

void drawAfterImages(Character Player, AfterImage AfterPlayer, int shake_power_x, int shake_power_y, int sprite_handle)
{
	SetDrawBright(130, 130, 240);
	if (Player.attack_state == BackStep)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 160);
		if (Player.direction == Right) { DrawRectGraph(AfterPlayer.x[4] + shake_power_x, AfterPlayer.y[4] + shake_power_y, PLAYER_SRC_X * 2, (PLAYER_SRC_Y + PLAYER_HEIGHT * 2), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE); }
		if (Player.direction == Left) { DrawRectGraph(AfterPlayer.x[4] + shake_power_x, AfterPlayer.y[4] + shake_power_y, PLAYER_SRC_X * 2, (PLAYER_SRC_Y + PLAYER_HEIGHT * 2), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE, TRUE); }
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
		if (Player.direction == Right) { DrawRectGraph(AfterPlayer.x[8] + shake_power_x, AfterPlayer.y[8] + shake_power_y, PLAYER_SRC_X * 2, (PLAYER_SRC_Y + PLAYER_HEIGHT * 2), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE); }
		if (Player.direction == Left) { DrawRectGraph(AfterPlayer.x[8] + shake_power_x, AfterPlayer.y[8] + shake_power_y, PLAYER_SRC_X * 2, (PLAYER_SRC_Y + PLAYER_HEIGHT * 2), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE, TRUE); }
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 60);
		if (Player.direction == Right) { DrawRectGraph(AfterPlayer.x[12] + shake_power_x, AfterPlayer.y[12] + shake_power_y, PLAYER_SRC_X * 2, (PLAYER_SRC_Y + PLAYER_HEIGHT * 2), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE); }
		if (Player.direction == Left) { DrawRectGraph(AfterPlayer.x[12] + shake_power_x, AfterPlayer.y[12] + shake_power_y, PLAYER_SRC_X * 2, (PLAYER_SRC_Y + PLAYER_HEIGHT * 2), PLAYER_WIDTH, PLAYER_HEIGHT, sprite_handle, TRUE, TRUE); }
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	SetDrawBright(255, 255, 255);
}