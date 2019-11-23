#include <DxLib.h>
#include "bg.h"
#include "map.h"

void drawBG(int bg_handle, int bg2_handle, MapData Map, BackGround BG)
{
	int alpha_amount;
	alpha_amount = (((1920 * 4) + Map.draw_position_x)*-1)/4;
	if (alpha_amount < 0) { alpha_amount = 0;}
	if (alpha_amount > 255) { alpha_amount = 255; }

	DrawRectExtendGraph(BG.x1, BG.y1, 1921+BG.x1, 1081+BG.y1, 0, 0, BG_WIDTH, BG_HEIGHT, bg_handle, TRUE);
	DrawRectExtendGraph(BG.x2, BG.y2, 1921 + BG.x2, 1081 + BG.y2, 0, 0, BG_WIDTH, BG_HEIGHT, bg_handle, TRUE);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha_amount);
	DrawRectExtendGraph(BG.x1, BG.y1, 1921 + BG.x1, 1081 + BG.y1, 0, 0, BG_WIDTH, BG_HEIGHT, bg2_handle, TRUE);
	DrawRectExtendGraph(BG.x2, BG.y2, 1921 + BG.x2, 1081 + BG.y2, 0, 0, BG_WIDTH, BG_HEIGHT, bg2_handle, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,255);

	DrawRectExtendGraph(BG.tree_x, BG.tree_y, 1921 + BG.tree_x, 1081 + BG.tree_y, BG_WIDTH, 0, BG_WIDTH, BG_HEIGHT, bg_handle, TRUE);
}

void scrollBG(BackGround* BG)
{
	BG->x1 += BG->scroll_speed;
	BG->x2 += BG->scroll_speed;
	if (BG->x1 > 1920) { BG->x1 = BG->x2-1920; }
	if (BG->x1 < -1920) { BG->x1 = BG->x2 +1920; }
	if (BG->x2 > 1920) { BG->x2 = BG->x1-1920;}
	if (BG->x2 < -1920) { BG->x2 = BG->x1+1920; }
}

void scrollTree(BackGround* BG,MapData Map)
{
	BG->tree_x = 1980 + Map.draw_position_x;
}