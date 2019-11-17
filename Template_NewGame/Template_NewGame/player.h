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
#define PLAYER_ATTACK1_COLL_BOTTOM	(80)


//構造体定義
enum ATTACK_STATE {None, GrAttack1,GrAttack2,GrAttack3};
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

	bool hit_able;
	int attack_state;

	int anime_timer;
	int damage_timer;
	int attack_timer;

	int anime_frame_num;
};

//プロトタイプ宣言
//struct ScareCrow;
//struct Character;
void drawPlayer(Character* Player, int sprite_handle, int shake_power);
void movePlayer(Character* Player, bool now_performance, XINPUT_STATE X_input);
void exeJump(Character* Player, int gravity,bool checkPressButton);
void affectGravity(Character* Player, int gravity);
void attackPlayer(Character* Player, bool checkPressAttack, bool now_performance);
void collPlayerAttack(Character Player, ScareCrow Dammy, bool* shake_screen, MapData Map);