#include <DxLib.h>
#include "bg.h"
#include "map.h"

void drawBG(int bg_handle, MapData Map, BackGround BG)
{
	int alpha_tree_amount;
	int alpha_temple_amount;
	alpha_tree_amount = (((1920 * 2.5) + Map.draw_position_x)*-1) / 8;
	alpha_temple_amount = (((1920 * 5.5) + Map.draw_position_x)*-1) / 8;
	if (alpha_tree_amount < 0) { alpha_tree_amount = 0; }
	if (alpha_tree_amount > 255) { alpha_tree_amount = 255; }
	if (alpha_temple_amount < 0) { alpha_temple_amount = 0; }
	if (alpha_temple_amount > 255) { alpha_temple_amount = 255; }

	DrawRectExtendGraph(BG.x1, BG.y1, 1921 + BG.x1, 1081 + BG.y1, 0, 0, BG_WIDTH, BG_HEIGHT, bg_handle, TRUE);
	DrawRectExtendGraph(BG.x2, BG.y2, 1921 + BG.x2, 1081 + BG.y2, 0, 0, BG_WIDTH, BG_HEIGHT, bg_handle, TRUE);
	DrawRectExtendGraph(BG.x1, BG.y1+80, 1921 + BG.x1, 1081 + BG.y1, BG_WIDTH * 3, 0, BG_WIDTH, BG_HEIGHT, bg_handle, TRUE);
	DrawRectExtendGraph(BG.x2, BG.y2+80, 1921 + BG.x2, 1081 + BG.y2, BG_WIDTH * 3, 0, BG_WIDTH, BG_HEIGHT, bg_handle, TRUE);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha_tree_amount);
	DrawRectExtendGraph(BG.x1, BG.y1, 1921 + BG.x1, 1081 + BG.y1, BG_WIDTH, 0, BG_WIDTH, BG_HEIGHT, bg_handle, TRUE);
	DrawRectExtendGraph(BG.x2, BG.y2, 1921 + BG.x2, 1081 + BG.y2, BG_WIDTH, 0, BG_WIDTH, BG_HEIGHT, bg_handle, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha_temple_amount);
	DrawRectExtendGraph(BG.x1, BG.y1, 1921 + BG.x1, 1081 + BG.y1, BG_WIDTH * 2, 0, BG_WIDTH, BG_HEIGHT, bg_handle, TRUE);
	DrawRectExtendGraph(BG.x2, BG.y2, 1921 + BG.x2, 1081 + BG.y2, BG_WIDTH * 2, 0, BG_WIDTH, BG_HEIGHT, bg_handle, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

	DrawRectExtendGraph(BG.tree_x, BG.tree_y, 1921 + BG.tree_x, 1081 + BG.tree_y, BG_WIDTH * 5, 0, BG_WIDTH, BG_HEIGHT, bg_handle, TRUE);
	DrawRectExtendGraph(BG.temple_x, BG.temple_y, 1921 + BG.temple_x, 1081 + BG.temple_y, BG_WIDTH * 4, 0, BG_WIDTH, BG_HEIGHT, bg_handle, TRUE);
}

void scrollBG(BackGround* BG)
{
	BG->x1 += BG->scroll_speed;
	BG->x2 += BG->scroll_speed;
	if (BG->x1 > 1920) { BG->x1 = BG->x2 - 1920; }
	if (BG->x1 < -1920) { BG->x1 = BG->x2 + 1920; }
	if (BG->x2 > 1920) { BG->x2 = BG->x1 - 1920; }
	if (BG->x2 < -1920) { BG->x2 = BG->x1 + 1920; }
}

void scrollTreeAndTemple(BackGround* BG, MapData Map)
{
	BG->tree_x = 7680 + Map.draw_position_x;
	BG->temple_x = 13440 + Map.draw_position_x;
}