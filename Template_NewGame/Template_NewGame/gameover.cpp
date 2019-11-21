#include <DxLib.h>
#include "gameover.h"

void drawBB(int bb_handle, int* bb_transparency)
{
	if (*bb_transparency != BB_TRANSPARENCY_MAX) { SetDrawBlendMode(DX_BLENDMODE_ALPHA, *bb_transparency); }
	DrawGraph(0, 0, bb_handle, true);

	if (*bb_transparency < BB_TRANSPARENCY_MAX) { *bb_transparency += 3; }
	if (*bb_transparency > BB_TRANSPARENCY_MAX) { *bb_transparency = BB_TRANSPARENCY_MAX; }

	if (*bb_transparency != BB_TRANSPARENCY_MAX) { SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255); }
}