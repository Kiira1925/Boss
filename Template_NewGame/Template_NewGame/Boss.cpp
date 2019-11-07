#include  "DxLib.h"
#include  "Boss.h"

//struct Boss
//{
//    int HP;              //体力
//    int PosX;            //位置
//    int PosY;            //位置
//    int farattack;       //遠距離攻撃
//    int nearattack;      //近距離攻撃
//    int stanflg;         //スタンフラグ
//    int flyflg;          //飛行フラグ
//    int power;           //攻撃力
//    int jumpflg;         //ジャンプフラグ
//}b;


void boss_initialize(Character* Boss,int boss_handle)
{
    boss_handle = LoadGraph("C:\\Users\\2190232\\Desktop\\vsBoss\\Template_NewGame\\Template_NewGame\\sprite.png");
    Boss->x = 100;
    Boss->y = 100;
    Boss->HP = 200;
}

void moveBoss(Character* Boss)
{
    Boss->speed_x = 0;

    if (CheckHitKey(KEY_INPUT_RIGHT))
    {
        Boss->speed_x = BOSS_SPEED_MAX;
    }
    if (CheckHitKey(KEY_INPUT_LEFT))
    {
        Boss->speed_x = -BOSS_SPEED_MAX;
    }

    if (Boss->speed_x > 50) { Boss->speed_x = 50; }
    if (Boss->speed_y > 50) { Boss->speed_y = 50; }
    Boss->x += Boss->speed_x;
    Boss->y += Boss->speed_y;
}

void drawBoss(Character* Boss, int boss_handle)
{
    DrawRectGraph(Boss->x, Boss->y, 0, 192, 192, 192, boss_handle, true);
}

void boss_farattack()
{

}