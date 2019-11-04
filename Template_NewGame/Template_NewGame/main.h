#pragma once

// インクルード
#include <windows.h>
#include <DxLib.h>
#include "map.h"
#include "player.h"
#include "system.h"

// 定数定義
#define STR_WINTTL				"DXLIB" // ウィンドウタイトル（任意に設定）
#define STR_MSGTTL_ASKFS		"起動処理"
#define STR_MSG_ASKFS			"フルスクリーンで起動しますか？"

// 構造体定義
enum GAME_SCENE{Title,Game,Result};


// 関数プロトタイプ宣言

