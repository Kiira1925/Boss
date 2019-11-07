#pragma once

#define BOSS_WIDTH            (128)
#define BOSS_HEIGHT           (128)
#define BOSS_SRC_X            (0)
#define BOSS_SRC_Y            (60)
#define BOSS_COLL_LEFT        (0)
#define BOSS_COLL_RIGHT       (128)
#define BOSS_COLL_TOP         (0)
#define BOSS_COLL_BOTTOM      (128)
#define BOSS_SPEED_MAX        (15)
#define BOSS_JUMP_POW_MAX     (50)
#define BOSS_DECAY_JUMP_POW   (2)


void drawBoss(Character* Boss, int boss_handle);
void moveBoss(Character* Boss);

struct Character2
{
    int x, y;
    int speed_x, speed_y;
    int HP;

    int jump_pow;
    bool on_ground;
    bool jump_flag;

    bool hit_able;
    int attack_state;

    int anime_timer;     //キャラモーション
    int damage_timer;    //ダメージタイマー

    int anime_frame_num; //モーションナンバー
};