#include "main.h"


//////////////////////////////////////////////////////////////////////////
//	各ゲームで使用するクラスインスタンスやグローバル変数はここに記述
//


<<<<<<< HEAD
//ハンドル宣言
=======
int game_scene;
>>>>>>> ruka_develop
int title_handle;
int game_handle;
int result_handle;
int sprite_handle;

//変数宣言
int gravity;
int button_timer;

//構造体実体宣言
MapData Map;
Character Player;

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
<<<<<<< HEAD
	//ハンドルへのロード
	title_handle = LoadGraph("Data/Sprite/Title.jpg");
	game_handle = LoadGraph("Data/Sprite/Game.jpg");
	result_handle = LoadGraph("Data/Sprite/Result.jpg");
	sprite_handle = LoadGraph("Data/Sprite/sprite.png");
	//変数の初期化
	game_scene = Title;
	gravity = 3;
	//構造体の初期化
	Map = { 0,0 };
	Player = { 60, 892, 0, 0, 10, 0, true, false, false, 0, true, None, 0, 0, 0 };

	SetFontSize(28);
=======
    title_handle = LoadGraph("Title.jpg");
	game_handle = LoadGraph("Game.jpg");
	result_handle = LoadGraph("Result.jpg");
	game_scene = Title;
    Player = { 60, 892, 0, 0, 10, 0, true,false, true, None, 0, 0, 0 };
    Boss= { 60, 892, 0, 0, 10, 0, true,false, true, None, 0, 0, 0 };
>>>>>>> ruka_develop
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
<<<<<<< HEAD
{
	TimeController();
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		game_scene = Result;
	}
	movePlayer(&Player);
	setPlayerCollWithChip(Map, &Player);
	affectGravity(&Player, gravity);
	exeJump(&Player, gravity, checkPressButton(&button_timer));
=======
{	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		game_scene = Result;
	}
movePlayer(&Player);
moveBoss(&Boss);
//setPlayerCollWithChip(Map, &Player);
affectGravity(&Player, gravity);
exeJump(&Player, gravity);
>>>>>>> ruka_develop
}

// ゲーム描画処理
void GameDraw(int GameTime)
{
<<<<<<< HEAD
	DrawGraph(0, 0, game_handle, true);
	drawMapChip(Map, sprite_handle);
	drawPlayer(&Player, sprite_handle);
	drawDebugString(Player, gravity,button_timer);
=======
    DrawRectGraph(0, 0, 0, 0, 192, 192, game_handle, true);
    drawBoss(&Boss,boss_handle);
>>>>>>> ruka_develop
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

