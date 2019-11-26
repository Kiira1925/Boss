#define _CRT_SECURE_NO_WARNINGS
#include "system.h"
#include "main.h"
#include "boss.h"
#include "shot.h"
#include "bg.h"
#include "gimmick.h"



//--�}�b�v�`�b�v�������e--
//	0	:	��(�����F)
//	1	:	�n��
//	2	:	�n��
//	3	:	��
//	4	:	���蔲�����鏰

int map_data[18][256] =
{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,1,1,1,1,1,1,1,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3
};

void loadMap()
{
	FILE* fp;
	fp = fopen("Data/Map/map_data.txt", "r");
	if (fp == NULL) { return; }

	//int count = 0;
	//while (fscanf(fp, "%d", (&map_data+count)) != EOF)
	//{
	//	count++;
	//
	//}

	for (int h = 0; h < 18; h++)
	{
		for (int v = 0; v < 256; v++)
		{
			fscanf(fp, "%d", &map_data[h][v]);
		}
	}
	fclose(fp);
}

void drawMapChip(MapData Map, int sprite_handle, int shake_power_x, int shake_power_y)
{
	for (int Ver = 0; Ver < CHIP_MAX_Y; Ver++)
	{
		for (int Hor = 0 + MAP_MOVE_AMOUNT; Hor < CHIP_MAX_X + MAP_MOVE_AMOUNT + 1; Hor++)
		{
			DrawRectGraph((Map.draw_position_x + (CHIP_SIZE*Hor) + shake_power_x), (Map.draw_position_y + (CHIP_SIZE*Ver) - shake_power_y),
				CHIP_SRC_X + (CHIP_SIZE * map_data[Ver][Hor]), CHIP_SRC_Y, CHIP_SIZE, CHIP_SIZE, sprite_handle, true);
		}
	}
}

