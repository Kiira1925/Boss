#pragma once
//インクルード

//定数定義
#define P_TALISMAN_COLL_TOP			(45)
#define P_TALISMAN_COLL_BOTTOM		(80)
#define P_TALISMAN_COLL_RIGHT		(70)
#define P_TALISMAN_COLL_LEFT		(50)

//構造体定義
struct Bullet
{
	int x, y;

	float cal_x, cal_y;			// ８方向以上の角度で座標を取ろうとすると小数点以下の数値が必要になるので、
	float speed;				// 計算用座標とスピードはfloatで取り、当たり判定と描画の前にint型に変換する

	int coll_right;
	int coll_left;
	int coll_top;
	int coll_bottom;

	int direction;
	int angle;
	bool exist;

	int timer;
	int frame;
};

//プロトタイプ宣言
void calTalisman(Bullet* PlayerShot);
void drawTalisman(Bullet PlayerShot[5], int bullet_handle);
void drawTest(Bullet* Test, int testB_handle);
void calTest(Bullet* Test, float fsin[360], float fcos[360]);