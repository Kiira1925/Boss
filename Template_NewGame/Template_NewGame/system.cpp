//#include <DxLib.h>
//#include "system.h"
//#include "player.h"
//#include "map.h"
//#include "scene.h"
//#include "scarecrow.h"
#include "system.h"
#include "main.h"
#include "boss.h"

void drawDebugString(Character Player, int gravity, int jump_button_timer, int attack_button_timer, MapData Map, SceneFlag Scene, int shake_timer, int shake_power, bool shake_screen, int scene, AfterImage AfterPlayer,
	int gate_y, int gate_speed, Enemy Boss)
{
	int Orange = GetColor(255, 102, 0);
	//���l�n
	DrawFormatString(540 * 0, 20 * 0, Orange, "�v���C���[���WX:%d,Y:%d", Player.x, Player.y);
	DrawFormatString(540 * 0, 20 * 1, Orange, "�v���C���[�X�s�[�hX:%d,Y:%d", Player.speed_x, Player.speed_y);
	DrawFormatString(540 * 0, 20 * 2, Orange, "�W�����v�p���[:%d", Player.jump_pow);
	DrawFormatString(540 * 0, 20 * 3, Orange, "�W�����v�{�^���^�C�}�[:%d", jump_button_timer);
	DrawFormatString(540 * 0, 20 * 4, Orange, "�A�^�b�N�{�^���^�C�}�[%d", attack_button_timer);
	DrawFormatString(540 * 0, 20 * 5, Orange, "�}�b�v�`����W:%d", Map.draw_position_x);
	DrawFormatString(540 * 0, 20 * 6, Orange, "���{�X��J�n���C��X:%d", Map.first_battle_line);
	DrawFormatString(540 * 0, 20 * 7, Orange, "��ʓ��^�C�}�[:%d", shake_timer);
	DrawFormatString(540 * 0, 20 * 8, Orange, "��ʓ���:%d", shake_power);
	DrawFormatString(540 * 0, 20 * 9, Orange, "�X�e�b�v�^�C�}�[%d", Player.step_timer);
	DrawFormatString(540 * 0, 20 * 10, Orange, "�W�����v�G�t�F�N�g�^�C�}�[:%d", Player.jump_effect_timer);
	DrawFormatString(540 * 0, 20 * 11, Orange, "�Q�[�g���Wy:%d", gate_y);
	DrawFormatString(540 * 0, 20 * 12, Orange, "�Q�[�g�X�s�[�h:%d", gate_speed);
	DrawFormatString(540 * 0, 20 * 13, Orange, "�p�t�H�[�}���X�^�C�}�[:%d", Scene.performance_timer);
	DrawFormatString(540 * 0, 20 * 14, Orange, "�{�X���WX:%d,Y:%d", Boss.x, Boss.y);

	//�t���O�n
	DrawFormatString(540 * 1, 20 * 0, Orange, "�W�����v�t���O:%d", Player.jump_flag);
	DrawFormatString(540 * 1, 20 * 1, Orange, "�G�A�W�����v�t���O:%d", Player.air_jump_flag);
	DrawFormatString(540 * 1, 20 * 2, Orange, "�ڒn����:%d", Player.on_ground);
	DrawFormatString(540 * 1, 20 * 3, Orange, "�v���C���[�̌���:%d", Player.direction);
	DrawFormatString(540 * 1, 20 * 4, Orange, "����{�X�o��t���O:%d", Scene.first_boss_appearance);
	DrawFormatString(540 * 1, 20 * 5, Orange, "��ʓ��t���O:%d", shake_screen);
	DrawFormatString(540 * 1, 20 * 6, Orange, "�o�b�N�X�e�b�v�t���O:%d", Player.stepable);
	DrawFormatString(540 * 1, 20 * 7, Orange, "�W�����v�G�t�F�N�g�t���O:%d", Player.jump_effect_flag);
	DrawFormatString(540 * 1, 20 * 8, Orange, "�{�X�W�����v�t���O:%d", Boss.jump_flag);
	DrawFormatString(540 * 1, 20 * 9, Orange, "�{�X�ڒn����:%d", Boss.on_ground);

	//�X�e�[�g�n
	DrawFormatString(540 * 2, 20 * 0, Orange, "�v���C���[�U�����:%d", Player.attack_state);
	DrawFormatString(540 * 2, 20 * 1, Orange, "�V�[��:%d", scene);
}

