#include "main.h"


//////////////////////////////////////////////////////////////////////////
//	各ゲームで使用するクラスインスタンスやグローバル変数はここに記述
//


int game_scene;
int title_handle;
int game_handle;
int result_handle;

int gravity;
Character2 Boss;
Character Player;
//MapData Map;
//
// 定義ここまで
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//	ここからゲームの処理
//




// ゲーム開始前処理
void AfterInit(void)
{
    title_handle = LoadGraph("Title.jpg");
	game_handle = LoadGraph("Game.jpg");
	result_handle = LoadGraph("Result.jpg");
	game_scene = Title;
    Player = { 60, 892, 0, 0, 10, 0, true,false, true, None, 0, 0, 0 };
    Boss= { 60, 892, 0, 0, 10, 0, true,false, true, None, 0, 0, 0 };
}

// タイトル更新処理
void UpdateTitle(int GameTime)
{
	if (CheckHitKey(KEY_INPUT_T))
	{
		game_scene = Game;
	}

}

// タイトル描画処理
void TitleDraw(int GameTime)
{
    DrawRectGraph(0, 0, 0, 0, 192, 192, title_handle, true);
}

// ゲーム更新処理
void UpdateGame(int GameTime)
{	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		game_scene = Result;
	}
movePlayer(&Player);
moveBoss(&Boss);
//setPlayerCollWithChip(Map, &Player);
affectGravity(&Player, gravity);
exeJump(&Player, gravity);
}

// ゲーム描画処理
void GameDraw(int GameTime)
{
    DrawRectGraph(0, 0, 0, 0, 192, 192, game_handle, true);
    drawBoss(&Boss,boss_handle);
}

// リザルト更新処理
void UpdateResult(int GameTime)
{

}

// リザルト描画処理
void ResultDraw(int GameTime)
{
    DrawRectGraph(0, 0, 0, 0, 192, 192, result_handle, true);

}

// ゲーム終了処理
void DestroyGame(void)
{

}

//
//	ゲームの処理ここまで
//////////////////////////////////////////////////////////////////////////

// DirectX初期化前処理
void BeforeInit(void)
{
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);
	// ウィンドウタイトルを設定する
	SetMainWindowText(STR_WINTTL);
}

// ゲームメインループ
void MainLoop(void)
{
	unsigned int gameTime = 0;			// グローバルゲームカウンタ

	while (ProcessMessage() == 0)		// ProcessMessageが正常に処理されている間はループ
	{
		switch (game_scene)
		{
		case Title:
			UpdateTitle(gameTime);			// タイトル更新処理
			ClearDrawScreen;				// 裏画面を削除
			TitleDraw(gameTime);			// タイトル描画処理
			break;
		case Game:
			UpdateGame(gameTime);			// ゲーム更新処理
			ClearDrawScreen;				// 裏画面を削除
			GameDraw(gameTime);				// ゲーム描画処理
			break;
		case Result:
			UpdateResult(gameTime);			// リザルト更新処理
			ClearDrawScreen;				// 裏画面を削除
			ResultDraw(gameTime);			// リザルト描画処理
			break;
		}

		ScreenFlip();					// VSYNCを待つ
		// ESCキーだけは常に監視。押されたら直ちに終了
		int stick = CheckHitKey(KEY_INPUT_ESCAPE);
		if (stick == 1) break;
		gameTime++;						// ゲームカウンタを進める
	}
}

// WinMain関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	BeforeInit();						// DirectX初期化前処理
	if (DxLib_Init() == -1) return -1;	// エラーが起きたら直ちに終了
	SetGraphMode(1920, 1080, 32);		// 画面解像度を1920x1080,32bitカラーに設定
	SetDrawScreen(DX_SCREEN_BACK);		// 描画スクリーンを裏側に指定
	SetWaitVSyncFlag(TRUE);				// VSYNCを有効にする
	AfterInit();						// DirectX初期化後処理
	MainLoop();							// ゲーム本体(メインループ) 
	DxLib_End();						// ＤＸライブラリ使用の終了処理
	return 0;							// ソフトの終了
}

