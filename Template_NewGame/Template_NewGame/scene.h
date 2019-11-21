#pragma once
//インクルード
#include"map.h"
//定数定義

//構造体定義
struct SceneFlag
{
	bool first_boss_appearance;
	bool destroy_first_boss;
	bool second_boss_appearance;
	bool destroy_second_boss;
	bool third_boss_appearance;
	bool destroy_third_boss;

	int performance_timer;
};

enum PHASE{Tutorial,FirstBattle,FirstMove,SecondBattle,SecondMove,ThirdBattle};

//プロトタイプ宣言

void StateTransition(int* scene, SceneFlag Scene);
void changeStateFlag(SceneFlag* Scene, MapData Map, Character Player, int* scene, bool* now_performance);
void performanceScroll(MapData* Map, Character* Player,Enemy* Boss, SceneFlag* Scene, int scene);
void drawGate(int gate_handle, int gate_y, int shake_power_x, int shake_power_y);
void dropGate(int* gate_y, SceneFlag Scene, int gravity, int* gate_speed, bool* shake_screen);