void setPlayerCollWithChip(MapData Map, Character* Player, XINPUT_STATE X_Input)
{

	Player->on_ground = false;
	//�`�b�v�����蔻�菈��
	for (int Ver = 0; Ver < CHIP_MAX_Y; Ver++)
	{
		for (int Hor = 0 + MAP_MOVE_AMOUNT; Hor < CHIP_MAX_X + MAP_MOVE_AMOUNT + 1; Hor++)
		{
			int chip_left;
			int chip_right;
			int chip_top;
			int chip_bottom;
			int player_coll_left;
			int player_coll_right;
			int player_coll_top;
			int player_coll_bottom;

			if (map_data[Ver][Hor] > 0 && map_data[Ver][Hor] != 4)
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
							if (player_coll_left < chip_right && player_coll_right > chip_left && player_coll_top + 120 < chip_bottom && player_coll_bottom > chip_top)
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
							if (player_coll_left < chip_right && player_coll_right > chip_left && player_coll_top < chip_bottom && player_coll_bottom - 120 > chip_top)
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

			//���蔲���\�ȑ���
			if (map_data[Ver][Hor] == 4)
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
							if (player_coll_left < chip_right && player_coll_right > chip_left && player_coll_top + 120 < chip_bottom && player_coll_bottom > chip_top)
							{
								//����̂������`�b�v�̏�����Ƀ`�b�v�����݂��Ȃ���Ώ������s��
								if (map_data[Ver - 1][Hor] == 0)
								{
									if (!(CheckHitKey(KEY_INPUT_DOWN) || X_Input.ThumbLY < -30000)) { Player->y = chip_top - PLAYER_COLL_BOTTOM; }
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

				//�ڒn����
				if (player_coll_bottom == chip_top && player_coll_right > chip_left && player_coll_left < chip_right)
				{
					Player->on_ground = true;
					if (CheckHitKey(KEY_INPUT_DOWN) || X_Input.ThumbLY < -30000) { Player->on_ground = false; }
				}
			}
		}
	}
}

void setBossCollWithChip(MapData Map, Enemy* Boss)
{
	Boss->on_ground = false;
	//�`�b�v�����蔻�菈��
	for (int Ver = 0; Ver < CHIP_MAX_Y; Ver++)
	{
		for (int Hor = 0 + MAP_MOVE_AMOUNT; Hor < CHIP_MAX_X + MAP_MOVE_AMOUNT + 1; Hor++)
		{
			int chip_left;
			int chip_right;
			int chip_top;
			int chip_bottom;
			int boss_coll_left;
			int boss_coll_right;
			int boss_coll_top;
			int boss_coll_bottom;

			if (map_data[Ver][Hor] > 0)
			{
				//�}�b�v�`�b�v4�_���W
				chip_left = Hor*CHIP_SIZE + Map.draw_position_x;
				chip_right = (Hor + 1)*CHIP_SIZE + Map.draw_position_x;
				chip_top = Ver*CHIP_SIZE + Map.draw_position_y;
				chip_bottom = (Ver + 1)*CHIP_SIZE + Map.draw_position_y;
				//�{�X�����蔻�蕔4�_���W
				boss_coll_left = Boss->x + BOSS_COLL_LEFT;
				boss_coll_right = Boss->x + BOSS_COLL_RIGHT;
				boss_coll_top = Boss->y + BOSS_COLL_TOP;
				boss_coll_bottom = Boss->y + BOSS_COLL_BOTTOM;

				if (boss_coll_left < chip_right && boss_coll_right > chip_left && boss_coll_top < chip_bottom && boss_coll_bottom > chip_top)
				{
					//�c�����̉����߂�
					if (Boss->speed_y != 0)
					{
						if (Boss->speed_y > 0)
						{
							if (boss_coll_left < chip_right && boss_coll_right > chip_left && boss_coll_top + 180 < chip_bottom && boss_coll_bottom > chip_top)
							{
								//����̂������`�b�v�̏�����Ƀ`�b�v�����݂��Ȃ���Ώ������s��
								if (map_data[Ver - 1][Hor] == 0)
								{
									Boss->y = chip_top - BOSS_COLL_BOTTOM;
								}
							}
						}
						if (Boss->speed_y < 0)
						{
							if (boss_coll_left < chip_right && boss_coll_right > chip_left && boss_coll_top < chip_bottom && boss_coll_bottom - 180 > chip_top)
							{
								//����̂������`�b�v�̉������Ƀ`�b�v�����݂��Ȃ���Ώ������s��
								if (map_data[Ver + 1][Hor] == 0)
								{
									Boss->y = chip_bottom;
									Boss->speed_y = 0;
								}
							}
						}
					}
				}
				//�����߂���̃v���C���[���W���Ď擾
				boss_coll_left = Boss->x + BOSS_COLL_LEFT;
				boss_coll_right = Boss->x + BOSS_COLL_RIGHT;
				boss_coll_top = Boss->y + BOSS_COLL_TOP;
				boss_coll_bottom = Boss->y + BOSS_COLL_BOTTOM;

				if (boss_coll_left < chip_right && boss_coll_right > chip_left && boss_coll_top < chip_bottom && boss_coll_bottom > chip_top)
				{
					//�������̉����߂�����
					if (Boss->speed_x != 0)
					{
						if (Boss->speed_x > 0)
						{
							//����̂������`�b�v�̍������Ƀ`�b�v�����݂��Ȃ���Ώ������s��
							if (map_data[Ver][Hor - 1] == 0)
							{
								Boss->x = chip_left - BOSS_COLL_RIGHT;
							}
						}
						if (Boss->speed_x < 0)
						{
							//����̂������`�b�v�̉E�����Ƀ`�b�v�����݂��Ȃ���Ώ������s��
							if (map_data[Ver][Hor + 1] == 0)
							{
								Boss->x = chip_right;
							}
						}
					}
				}
				//�����߂���̃v���C���[���W���Ď擾
				boss_coll_left = Boss->x + BOSS_COLL_LEFT;
				boss_coll_right = Boss->x + BOSS_COLL_RIGHT;
				boss_coll_top = Boss->y + BOSS_COLL_TOP;
				boss_coll_bottom = Boss->y + BOSS_COLL_BOTTOM;

				//�ڒn����
				if (boss_coll_bottom == chip_top && boss_coll_right > chip_left && boss_coll_left < chip_right)
				{
					Boss->on_ground = true;
				}
			}
		}
	}
}

void setTalismanCollWithChip(MapData Map, Bullet* PlayerShot)
{
	//�`�b�v�����蔻�菈��
	for (int Ver = 0; Ver < CHIP_MAX_Y; Ver++)
	{
		for (int Hor = 0 + MAP_MOVE_AMOUNT; Hor < CHIP_MAX_X + MAP_MOVE_AMOUNT + 1; Hor++)
		{
			int chip_left;
			int chip_right;
			int chip_top;
			int chip_bottom;

			if (map_data[Ver][Hor] > 0)
			{
				//�}�b�v�`�b�v4�_���W
				chip_left = Hor*CHIP_SIZE + Map.draw_position_x;
				chip_right = (Hor + 1)*CHIP_SIZE + Map.draw_position_x;
				chip_top = Ver*CHIP_SIZE + Map.draw_position_y;
				chip_bottom = (Ver + 1)*CHIP_SIZE + Map.draw_position_y;

				for (int i = 0; i < 5; i++)
				{
					if ((PlayerShot + i)->exist)
					{
						if ((PlayerShot + i)->coll_left < chip_right && (PlayerShot + i)->coll_right > chip_left && (PlayerShot + i)->coll_top < chip_bottom && (PlayerShot + i)->coll_bottom > chip_top)
						{
							(PlayerShot + i)->exist = false;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		if ((PlayerShot + i)->coll_right < 0 || (PlayerShot + i)->coll_left > 1920 || (PlayerShot + i)->coll_top < 0 || (PlayerShot + i)->coll_bottom >1080)
		{
			(PlayerShot + i)->exist = false;
		}
	}
}

//�L�[���͂ɂ��}�b�v�`�b�v�̃X�N���[��	���f�o�b�O�p�Ȃ̂Ń}�X�^�[�ł͎������Ȃ�
void moveMapChip(MapData* Map)
{
	if (Map->draw_position_x >= BG_DEST_LIMIT_LEFT)
	{
		if (CheckHitKey(KEY_INPUT_D))
		{
			Map->draw_position_x -= BG_SCROLL_SPEED;
			if (Map->draw_position_x <= BG_DEST_LIMIT_LEFT)

			{
				Map->draw_position_x = BG_DEST_LIMIT_LEFT;
			}
		}
	}

	if (Map->draw_position_x <= BG_DEST_LIMIT_RIGHT)
	{
		if (CheckHitKey(KEY_INPUT_A))
		{
			Map->draw_position_x += BG_SCROLL_SPEED;
			if (Map->draw_position_x >= BG_DEST_LIMIT_RIGHT)
			{
				Map->draw_position_x = BG_DEST_LIMIT_RIGHT;
			}
		}
	}
}

void scrollMapChip(MapData* Map, Character* Player, Enemy* Boss, BackGround* BG, Gimmick* Shooting, int scene,bool avoid_tutorial, int* avoid_x)
{
	int scroll_dest_pos;
	int scroll_speed;

	if (Player->direction == Right)
	{
		scroll_dest_pos = 400;
		if (Player->x + (PLAYER_WIDTH / 2) > scroll_dest_pos) { scroll_speed = ((float)(Player->x + (PLAYER_WIDTH / 2) - scroll_dest_pos) / 1000) * 30; }
		if (Player->x + (PLAYER_WIDTH / 2) < scroll_dest_pos) { scroll_speed = ((float)(scroll_dest_pos - Player->x + (PLAYER_WIDTH / 2)) / 1000) * 30; }
	}
	if (Player->direction == Left)
	{
		scroll_dest_pos = 1520;
		if (Player->x + (PLAYER_WIDTH / 2) < scroll_dest_pos) { scroll_speed = ((float)(scroll_dest_pos - Player->x + (PLAYER_WIDTH / 2)) / 1000) * 30; }
		if (Player->x + (PLAYER_WIDTH / 2) > scroll_dest_pos) { scroll_speed = ((float)(Player->x + (PLAYER_WIDTH / 2) - scroll_dest_pos) / 1000) * 30; }
	}

	if (scene != 1 && scene != 3 && scene != 5)
	{
		//if (Player->attack_state == BackStep)
		//{
		//	Map->draw_position_x -= Player->speed_x;
		//}
		BG->scroll_speed = 0;
		//���ɃX�N���[������ꍇ
		if (Player->x + (PLAYER_WIDTH / 2) > scroll_dest_pos)
		{
			if (Map->draw_position_x != BG_DEST_LIMIT_LEFT) {
				Player->x -= scroll_speed;
				Boss->x -= scroll_speed;
				Map->draw_position_x -= scroll_speed;
				BG->scroll_speed = -scroll_speed /4;
				if (avoid_tutorial == true) { *avoid_x -= scroll_speed; }
			}
		}

		//�E�ɃX�N���[������ꍇ
		if (Player->x + (PLAYER_WIDTH / 2) < scroll_dest_pos)
		{
			if (Map->draw_position_x != BG_DEST_LIMIT_RIGHT) {
				Player->x += scroll_speed;
				Boss->x += scroll_speed;
				Map->draw_position_x += scroll_speed;
				BG->scroll_speed = scroll_speed / 4;
				if (avoid_tutorial == true) { *avoid_x += scroll_speed; }
			}
		}
	}

	////�E�����X�N���[�����E�n�_����
	if (Map->draw_position_x > BG_DEST_LIMIT_RIGHT) { Map->draw_position_x = BG_DEST_LIMIT_RIGHT; }
	if (Player->x < 0) { Player->x = 0; }

	////�������X�N���[�����E�n�_����
	if (Map->draw_position_x < BG_DEST_LIMIT_LEFT) { Map->draw_position_x = BG_DEST_LIMIT_LEFT; }
	if (Player->x + PLAYER_WIDTH>1920) { Player->x = 1920 - PLAYER_WIDTH; }

	//�{�X�픻�胉�C�����W�X�V
	Map->first_battle_line = ABS_FIRST_BATTLE_LINE + Map->draw_position_x;
	Map->second_battle_line = ABS_SECOND_BATTLE_LINE + Map->draw_position_x;
	Map->third_battle_line = ABS_THIRD_BATTLE_LINE + Map->draw_position_x;
}