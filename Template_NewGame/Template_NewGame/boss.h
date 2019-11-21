#pragma once
//インクルード
#include "player.h"

//定数定義
#define BOSS_WIDTH			(192)    //ボスの横幅
#define BOSS_HEIGHT			(192)    //ボスの縦幅
#define BOSS_SRC_X			(0)      //描画切り取り位置ｘ
#define BOSS_SRC_Y			(0)    //描画切り取り位置y
#define BOSS_COLL_LEFT		(0+50)      //画像の左線の座標
#define BOSS_COLL_RIGHT		(192-40)    //画像の右線の座標
#define BOSS_COLL_TOP   	(0)      //画像の上線の座標
#define BOSS_COLL_BOTTOM	(192)    //画像の下線の座標
#define BOSS_SPEED_MAX		(15)     //ボスのスピードマックス
#define BOSS_JUMP_POW_MAX	(50)     //ボスのジャンプ力マックス
#define BOSS_DECAY_JUMP_POW	(2)      //


//構造体定義
enum BOSS_ATTACK_STATE
{
	No,          //何もしてない
	FarShot,     //遠距離攻撃
	GrAttack,    //近距離攻撃
	Stan         //スタン
};

enum BOSS_DIRECTION
{
	B_Left,
	B_Right
};

struct Enemy
{
	int x, y;
	bool direction;
	int speed_x, speed_y;
	int HP;

	int jump_pow;         //ジャンプ力
	bool on_ground;       //地面についているか否か(true or false)
	bool jump_flag;       //ジャンプしてるか
	bool air_jump_flag;   //二段ジャンプしてるか
	int jump_timer;       //ジャンプタイマー

	bool hit_able;        //
	int boss_attack_state;     //攻撃種類

	int anime_timer;      //
	int damage_timer;     //ダメージタイマー

	int anime_frame_num;  //
};

//プロトタイプ宣言
void drawBoss(Enemy* Boss, int boss_handle, int shake_power_x, int shake_power_y);
void moveBoss(Character Player, Enemy* Boss);
void exeJump(Enemy* Boss, int gravity, bool checkPressButton);
void affectGravity(Enemy* Boss, int gravity);
void boss_attack(Character* Player, Enemy* Boss);