//�e�X�g�֐��@������(����)���Ȃ�
void TimeController()
{
	if (CheckHitKey(KEY_INPUT_S))
	{
		WaitTimer(30);
	}
}

bool checkPressButton(int* jump_button_timer, bool now_performance, XINPUT_STATE X_Input)
{
	if ((CheckHitKey(KEY_INPUT_SPACE) || X_Input.Buttons[XINPUT_BUTTON_A]) && !now_performance) {
		(*jump_button_timer)++;
	}
	else { (*jump_button_timer) = 0; }

	if ((*jump_button_timer) == 1) { return true; }
	else { return false; }
}

bool checkPressAttack(int* attack_button_timer, bool now_performance)
{
	if (CheckHitKey(KEY_INPUT_F) && !now_performance) { (*attack_button_timer)++; }
	else { (*attack_button_timer) = 0; }

	if ((*attack_button_timer) == 1) { return true; }
	else { return false; }
}

bool checkPressStep(int* step_button_timer, bool now_performance)
{
	if (CheckHitKey(KEY_INPUT_LSHIFT) && !now_performance) { (*step_button_timer)++; }
	else { (*step_button_timer) = 0; }

	if ((*step_button_timer) == 1) { return true; }
	else { return false; }
}

void drawCollisionBox(Character Player, ScareCrow Dammy, MapData Map)
{
	int color = GetColor(255, 0, 153);
	//�v���C���[
	DrawBox(Player.x + PLAYER_COLL_LEFT, Player.y + PLAYER_COLL_TOP, Player.x + PLAYER_COLL_RIGHT, Player.y + PLAYER_COLL_BOTTOM, color, FALSE);
	if (Player.attack_state == GrAttack1)
	{
		if (Player.direction == Right)
		{
			DrawBox(Player.x + PLAYER_ATTACK1_COLL_LEFT, Player.y + PLAYER_ATTACK1_COLL_TOP, Player.x + PLAYER_ATTACK1_COLL_RIGHT, Player.y + PLAYER_ATTACK1_COLL_BOTTOM, color, FALSE);
		}
		if (Player.direction == Left)
		{
			DrawBox(Player.x + PLAYER_ATTACK1_COLL_LEFT - (PLAYER_WIDTH / 2), Player.y + PLAYER_ATTACK1_COLL_TOP, Player.x + PLAYER_ATTACK1_COLL_RIGHT - (PLAYER_WIDTH / 2), Player.y + PLAYER_ATTACK1_COLL_BOTTOM, color, FALSE);
		}
	}

	//�_�~�[
	DrawBox(Dammy.x + Map.draw_position_x, Dammy.y, Dammy.x + DAMMY_WIDTH + Map.draw_position_x, Dammy.y + DAMMY_HEIGHT, color, FALSE);

}

void drawBattleStartLine(MapData Map)
{
	int color = GetColor(255, 100, 0);
	DrawLine(Map.first_battle_line, 0, Map.first_battle_line, 1080, color);
}

void shakeScreen(bool* shake_screen, int* shake_power_x, int* shake_power_y, int* shake_timer, Character* Player, MapData* Map, ScareCrow* Dammy)
{
	if (*shake_screen)
	{
		if (Player->direction == Right)
		{
			//if (*shake_timer < 5) { *shake_power_x += 5; }
			//if (*shake_timer >= 5) { *shake_power_x = 0; *shake_power_y -= 5;}
			*shake_power_x = *shake_power_y = 0;
			if (*shake_timer % 5 < 3) { *shake_power_x = 10; }
			if (*shake_timer % 5 >= 3) { *shake_power_y = 10; }
			if (*shake_timer > 6) { *shake_screen = false; }
		}
		if (Player->direction == Left)
		{
			*shake_power_x = *shake_power_y = 0;
			if (*shake_timer % 5 < 3) { *shake_power_x = 10; }
			if (*shake_timer % 5 >= 3) { *shake_power_y = 10; }
			if (*shake_timer > 10) { *shake_screen = false; }
		}
		(*shake_timer)++;
	}
	if (!*shake_screen)
	{
		*shake_timer = 0;
		*shake_power_x = 0;
		*shake_power_y = 0;
	}
}