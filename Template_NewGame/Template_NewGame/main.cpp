#include "main.h"
#include "system.h"
#include "gameover.h"
#include "boss.h"


//////////////////////////////////////////////////////////////////////////
//	各ゲームで使用するクラスインスタンスやグローバル変数はここに記述
//
int game_scene;

//ハンドル宣言
int title_handle;
int game_handle;
int result_handle;
int sprite_handle;
int gate_handle;
int boss_handle;
int dammy_handle;
int bb_handle;

//変数宣言
int gravity;
int jump_button_timer;
int attack_button_timer;
int step_button_timer;
int scene;
int shake_timer;
int shake_power_x;
int shake_power_y;
bool shake_screen;
bool now_performance;
int gate_y;
int gate_speed;
int bb_transparency;

//構造体実体宣言
MapData Map;
Character Player;
Enemy Boss;
HitState Attack;
AfterImage AfterPlayer;
SceneFlag Scene;
ScareCrow Dammy;
XINPUT_STATE X_Input;


//
// 定義ここまで
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//	ここからゲームの処理
//

// ゲーム開始前処理
void AfterInit(void)
{
	//ハンドルへのロード
	title_handle = LoadGraph("Data/Sprite/Title.jpg");
	game_handle = LoadGraph("Data/Sprite/Game.jpg");
	result_handle = LoadGraph("Data/Sprite/Result.jpg");
	sprite_handle = LoadGraph("Data/Sprite/sprite.png");
	boss_handle = LoadGraph("Data/Sprite/boss.png");
	gate_handle = LoadGraph("Data/Sprite/gate.png");
	dammy_handle = LoadGraph("Data/Sprite/dammy.png");
	bb_handle = LoadGraph("Data/Sprite/BlackBack.png");

	//変数の初期化
	game_scene = Title;
	gravity = 2;
	jump_button_timer = 0;
	attack_button_timer = 0;
	step_button_timer = 0;
	scene = Tutorial;
	now_performance = false;
	gate_y = -420;

	//構造体の初期化
	Map = { 0, 0, ABS_FIRST_BATTLE_LINE };
	Player = { 300, 892, Right, 0, 0, 10, 0, true, false, false, 0,false, 0,0,0, true, None,true, 0, 0, 0, 0, 0 };
	AfterPlayer = { 0,0 };
	Boss = { 3600, 708, 0,0, 0, 10, 0, true, false, false, 0, true, None, 0, 0, 0 };
	Dammy = { 500,912,20000 };
	Scene = { false, false, false, false, false, false, 0 };

	SetFontSize(28);
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
	DrawGraph(0, 0, title_handle, true);
}

// ゲーム更新処理
void UpdateGame(int GameTime)
{
	GetJoypadXInputState(DX_INPUT_PAD1, &X_Input);
	TimeController();
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		game_scene = Result;
	}
	if (CheckHitKey(KEY_INPUT_END))
	{
		game_scene = GameOver;
	}
	movePlayer(&Player, now_performance, X_Input);
	moveBoss(Player, &Boss);
	setPlayerCollWithChip(Map, &Player);
	setBossCollWithChip(Map, &Boss);
	affectGravity(&Player, gravity);
	affectGravity(&Boss, gravity);
	exeJump(&Player, Map, gravity, checkPressButton(&jump_button_timer, now_performance, X_Input));
	exeJump(&Boss, gravity, checkPressButton(&jump_button_timer, now_performance, X_Input));
	attackPlayer(&Player, checkPressAttack(&attack_button_timer, now_performance), checkPressStep(&step_button_timer, now_performance), now_performance);
	collPlayerAttack(Player, Dammy, &shake_screen, Map, &Attack);
	//moveMapChip(&Map);
	scrollMapChip(&Map, &Player, &Boss, scene);
	changeStateFlag(&Scene, Map, Player, &scene, &now_performance);
	StateTransition(&scene, Scene);
	performanceScroll(&Map, &Player, &Boss, &Scene, scene);
	shakeScreen(&shake_screen, &shake_power_x, &shake_power_y, &shake_timer, &Player, &Map, &Dammy);
	savePlayerPos(Player, &AfterPlayer);
	dropGate(&gate_y, Scene, gravity, &gate_speed, &shake_screen);
}

// ゲーム描画処理
void GameDraw(int GameTime)
{
	DrawGraph(0 + shake_power_x, 0 + shake_power_y, game_handle, true);
	drawAfterImages(Player, AfterPlayer, shake_power_x, shake_power_y, sprite_handle);
	drawMapChip(Map, sprite_handle, shake_power_x, shake_power_y);
	drawPlayer(&Player, sprite_handle, shake_power_x, shake_power_y);
	drawDebugString(Player, gravity, jump_button_timer, attack_button_timer, Map, Scene, shake_timer, shake_power_x, shake_screen, scene, AfterPlayer, gate_y, gate_speed, Boss);
	drawCollisionBox(Player, Dammy, Map);
	drawBattleStartLine(Map);
	drawScareCrow(Dammy, Map, dammy_handle, shake_power_x, shake_power_y);
	drawEffect(Player, sprite_handle, Map);
	drawGate(gate_handle, gate_y, shake_power_x, shake_power_y);
	drawBoss(&Boss, boss_handle, shake_power_x, shake_power_y);
}

// リザルト更新処理
void UpdateResult(int GameTime)
{

}

// リザルト描画処理
void ResultDraw(int GameTime)
{

}

// リザルト更新処理
void UpdateGameOver(int GameTime)
{

}

// リザルト描画処理
void GameOverDraw(int GameTime)
{
	DrawGraph(0 + shake_power_x, 0 + shake_power_y, game_handle, true);
	drawAfterImages(Player, AfterPlayer, shake_power_x, shake_power_y, sprite_handle);
	drawMapChip(Map, sprite_handle, shake_power_x, shake_power_y);
	drawPlayer(&Player, sprite_handle, shake_power_x, shake_power_y);
	drawDebugString(Player, gravity, jump_button_timer, attack_button_timer, Map, Scene, shake_timer, shake_power_x, shake_screen, scene, AfterPlayer, gate_y, gate_speed, Boss);
	drawBattleStartLine(Map);
	drawScareCrow(Dammy, Map, dammy_handle, shake_power_x, shake_power_y);
	drawEffect(Player, sprite_handle, Map);
	drawBB(bb_handle, &bb_transparency);
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
		case GameOver:
			UpdateGameOver(gameTime);		// ゲームオーバー更新処理
			ClearDrawScreen;				// 裏画面を削除
			GameOverDraw(gameTime);			// ゲームオーバー描画処理
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
