#pragma once
//インクルード
#include "player.h"
#include "map.h"

//プロトタイプ宣言
void drawDebugString(Character Player, int gravity, int button_timer,MapData Map);
void TimeController();
bool checkPressButton(int* button_timer);
void drawCollisionBox(Character Player);