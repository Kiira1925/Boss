#pragma once
//�C���N���[�h

//�萔��`
#define P_TALISMAN_COLL_TOP			(45)
#define P_TALISMAN_COLL_BOTTOM		(80)
#define P_TALISMAN_COLL_RIGHT		(70)
#define P_TALISMAN_COLL_LEFT		(50)

//�\���̒�`
struct Bullet
{
	int x, y;

	float cal_x, cal_y;			// �W�����ȏ�̊p�x�ō��W����낤�Ƃ���Ə����_�ȉ��̐��l���K�v�ɂȂ�̂ŁA
	float speed;				// �v�Z�p���W�ƃX�s�[�h��float�Ŏ��A�����蔻��ƕ`��̑O��int�^�ɕϊ�����

	int coll_right;
	int coll_left;
	int coll_top;
	int coll_bottom;

	int direction;
	int angle;
	bool exist;

	int timer;
	int frame;
};

//�v���g�^�C�v�錾
void calTalisman(Bullet* PlayerShot);
void drawTalisman(Bullet PlayerShot[5], int bullet_handle);
void drawTest(Bullet* Test, int testB_handle);
void calTest(Bullet* Test, float fsin[360], float fcos[360]);