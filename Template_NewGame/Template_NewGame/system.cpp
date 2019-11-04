#include <DxLib.h>
#include "system.h"

void drawDebugString(Character Player, int gravity)
{
	int Orange = GetColor(255, 102, 0);
	//数値系
	DrawFormatString(0, 20 * 0, Orange, "プレイヤー座標X:%d,Y:%d", Player.x, Player.y);
	DrawFormatString(0, 20 * 1, Orange, "ジャンプパワー:%d", Player.jump_pow);
	DrawFormatString(0, 20 * 2, Orange, "プレイヤースピードX:%d,Y:%d", Player.speed_x, Player.speed_y);

	//フラグ系
	DrawFormatString(540, 20 * 0, Orange, "ジャンプフラグ:%d", Player.jump_flag);
	DrawFormatString(540, 20 * 1, Orange, "接地判定:%d", Player.on_ground);
}