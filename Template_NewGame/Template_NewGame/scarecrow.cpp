//#include <DxLib.h>
//#include "scarecrow.h"
//#include "map.h"
#include"system.h"
#include"main.h"


void drawScareCrow(ScareCrow dammy, MapData map, int dammy_handle, int shake_power)
{
	DrawGraph(dammy.x + map.draw_position_x + shake_power, dammy.y - shake_power, dammy_handle, TRUE);
}