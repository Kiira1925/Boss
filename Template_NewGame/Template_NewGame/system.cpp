#include <DxLib.h>
#include "system.h"

void drawDebugString(Character Player, int gravity)
{
	int Orange = GetColor(255, 102, 0);
	//���l�n
	DrawFormatString(0, 20 * 0, Orange, "�v���C���[���WX:%d,Y:%d", Player.x, Player.y);
	DrawFormatString(0, 20 * 1, Orange, "�W�����v�p���[:%d", Player.jump_pow);
	DrawFormatString(0, 20 * 2, Orange, "�v���C���[�X�s�[�hX:%d,Y:%d", Player.speed_x, Player.speed_y);

	//�t���O�n
	DrawFormatString(540, 20 * 0, Orange, "�W�����v�t���O:%d", Player.jump_flag);
	DrawFormatString(540, 20 * 1, Orange, "�ڒn����:%d", Player.on_ground);
}