#include "main.h"
#include "system.h"
#include "gameover.h"
#include "boss.h"


//////////////////////////////////////////////////////////////////////////
//	�e�Q�[���Ŏg�p����N���X�C���X�^���X��O���[�o���ϐ��͂����ɋL�q
//
int game_scene;

//�n���h���錾
int title_handle;
int game_handle;
int result_handle;
int sprite_handle;
int gate_handle;
int boss_handle;
int dammy_handle;
int bb_handle;

//�ϐ��錾
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

//�\���̎��̐錾
MapData Map;
Character Player;
Enemy Boss;
HitState Attack;
AfterImage AfterPlayer;
SceneFlag Scene;
ScareCrow Dammy;
XINPUT_STATE X_Input;


//
// ��`�����܂�
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//	��������Q�[���̏���
//

// �Q�[���J�n�O����
void AfterInit(void)
{
	//�n���h���ւ̃��[�h
	title_handle = LoadGraph("Data/Sprite/Title.jpg");
	game_handle = LoadGraph("Data/Sprite/Game.jpg");
	result_handle = LoadGraph("Data/Sprite/Result.jpg");
	sprite_handle = LoadGraph("Data/Sprite/sprite.png");
	boss_handle = LoadGraph("Data/Sprite/boss.png");
	gate_handle = LoadGraph("Data/Sprite/gate.png");
	dammy_handle = LoadGraph("Data/Sprite/dammy.png");
	bb_handle = LoadGraph("Data/Sprite/BlackBack.png");

	//�ϐ��̏�����
	game_scene = Title;
	gravity = 2;
	jump_button_timer = 0;
	attack_button_timer = 0;
	step_button_timer = 0;
	scene = Tutorial;
	now_performance = false;
	gate_y = -420;

	//�\���̂̏�����
	Map = { 0, 0, ABS_FIRST_BATTLE_LINE };
	Player = { 300, 892, Right, 0, 0, 10, 0, true, false, false, 0,false, 0,0,0, true, None,true, 0, 0, 0, 0, 0 };
	AfterPlayer = { 0,0 };
	Boss = { 3600, 708, 0,0, 0, 10, 0, true, false, false, 0, true, None, 0, 0, 0 };
	Dammy = { 500,912,20000 };
	Scene = { false, false, false, false, false, false, 0 };

	SetFontSize(28);
}

// �^�C�g���X�V����
void UpdateTitle(int GameTime)
{
	if (CheckHitKey(KEY_INPUT_T))
	{
		game_scene = Game;
	}
}

// �^�C�g���`�揈��
void TitleDraw(int GameTime)
{
	DrawGraph(0, 0, title_handle, true);
}

// �Q�[���X�V����
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

// �Q�[���`�揈��
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

// ���U���g�X�V����
void UpdateResult(int GameTime)
{

}

// ���U���g�`�揈��
void ResultDraw(int GameTime)
{

}

// ���U���g�X�V����
void UpdateGameOver(int GameTime)
{

}

// ���U���g�`�揈��
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

// �Q�[���I������
void DestroyGame(void)
{

}

//
//	�Q�[���̏��������܂�
//////////////////////////////////////////////////////////////////////////

// DirectX�������O����
void BeforeInit(void)
{
	// �E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);
	// �E�B���h�E�^�C�g����ݒ肷��
	SetMainWindowText(STR_WINTTL);
}

// �Q�[�����C�����[�v
void MainLoop(void)
{
	unsigned int gameTime = 0;			// �O���[�o���Q�[���J�E���^

	while (ProcessMessage() == 0)		// ProcessMessage������ɏ�������Ă���Ԃ̓��[�v
	{
		switch (game_scene)
		{
		case Title:
			UpdateTitle(gameTime);			// �^�C�g���X�V����
			ClearDrawScreen;				// ����ʂ��폜
			TitleDraw(gameTime);			// �^�C�g���`�揈��
			break;
		case Game:
			UpdateGame(gameTime);			// �Q�[���X�V����
			ClearDrawScreen;				// ����ʂ��폜
			GameDraw(gameTime);				// �Q�[���`�揈��
			break;
		case Result:
			UpdateResult(gameTime);			// ���U���g�X�V����
			ClearDrawScreen;				// ����ʂ��폜
			ResultDraw(gameTime);			// ���U���g�`�揈��
			break;
		case GameOver:
			UpdateGameOver(gameTime);		// �Q�[���I�[�o�[�X�V����
			ClearDrawScreen;				// ����ʂ��폜
			GameOverDraw(gameTime);			// �Q�[���I�[�o�[�`�揈��
			break;
		}

		ScreenFlip();					// VSYNC��҂�
		// ESC�L�[�����͏�ɊĎ��B�����ꂽ�璼���ɏI��
		int stick = CheckHitKey(KEY_INPUT_ESCAPE);
		if (stick == 1) break;
		gameTime++;						// �Q�[���J�E���^��i�߂�
	}
}

// WinMain�֐�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	BeforeInit();						// DirectX�������O����
	if (DxLib_Init() == -1) return -1;	// �G���[���N�����璼���ɏI��

	SetGraphMode(1920, 1080, 32);		// ��ʉ𑜓x��1920x1080,32bit�J���[�ɐݒ�
	SetDrawScreen(DX_SCREEN_BACK);		// �`��X�N���[���𗠑��Ɏw��
	SetWaitVSyncFlag(TRUE);				// VSYNC��L���ɂ���
	AfterInit();						// DirectX�������㏈��
	MainLoop();							// �Q�[���{��(���C�����[�v)
	DxLib_End();						// �c�w���C�u�����g�p�̏I������
	return 0;							// �\�t�g�̏I��
}
