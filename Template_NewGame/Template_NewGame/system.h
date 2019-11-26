#pragma once
//インクルード
#include"scene.h"

//定数定義
#define MAX_SHAKE_POWER	(10)

//プロトタイプ宣言
struct Bullet;
void drawDebugString(Character Player, int gravity, int jump_button_timer, int attack_button_timer, MapData Map, SceneFlag Scene, int shake_timer, int shake_power, bool shake_screen, int scene,AfterImage AfterPlayer,
	int gate_y, int gate_speed, Enemy Boss,Bullet Test,Bullet PlayerShot[5], XINPUT_STATE X_Input, int avoid_x, int avoid_y, bool avoid_tutorial, bool avoid_tutorial_fin);
void TimeController();
bool checkPressButton(int* space_button_timer, bool now_performance, XINPUT_STATE X_Input);
bool checkPressAttack(int* attack_button_timer, bool now_performance, XINPUT_STATE X_Input);
bool checkPressStep(int* step_button_timer, bool now_performance, XINPUT_STATE X_Input);
bool checkPressShot(int* shot_button_timer, bool now_performance, XINPUT_STATE X_Input);
void drawCollisionBox(Character Player, ScareCrow Dammy,MapData Map,Bullet PlayerShot[5]);
void drawBattleStartLine(MapData Map);
void shakeScreen(bool* shake_screen, int* shake_power_x, int* shake_power_y, int* shake_timer, Character* Player, MapData* Map, ScareCrow* Dammy, bool now_performance);