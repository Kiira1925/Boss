#pragma once
//�C���N���[�h
#include "map.h"

//�萔��`
#define SHOOTRANGE_WIDTH		(720)
#define SHOOTRANGE_HEIGHT		(120)
#define ABS_SHOOTRANGE_POS_X	(5040)
#define ABS_TARGET_POS_X		(5700)
#define ABS_GATE_POS_X			(5640)

//�\���̒�`
struct Gimmick
{
	int range_x, range_y;
	int target_x, target_y;
	int gate_x, gate_y;

	bool hit;
};

//�v���g�^�C�v�錾
struct Character;
struct Bullet;
void drawShootRange(int shootrange_handle, int target_handle, int gate_handle, Gimmick Shooting[2]);
void collShootRange(Character* Player, Gimmick* Shooting, Bullet* PlayerShot, MapData Map);