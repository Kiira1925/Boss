#pragma once
//インクルード
#include"DxLib.h"
#include"scarecrow.h"

//定数定義
#define PLAYER_WIDTH				(128)
#define PLAYER_HEIGHT				(128)
#define PLAYER_SRC_X				(0)
#define PLAYER_SRC_Y				(60)
#define PLAYER_COLL_LEFT			(0+35)
#define PLAYER_COLL_RIGHT			(128-35)
#define PLAYER_COLL_TOP				(0+15)
#define PLAYER_COLL_BOTTOM			(128)
#define PLAYER_SPEED_MAX			(15)
#define PLAYER_JUMP_POW_MAX			(35)
#define PLAYER_DECAY_JUMP_POW		(2)
#define PLAYER_ATTACK1_COLL_LEFT	(75)
#define PLAYER_ATTACK1_COLL_RIGHT	(130)
#define PLAYER_ATTACK1_COLL_TOP		(60)
#define PLAYER_ATTACK1_COLL_BOTTOM	(90)
#define PLAYER_ATTACK2_COLL_LEFT	(15)
#define PLAYER_ATTACK2_COLL_RIGHT	(130)
#define PLAYER_ATTACK2_COLL_TOP		(0)
#define PLAYER_ATTACK2_COLL_BOTTOM	(100)
#define PLAYER_ATTACK3_COLL_LEFT	(15)
#define PLAYER_ATTACK3_COLL_RIGHT	(130)
#define PLAYER_ATTACK3_COLL_TOP		(0)
#define PLAYER_ATTACK3_COLL_BOTTOM	(100)
#define JUMP_EFFECT_WIDTH			(256)
#define JUMP_EFFECT_HEIGHT			(256)


//構造体定義
enum ATTACK_STATE {None, BackStep, GrAttack1,GrAttack2,GrAttack3,AirAttack,Shot};
enum PLAYER_DIRECTION { Left, Right };

struct Character
{
	int x, y;
	bool direction;
	int speed_x, speed_y;
	int HP;

	int jump_pow;
	bool on_ground;
	bool jump_flag;
	bool air_jump_flag;
	int jump_timer;
	bool jump_effect_flag;
	int jump_effect_timer;
	int jump_effect_posX, jump_effect_posY;

	bool hit_able;
	int attack_state;
	bool stepable;

	int anime_timer;
	int damage_timer;
	int attack_timer;
	int step_timer;

	int anime_frame_num;
};

struct HitState
{
	bool hit_GrAttack1;
	bool hit_GrAttack2;
	bool hit_GrAttack3;

	bool hit_AirAttack;

	bool hit_Shot;
};

struct AfterImage
{
	int x[20];
	int y[20];
};

//プロトタイプ宣言
//struct ScareCrow;
//struct Character;
struct Bullet;
void drawPlayer(Character* Player, int sprite_handle, int shake_power_x, int shake_power_y);
void movePlayer(Character* Player, bool now_performance, XINPUT_STATE X_input);
void exeJump(Character* Player, MapData Map, int gravity,bool checkPressButton);
void affectGravity(Character* Player, int gravity);
void attackPlayer(Character* Player, Bullet* PlayerShot, bool shot_fin, bool checkPressAttack, bool checkPressStep, bool checkPressShot, bool now_performance, XINPUT_STATE X_Input);
void collPlayerAttack(Character Player, ScareCrow Dammy, bool* shake_screen, int* shake_timer, MapData Map,HitState* Attack);
void collPlayerShot(Character Player, ScareCrow Dammy, bool* shake_screen, int* shake_timer, MapData Map, Bullet* PlayerShot);
void savePlayerPos(Character Player, AfterImage* AfterPlayer);
void drawAfterImages(Character Player, AfterImage AfterPlayer, int shake_power_x, int shake_power_y, int sprite_handle);
void drawEffect(Character Player, int sprite_handle,MapData Map);