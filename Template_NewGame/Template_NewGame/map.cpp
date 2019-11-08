#include <Dxlib.h>
#include "map.h"

//--�}�b�v�`�b�v�������e--
//	0	:	��(�����F)
//	1	:	�n��
//	2	:	��

int map_data[18][32]
{
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void drawMapChip(MapData Map,int sprite_handle)
{
	for (int Ver = 0; Ver < CHIP_MAX_Y; Ver++)
	{
		for (int Hor = 0; Hor < CHIP_MAX_X; Hor++)
		{
			DrawRectGraph((Map.draw_position_x + (CHIP_SIZE*Hor)), (Map.draw_position_y + (CHIP_SIZE*Ver)),
				CHIP_SRC_X + (CHIP_SIZE * map_data[Ver][Hor]), CHIP_SRC_Y, CHIP_SIZE, CHIP_SIZE, sprite_handle, true);
		}
	}
}

void setPlayerCollWithChip(MapData Map, Character* Player)
{

	Player->on_ground = false;
	//�`�b�v�����蔻�菈��
	for (int Ver = 0; Ver < CHIP_MAX_Y; Ver++)
	{
		for (int Hor = 0; Hor < CHIP_MAX_X; Hor++)
		{
			int chip_left;
			int chip_right;
			int chip_top;
			int chip_bottom;
			int player_coll_left;
			int player_coll_right;
			int player_coll_top;
			int player_coll_bottom;

			if (map_data[Ver][Hor] > 0)
			{
				//�}�b�v�`�b�v4�_���W
				chip_left = Hor*CHIP_SIZE + Map.draw_position_x;
				chip_right = (Hor + 1)*CHIP_SIZE + Map.draw_position_x;
				chip_top = Ver*CHIP_SIZE + Map.draw_position_y;
				chip_bottom = (Ver + 1)*CHIP_SIZE + Map.draw_position_y;
				//�v���C���[�����蔻�蕔4�_���W
				player_coll_left = Player->x + PLAYER_COLL_LEFT;
				player_coll_right = Player->x + PLAYER_COLL_RIGHT;
				player_coll_top = Player->y + PLAYER_COLL_TOP;
				player_coll_bottom = Player->y + PLAYER_COLL_BOTTOM;

				if (player_coll_left < chip_right && player_coll_right > chip_left && player_coll_top < chip_bottom && player_coll_bottom > chip_top)
				{
					//�c�����̉����߂�
					if (Player->speed_y != 0)
					{
						if (Player->speed_y > 0)
						{
							if (player_coll_left < chip_right && player_coll_right > chip_left && player_coll_top+120 < chip_bottom && player_coll_bottom > chip_top)
							{
								//����̂������`�b�v�̏�����Ƀ`�b�v�����݂��Ȃ���Ώ������s��
								if (map_data[Ver - 1][Hor] == 0)
								{
									Player->y = chip_top - PLAYER_COLL_BOTTOM;
								}
							}
						}
						if (Player->speed_y < 0)
						{
							if (player_coll_left < chip_right && player_coll_right > chip_left && player_coll_top < chip_bottom && player_coll_bottom-120 > chip_top)
							{
								//����̂������`�b�v�̉������Ƀ`�b�v�����݂��Ȃ���Ώ������s��
								if (map_data[Ver + 1][Hor] == 0)
								{
									Player->y = chip_bottom - PLAYER_COLL_TOP;
									Player->speed_y = 0;
								}
							}
						}
					}
				}
				//�����߂���̃v���C���[���W���Ď擾
				player_coll_left = Player->x + PLAYER_COLL_LEFT;
				player_coll_right = Player->x + PLAYER_COLL_RIGHT;
				player_coll_top = Player->y + PLAYER_COLL_TOP;
				player_coll_bottom = Player->y + PLAYER_COLL_BOTTOM;

				if (player_coll_left < chip_right && player_coll_right > chip_left && player_coll_top < chip_bottom && player_coll_bottom > chip_top)
				{
					//�������̉����߂�����
					if (Player->speed_x != 0)
					{
						if (Player->speed_x > 0)
						{
							//����̂������`�b�v�̍������Ƀ`�b�v�����݂��Ȃ���Ώ������s��
							if (map_data[Ver][Hor - 1] == 0)
							{
								Player->x = chip_left - PLAYER_COLL_RIGHT;
							}
						}
						if (Player->speed_x < 0)
						{
							//����̂������`�b�v�̉E�����Ƀ`�b�v�����݂��Ȃ���Ώ������s��
							if (map_data[Ver][Hor + 1] == 0)
							{
								Player->x = chip_right - PLAYER_COLL_LEFT;
							}
						}
					}
				}
				//�����߂���̃v���C���[���W���Ď擾
				player_coll_left = Player->x + PLAYER_COLL_LEFT;
				player_coll_right = Player->x + PLAYER_COLL_RIGHT;
				player_coll_top = Player->y + PLAYER_COLL_TOP;
				player_coll_bottom = Player->y + PLAYER_COLL_BOTTOM;

				//�ڒn����
				if (player_coll_bottom == chip_top && player_coll_right > chip_left && player_coll_left < chip_right)
				{
					Player->on_ground = true;
				}
			}
		}
	}
}
