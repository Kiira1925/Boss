#pragma once
//インクルード
#include "player.h"

//プロトタイプ宣言
void drawDebugString(Character Player, int gravity, int button_timer);
void TimeController();
bool checkPressButton(int* button_timer);
void drawCollisionBox(Character Player);