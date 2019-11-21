#pragma once
//�C���N���[�h
#include "player.h"

//�萔��`
#define BOSS_WIDTH			(192)    //�{�X�̉���
#define BOSS_HEIGHT			(192)    //�{�X�̏c��
#define BOSS_SRC_X			(0)      //�`��؂���ʒu��
#define BOSS_SRC_Y			(0)    //�`��؂���ʒuy
#define BOSS_COLL_LEFT		(0+50)      //�摜�̍����̍��W
#define BOSS_COLL_RIGHT		(192-40)    //�摜�̉E���̍��W
#define BOSS_COLL_TOP   	(0)      //�摜�̏���̍��W
#define BOSS_COLL_BOTTOM	(192)    //�摜�̉����̍��W
#define BOSS_SPEED_MAX		(15)     //�{�X�̃X�s�[�h�}�b�N�X
#define BOSS_JUMP_POW_MAX	(50)     //�{�X�̃W�����v�̓}�b�N�X
#define BOSS_DECAY_JUMP_POW	(2)      //


//�\���̒�`
enum BOSS_ATTACK_STATE
{
	No,          //�������ĂȂ�
	FarShot,     //�������U��
	GrAttack,    //�ߋ����U��
	Stan         //�X�^��
};

enum BOSS_DIRECTION
{
	B_Left,
	B_Right
};

struct Enemy
{
	int x, y;
	bool direction;
	int speed_x, speed_y;
	int HP;

	int jump_pow;         //�W�����v��
	bool on_ground;       //�n�ʂɂ��Ă��邩�ۂ�(true or false)
	bool jump_flag;       //�W�����v���Ă邩
	bool air_jump_flag;   //��i�W�����v���Ă邩
	int jump_timer;       //�W�����v�^�C�}�[

	bool hit_able;        //
	int boss_attack_state;     //�U�����

	int anime_timer;      //
	int damage_timer;     //�_���[�W�^�C�}�[

	int anime_frame_num;  //
};

//�v���g�^�C�v�錾
void drawBoss(Enemy* Boss, int boss_handle, int shake_power_x, int shake_power_y);
void moveBoss(Character Player, Enemy* Boss);
void exeJump(Enemy* Boss, int gravity, bool checkPressButton);
void affectGravity(Enemy* Boss, int gravity);
void boss_attack(Character* Player, Enemy* Boss);