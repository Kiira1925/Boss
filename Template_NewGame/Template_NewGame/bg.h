#pragma once
//�C���N���[�h

//�萔��`
#define BG_WIDTH	(256)
#define BG_HEIGHT	(144)

//�\���̒�`
struct BackGround
{
	int x1, y1;
	int x2, y2;

	int tree_x, tree_y;
	int temple_x, temple_y;

	int scroll_speed;
};

//�v���g�^�C�v�錾
struct MapData;
void drawBG(int bg_handle, int bg2_handle, MapData Map, BackGround BG);
void scrollBG(BackGround* BG);
void scrollTree(BackGround* BG, MapData Map);