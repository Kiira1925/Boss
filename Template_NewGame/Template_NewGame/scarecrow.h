#pragma once
//�C���N���[�h

//extern

//�萔��`
#define DAMMY_WIDTH		(108)
#define DAMMY_HEIGHT	(108)

//�\���̒�`
struct ScareCrow
{
	int x, y;
	int hp;
};

//�v���g�^�C�v�錾
struct MapData;
void drawScareCrow(ScareCrow dammy, MapData map, int dammy_handle,int shake_power);