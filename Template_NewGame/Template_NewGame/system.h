#pragma once
//�C���N���[�h
#include "player.h"
#include "map.h"

//�v���g�^�C�v�錾
void drawDebugString(Character Player, int gravity, int button_timer,MapData Map);
void TimeController();
bool checkPressButton(int* button_timer);
void drawCollisionBox(Character Player);