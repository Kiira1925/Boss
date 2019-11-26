//#include "scene.h"
//#include "player.h"
//#include "map.h"
#include "system.h"
#include "main.h"
#include "boss.h"
#include "Gimmick.h"

void StateTransition(int* scene, SceneFlag Scene)
{
	if (Scene.first_boss_appearance == true && *scene == Tutorial) { *scene = FirstBattle; }
	//if (Scene.destroy_first_boss == true && *scene == FirstBattle) { *scene = FirstMove; }
	if (Scene.second_boss_appearance == true && *scene == FirstMove) { *scene = SecondBattle; }
	//if (Scene.destroy_second_boss == true && *scene == SecondBattle) { *scene = SecondMove; }
	if (Scene.third_boss_appearance == true && *scene == SecondMove) { *scene = ThirdBattle; }
}

//StateTransitionよりも先に実行する
void changeStateFlag(SceneFlag* Scene, MapData Map, Character Player, int* scene, bool* now_performance)
{
	//ボス登場シーン1
	if (Player.x + PLAYER_COLL_RIGHT > Map.first_battle_line && *scene == Tutorial) { Scene->first_boss_appearance = true; }
	if (Scene->first_boss_appearance == true && Scene->performance_timer > 120)
	{
		Scene->first_boss_appearance = false;
		Scene->performance_timer = 0;
	}

	//ボス撃破時1
	if (*scene == FirstBattle && CheckHitKey(KEY_INPUT_0)) { Scene->destroy_first_boss = true; }
	if (Scene->destroy_first_boss == true && Scene->performance_timer > 240)
	{
		Scene->destroy_first_boss = false;
		Scene->performance_timer = 0;
		*scene = FirstMove;
	}

	//ボス登場シーン2
	if (Player.x + PLAYER_COLL_RIGHT > Map.second_battle_line && *scene == FirstMove) { Scene->second_boss_appearance = true; }
	if (Scene->second_boss_appearance == true && Scene->performance_timer > 120)
	{
		Scene->second_boss_appearance = false;
		Scene->performance_timer = 0;
	}

	//ボス撃破時2
	if (*scene == SecondBattle && CheckHitKey(KEY_INPUT_0)) { Scene->destroy_second_boss = true; }
	if (Scene->destroy_second_boss == true && Scene->performance_timer > 240)
	{
		Scene->destroy_second_boss = false;
		Scene->performance_timer = 0;
		*scene = SecondMove;
	}

	//ボス登場シーン3
	if (Player.x + PLAYER_COLL_RIGHT > Map.third_battle_line && *scene == SecondMove) { Scene->third_boss_appearance = true; }
	if (Scene->third_boss_appearance == true && Scene->performance_timer > 120)
	{
		Scene->third_boss_appearance = false;
		Scene->performance_timer = 0;
	}

	//ボス撃破時3
	if (*scene == ThirdBattle && CheckHitKey(KEY_INPUT_0)) { Scene->destroy_third_boss = true; }
	if (Scene->destroy_third_boss == true && Scene->performance_timer > 240)
	{
		Scene->destroy_third_boss = false;
		Scene->performance_timer = 0;
	}

	if (Scene->first_boss_appearance || Scene->destroy_first_boss || Scene->second_boss_appearance || Scene->destroy_second_boss || Scene->third_boss_appearance || Scene->destroy_third_boss) { *now_performance = true; }
	else { *now_performance = false; }
}

