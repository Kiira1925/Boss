#pragma once
//インクルード

//定数定義
#define PLAYER_WIDTH			(128)
#define PLAYER_HEIGHT			(128)
#define PLAYER_SRC_X			(0)
#define PLAYER_SRC_Y			(60)
#define PLAYER_COLL_LEFT		(0)
#define PLAYER_COLL_RIGHT		(128)
#define PLAYER_COLL_TOP			(0)
#define PLAYER_COLL_BOTTOM		(128)
#define PLAYER_SPEED_MAX		(15)
#define PLAYER_JUMP_POW_MAX		(50)
#define PLAYER_DECAY_JUMP_POW	(2)


//構造体定義
enum ATTACK_STATE {None, GrAttack1,GrAttack2,GrAttack3};

struct Character
{
	int x, y;
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

	int anime_frame_num;
};

//プロトタイプ宣言
void drawPlayer(Character* Player, int sprite_handle);
void movePlayer(Character* Player);
void exeJump(Character* Player, int gravity,bool checkPressButton);
void affectGravity(Character* Player, int gravity);