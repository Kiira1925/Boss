#include <DxLib.h>
#include "system.h"

void drawDebugString(Character Player, int gravity,int button_timer)
{
	int Orange = GetColor(255, 102, 0);
	//数値系
	DrawFormatString(0, 20 * 0, Orange, "プレイヤー座標X:%d,Y:%d", Player.x, Player.y);
	DrawFormatString(0, 20 * 1, Orange, "プレイヤースピードX:%d,Y:%d", Player.speed_x, Player.speed_y);
	DrawFormatString(0, 20 * 2, Orange, "ジャンプパワー:%d", Player.jump_pow);
	DrawFormatString(0, 20 * 3, Orange, "ボタンタイマー:%d", button_timer);

	//フラグ系
	DrawFormatString(540, 20 * 0, Orange, "ジャンプフラグ:%d", Player.jump_flag);
	DrawFormatString(540, 20 * 1, Orange, "エアジャンプフラグ:%d", Player.air_jump_flag);
	DrawFormatString(540, 20 * 2, Orange, "接地判定:%d", Player.on_ground);
}

//テスト関数　実装は(多分)しない
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