void performanceScroll(MapData* Map, Character* Player, Enemy* Boss, SceneFlag* Scene, int scene)
{
	//第一ボス戦
	if (Scene->first_boss_appearance == true)
	{
		if (Map->draw_position_x > -1980)
		{
			if (Player->x < ABS_FIRST_BATTLE_PLAYER_POS + Map->draw_position_x) { Player->speed_x = 10; }
			if (Player->x > ABS_FIRST_BATTLE_PLAYER_POS + Map->draw_position_x) { Player->x = ABS_FIRST_BATTLE_PLAYER_POS + Map->draw_position_x; }
			Player->x += Player->speed_x;
			Map->draw_position_x -= 8;
			Boss->x -= 8;
			if (Player->direction != Right) { Player->direction = Right; }
			if (Map->draw_position_x < -1980) { Map->draw_position_x = -1980; }
		}
		if (Scene->first_boss_appearance == true && Map->draw_position_x == -1980) { Scene->performance_timer++; }
	}

	if (Scene->destroy_first_boss == true)
	{
		if (Scene->performance_timer < 240)
		{
			if (Player->x < ABS_FIRST_BATTLE_PLAYER_POS + Map->draw_position_x && abs(ABS_FIRST_BATTLE_PLAYER_POS + Map->draw_position_x - Player->x) > 10) { Player->speed_x = 10; }
			if (Player->x > ABS_FIRST_BATTLE_PLAYER_POS + Map->draw_position_x && abs(ABS_FIRST_BATTLE_PLAYER_POS + Map->draw_position_x - Player->x) > 10) { Player->speed_x = -10; }
			if (abs(ABS_FIRST_BATTLE_PLAYER_POS + Map->draw_position_x - Player->x) <= 10) { Player->x = ABS_FIRST_BATTLE_PLAYER_POS + Map->draw_position_x; }
			Player->x += Player->speed_x;
		}
		if (Player->x == ABS_FIRST_BATTLE_PLAYER_POS + Map->draw_position_x)
		{
			Scene->performance_timer++;
			if (Player->direction != Right) { Player->direction = Right; }
		}
	}

	//第二ボス戦
	if (Scene->second_boss_appearance == true)
	{
		if (Map->draw_position_x > -7680)
		{
			if (Player->x < ABS_SECOND_BATTLE_PLAYER_POS + Map->draw_position_x) { Player->speed_x = 10; }
			if (Player->x > ABS_SECOND_BATTLE_PLAYER_POS + Map->draw_position_x) { Player->x = ABS_SECOND_BATTLE_PLAYER_POS + Map->draw_position_x; }
			Player->x += Player->speed_x;
			Map->draw_position_x -= 8;
			Boss->x -= 8;
			if (Player->direction != Right) { Player->direction = Right; }
			if (Map->draw_position_x < -7680) { Map->draw_position_x = -7680; }
		}
		if (Scene->second_boss_appearance == true && Map->draw_position_x == -7680) { Scene->performance_timer++; }
	}

	if (Scene->destroy_second_boss == true)
	{
		if (Scene->performance_timer < 240)
		{
			if (Player->x < ABS_SECOND_BATTLE_PLAYER_POS + Map->draw_position_x && abs(ABS_SECOND_BATTLE_PLAYER_POS + Map->draw_position_x - Player->x) > 10) { Player->speed_x = 10; }
			if (Player->x > ABS_SECOND_BATTLE_PLAYER_POS + Map->draw_position_x && abs(ABS_SECOND_BATTLE_PLAYER_POS + Map->draw_position_x - Player->x) > 10) { Player->speed_x = -10; }
			if (abs(ABS_SECOND_BATTLE_PLAYER_POS + Map->draw_position_x - Player->x) <= 10) { Player->x = ABS_SECOND_BATTLE_PLAYER_POS + Map->draw_position_x; }
			Player->x += Player->speed_x;
		}
		if (Player->x == ABS_SECOND_BATTLE_PLAYER_POS + Map->draw_position_x)
		{
			Scene->performance_timer++;
			if (Player->direction != Right) { Player->direction = Right; }
		}
	}
	//第三ボス戦
	if (Scene->third_boss_appearance == true)
	{
		if (Map->draw_position_x > -13440)
		{
			if (Player->x < ABS_THIRD_BATTLE_PLAYER_POS + Map->draw_position_x) { Player->speed_x = 10; }
			if (Player->x > ABS_THIRD_BATTLE_PLAYER_POS + Map->draw_position_x) { Player->x = ABS_THIRD_BATTLE_PLAYER_POS + Map->draw_position_x; }
			Player->x += Player->speed_x;
			Map->draw_position_x -= 8;
			Boss->x -= 8;
			if (Player->direction != Right) { Player->direction = Right; }
			if (Map->draw_position_x < -13440) { Map->draw_position_x = -13440; }
		}
		if (Scene->third_boss_appearance == true && Map->draw_position_x == -13440) { Scene->performance_timer++; }
	}

	if (Scene->destroy_third_boss == true)
	{
		if (Scene->performance_timer < 240)
		{
			if (Player->x < ABS_THIRD_BATTLE_PLAYER_POS + Map->draw_position_x && abs(ABS_THIRD_BATTLE_PLAYER_POS + Map->draw_position_x - Player->x) > 10) { Player->speed_x = 10; }
			if (Player->x > ABS_THIRD_BATTLE_PLAYER_POS + Map->draw_position_x && abs(ABS_THIRD_BATTLE_PLAYER_POS + Map->draw_position_x - Player->x) > 10) { Player->speed_x = -10; }
			if (abs(ABS_THIRD_BATTLE_PLAYER_POS + Map->draw_position_x - Player->x) <= 10) { Player->x = ABS_THIRD_BATTLE_PLAYER_POS + Map->draw_position_x; }
			Player->x += Player->speed_x;
		}
		if (Player->x == ABS_THIRD_BATTLE_PLAYER_POS + Map->draw_position_x)
		{
			Scene->performance_timer++;
			if (Player->direction != Right) { Player->direction = Right; }
		}
	}
}

