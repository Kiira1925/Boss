//#include <DxLib.h>
//#include "system.h"
//#include "player.h"
//#include "map.h"
//#include "scene.h"
//#include "scarecrow.h"
#include"system.h"
#include"main.h"

void drawDebugString(Character Player, int gravity, int jump_button_timer, int attack_button_timer, MapData Map, SceneFlag Scene, int shake_timer, int shake_power, bool shake_screen, int scene)
{
	int Orange = GetColor(255, 102, 0);
	//数値系
	DrawFormatString(540 * 0, 20 * 0, Orange, "プレイヤー座標X:%d,Y:%d", Player.x, Player.y);
	DrawFormatString(540 * 0, 20 * 1, Orange, "プレイヤースピードX:%d,Y:%d", Player.speed_x, Player.speed_y);
	DrawFormatString(540 * 0, 20 * 2, Orange, "ジャンプパワー:%d", Player.jump_pow);
	DrawFormatString(540 * 0, 20 * 3, Orange, "ジャンプボタンタイマー:%d", jump_button_timer);
	DrawFormatString(540 * 0, 20 * 4, Orange, "アタックボタンタイマー%d", attack_button_timer);
	DrawFormatString(540 * 0, 20 * 5, Orange, "マップ描画座標:%d", Map.draw_position_x);
	DrawFormatString(540 * 0, 20 * 6, Orange, "第一ボス戦開始ラインX:%d", Map.first_battle_line);
	DrawFormatString(540 * 0, 20 * 7, Orange, "画面道タイマー:%d", shake_timer);
	DrawFormatString(540 * 0, 20 * 8, Orange, "画面動力:%d", shake_power);

	//フラグ系
	DrawFormatString(540 * 1, 20 * 0, Orange, "ジャンプフラグ:%d", Player.jump_flag);
	DrawFormatString(540 * 1, 20 * 1, Orange, "エアジャンプフラグ:%d", Player.air_jump_flag);
	DrawFormatString(540 * 1, 20 * 2, Orange, "接地判定:%d", Player.on_ground);
	DrawFormatString(540 * 1, 20 * 3, Orange, "プレイヤーの向き:%d", Player.direction);
	DrawFormatString(540 * 1, 20 * 4, Orange, "第一回ボス登場フラグ:%d", Scene.first_boss_appearance);
	DrawFormatString(540 * 1, 20 * 5, Orange, "画面動フラグ:%d", shake_screen);

	//ステート系
	DrawFormatString(540 * 2, 20 * 0, Orange, "プレイヤー攻撃状態:%d", Player.attack_state);
	DrawFormatString(540 * 2, 20 * 1, Orange, "シーン:%d", scene);
}

//テスト関数　実装は(多分)しない
void TimeController()
{
	if (CheckHitKey(KEY_INPUT_S))
	{
		WaitTimer(30);
	}
}

bool checkPressButton(int* jump_button_timer, bool now_performance, XINPUT_STATE X_Input)
{
	if ((CheckHitKey(KEY_INPUT_SPACE) || X_Input.Buttons[XINPUT_BUTTON_A]) && !now_performance) {
		(*jump_button_timer)++;
	}
	else { (*jump_button_timer) = 0; }

	if ((*jump_button_timer) == 1) { return true; }
	else { return false; }
}

bool checkPressAttack(int* attack_button_timer, bool now_performance)
{
	if (CheckHitKey(KEY_INPUT_F) && !now_performance) { (*attack_button_timer)++; }
	else { (*attack_button_timer) = 0; }

	if ((*attack_button_timer) == 1) { return true; }
	else { return false; }
}

void drawCollisionBox(Character Player, ScareCrow Dammy, MapData Map)
{
	int color = GetColor(255, 0, 153);
	//プレイヤー
	DrawBox(Player.x + PLAYER_COLL_LEFT, Player.y + PLAYER_COLL_TOP, Player.x + PLAYER_COLL_RIGHT, Player.y + PLAYER_COLL_BOTTOM, color, FALSE);
	if (Player.attack_state == GrAttack1)
	{
		if (Player.direction == Right)
		{
			DrawBox(Player.x + PLAYER_ATTACK1_COLL_LEFT, Player.y + PLAYER_ATTACK1_COLL_TOP, Player.x + PLAYER_ATTACK1_COLL_RIGHT, Player.y + PLAYER_ATTACK1_COLL_BOTTOM, color, FALSE);
		}
		if (Player.direction == Left)
		{
			DrawBox(Player.x + PLAYER_ATTACK1_COLL_LEFT - (PLAYER_WIDTH / 2), Player.y + PLAYER_ATTACK1_COLL_TOP, Player.x + PLAYER_ATTACK1_COLL_RIGHT - (PLAYER_WIDTH / 2), Player.y + PLAYER_ATTACK1_COLL_BOTTOM, color, FALSE);
		}
	}

	//ダミー
	DrawBox(Dammy.x + Map.draw_position_x, Dammy.y, Dammy.x + DAMMY_WIDTH + Map.draw_position_x, Dammy.y + DAMMY_HEIGHT, color, FALSE);

}

void drawBattleStartLine(MapData Map)
{
	int color = GetColor(255, 100, 0);
	DrawLine(Map.first_battle_line, 0, Map.first_battle_line, 1080, color);
}

void shakeScreen(bool* shake_screen, int* shake_power, int* shake_timer, Character* Player, MapData* Map, ScareCrow* Dammy)
{
	if (*shake_screen)
	{
		if (Player->direction == Right)
		{
			//if (*shake_power < MAX_SHAKE_POWER && *shake_timer < 6) { *shake_power += 2; }
			//if (*shake_power > MAX_SHAKE_POWER && *shake_timer >= 6) { *shake_power -= 2; }
			if (*shake_timer < 5) { *shake_power = 15; }
			if (*shake_timer >= 5) { *shake_power = 0; }
			//Player->x += *shake_power;
			//Player->y += *shake_power;
			//Map->draw_position_x += *shake_power;
			//Map->draw_position_y += *shake_power;
			//Dammy->x += *shake_power;
			//Dammy->y += *shake_power;
			if (*shake_timer > 10) { *shake_screen = false; }
		}
		if (Player->direction == Left)
		{
			if (*shake_timer < 5) { *shake_power = -15; }
			if (*shake_timer >= 5) { *shake_power = 0; }
			if (*shake_timer > 10) { *shake_screen = false; }
		}
		(*shake_timer)++;
	}
	if (!*shake_screen)
	{
		*shake_timer = 0;
		*shake_power = 0;
	}
}