#include <DxLib.h>
#include "system.h"

void drawDebugString(Character Player, int gravity,int button_timer,MapData Map)
{
	int Orange = GetColor(255, 102, 0);
	//���l�n
	DrawFormatString(0, 20 * 0, Orange, "�v���C���[���WX:%d,Y:%d", Player.x, Player.y);
	DrawFormatString(0, 20 * 1, Orange, "�v���C���[�X�s�[�hX:%d,Y:%d", Player.speed_x, Player.speed_y);
	DrawFormatString(0, 20 * 2, Orange, "�W�����v�p���[:%d", Player.jump_pow);
	DrawFormatString(0, 20 * 3, Orange, "�{�^���^�C�}�[:%d", button_timer);
	DrawFormatString(0, 20 * 4, Orange, "�}�b�v�`����W:%d", Map.draw_position_x);

	//�t���O�n
	DrawFormatString(540, 20 * 0, Orange, "�W�����v�t���O:%d", Player.jump_flag);
	DrawFormatString(540, 20 * 1, Orange, "�G�A�W�����v�t���O:%d", Player.air_jump_flag);
	DrawFormatString(540, 20 * 2, Orange, "�ڒn����:%d", Player.on_ground);
	DrawFormatString(540, 20 * 3, Orange, "�v���C���[�̌���:%d", Player.direction);
}

//�e�X�g�֐��@������(����)���Ȃ�
void TimeController()
{
	if (CheckHitKey(KEY_INPUT_S))
	{
		WaitTimer(30);
	}
}

bool checkPressButton(int* button_timer)
{
	if (CheckHitKey(KEY_INPUT_SPACE)) { (*button_timer)++; }
	else { (*button_timer) = 0; }

	if ((*button_timer) == 1) { return true; }
	else { return false; }
}

void drawCollisionBox(Character Player)
{
	int color = GetColor(255, 0, 153);
	DrawBox(Player.x, Player.x + PLAYER_WIDTH, Player.y, Player.y + PLAYER_HEIGHT, color, FALSE);
}