void drawGate(int gate_handle, int gate_y, int shake_power_x, int shake_power_y)
{
	DrawGraph(0 + shake_power_x, gate_y + shake_power_y, gate_handle, TRUE);
	DrawGraph(1800 + shake_power_x, gate_y + shake_power_y, gate_handle, TRUE);
}

void dropGate(int* gate_y, SceneFlag Scene, int gravity, int* gate_speed, bool* shake_screen)
{
	if ((Scene.first_boss_appearance == true || Scene.second_boss_appearance == true || Scene.third_boss_appearance == true) && Scene.performance_timer > 20)
	{
		if (*gate_y <= -(GATE_HEIGHT - 430))
		{
			*gate_speed += 1;
			*gate_y += *gate_speed;
		}
		else
		{
			*gate_y = -(GATE_HEIGHT - 430);
			*gate_speed = 0;
			if (Scene.performance_timer < 60)
			{
				*shake_screen = true;
				StartJoypadVibration(DX_INPUT_PAD1, 1000, 200);
			}
		}
	}
	if ((Scene.destroy_first_boss == true || Scene.destroy_second_boss == true || Scene.destroy_third_boss == true) && Scene.performance_timer > 30)
	{
		if (*gate_y > -GATE_HEIGHT)
		{
			*gate_speed = -3;
			*gate_y += *gate_speed;
		}
		else
		{
			*gate_y = -GATE_HEIGHT;
			*gate_speed = 0;
		}
	}
}

void collGate(Character* Player,int scene,Gimmick Shooting[2])
{
	if (scene == FirstBattle || scene == SecondBattle || scene == ThirdBattle)
	{
		if (Player->x + PLAYER_COLL_LEFT < 120) { Player->x = 120 - PLAYER_COLL_LEFT; }
		if (Player->x + PLAYER_COLL_RIGHT > (1920 - 120)) { Player->x = (1920 - 120 - PLAYER_COLL_RIGHT); }
	}

	int gate_coll_left;
	int gate_coll_right;
	int gate_coll_top;
	int gate_coll_bottom;
	int player_coll_left;
	int player_coll_right;
	int player_coll_top;
	int player_coll_bottom;

	player_coll_left = Player->x + PLAYER_COLL_LEFT;
	player_coll_right = Player->x + PLAYER_COLL_RIGHT;
	player_coll_top = Player->y + PLAYER_COLL_TOP;
	player_coll_bottom = Player->y + PLAYER_COLL_BOTTOM;
	for (int i = 0; i < 2; i++)
	{
		gate_coll_left = Shooting[i].gate_x + GATE_WIDTH;
		gate_coll_right = Shooting[i].gate_x;
		gate_coll_top = Shooting[i].gate_y;
		gate_coll_bottom = Shooting[i].gate_y + GATE_HEIGHT;

		if (player_coll_left < gate_coll_right && player_coll_right > gate_coll_left && player_coll_top < gate_coll_bottom && player_coll_bottom > gate_coll_top)
		{
			if (Player->speed_x > 0) { Player->x = gate_coll_left; }
			if (Player->speed_x < 0) { Player->x = gate_coll_right; }
			if (Player->speed_y < 0) { Player->y = gate_coll_bottom; }
		}
	}
}

void practiceAvoid(bool* avoid_tutorial, bool* avoid_tutorial_fin, int* avoid_x,int* avoid_y,bool* shake_screen,int gate_handle, Character Player,MapData Map)
{
	if ((Player.x + (Map.draw_position_x)*-1)>9720 && (Player.x + (Map.draw_position_x)*-1) < 10860 && *avoid_tutorial == false)
	{
		*avoid_x = Player.x;
		if (Player.attack_state == BackStep) { *avoid_tutorial = true; }
	}

	if (*avoid_tutorial == true)
	{
		if (*avoid_y < (1080 - GATE_HEIGHT) && *avoid_tutorial_fin == false)
		{
			*avoid_y += 60;
			if (*avoid_y >= (1080 - GATE_HEIGHT))
			{
				*avoid_tutorial_fin = true;
				*shake_screen = true;
			}
		}

		if (*avoid_y > -GATE_HEIGHT && *avoid_tutorial_fin == true)
		{
			*avoid_y -= 60;
		}
	}
}

void drawAvoid(int gate_handle, int avoid_x, int avoid_y)
{
	DrawGraph(avoid_x, avoid_y, gate_handle, TRUE);
}