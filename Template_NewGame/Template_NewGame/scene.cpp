//#include "scene.h"
//#include "player.h"
//#include "map.h"
#include "system.h"
#include "main.h"
#include "boss.h"

void StateTransition(int* scene, SceneFlag Scene)
{
	if (Scene.first_boss_appearance == true && *scene == Tutorial) { *scene = FirstBattle; }
	//if (Scene.destroy_first_boss == true && *scene == FirstBattle) { *scene = FirstMove; }
	if (Scene.second_boss_appearance == true && *scene == FirstMove) { *scene = SecondBattle; }
	if (Scene.destroy_second_boss == true && *scene == SecondBattle) { *scene = SecondMove; }
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
		if (Player->x == ABS_FIRST_BATTLE_PLAYER_POS + Map->draw_position_x) { Scene->performance_timer++; }
	}

	//第二ボス戦

	//第三ボス戦
}

void drawGate(int gate_handle, int gate_y, int shake_power_x, int shake_power_y)
{
	DrawGraph(0 + shake_power_x, gate_y + shake_power_y, gate_handle, TRUE);
	DrawGraph(1800 + shake_power_x, gate_y + shake_power_y, gate_handle, TRUE);
}

void dropGate(int* gate_y, SceneFlag Scene, int gravity, int* gate_speed, bool* shake_screen)
{
	if (Scene.first_boss_appearance == true && Scene.performance_timer > 20)
	{
		if (*gate_y <= 0)
		{
			*gate_speed += 1;
			*gate_y += *gate_speed;
		}
		else
		{
			*gate_y = 0;
			*gate_speed = 0;
			if (Scene.performance_timer < 60) { *shake_screen = true; }
		}
	}
	if (Scene.destroy_first_boss == true && Scene.performance_timer > 30)
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