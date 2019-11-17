#include"main.h"
#include"system.h"


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
int dammy_handle;

//�ϐ��錾
int gravity;
int jump_button_timer;
int attack_button_timer;
int scene;
int shake_timer;
int shake_power;
bool shake_screen;
bool now_performance;

//�\���̎��̐錾
MapData Map;
Character Player;
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
	gate_handle = LoadGraph("Data/Sprite/gate.png");
	dammy_handle = LoadGraph("Data/Sprite/dammy.png");

	//�ϐ��̏�����
	game_scene = Title;
	gravity = 2;
	jump_button_timer = 0;
	attack_button_timer = 0;
	scene = Tutorial;
	now_performance = false;

	//�\���̂̏�����
	Map = { 0, 0, ABS_FIRST_BATTLE_LINE };
	Player = { 300, 892, Right, 0, 0, 10, 0, true, false, false, 0, true, None, 0, 0, 0, 0 };
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
	movePlayer(&Player, now_performance, X_Input);
	setPlayerCollWithChip(Map, &Player);
	affectGravity(&Player, gravity);
	exeJump(&Player, gravity, checkPressButton(&jump_button_timer, now_performance, X_Input));
	attackPlayer(&Player, checkPressAttack(&attack_button_timer, now_performance), now_performance);
	collPlayerAttack(Player, Dammy, &shake_screen, Map);
	moveMapChip(&Map);
	scrollMapChip(&Map, &Player, scene);
	changeStateFlag(&Scene, Map, Player, &scene, &now_performance);
	StateTransition(&scene, Scene);
	performanceScroll(&Map, &Player, &Scene, scene);
	shakeScreen(&shake_screen, &shake_power, &shake_timer, &Player, &Map, &Dammy);
}

// �Q�[���`�揈��
void GameDraw(int GameTime)
{
	DrawGraph(0, 0, game_handle, true);
	drawMapChip(Map, sprite_handle, shake_power);
	drawPlayer(&Player, sprite_handle, shake_power);
	drawDebugString(Player, gravity, jump_button_timer, attack_button_timer, Map, Scene, shake_timer, shake_power, shake_screen, scene);
	drawCollisionBox(Player, Dammy,Map);
	drawBattleStartLine(Map);
	drawScareCrow(Dammy, Map, dammy_handle, shake_power);
	//drawGate(gate_handle);
}

// ���U���g�X�V����
void UpdateResult(int GameTime)
{

}

// ���U���g�`�揈��
void ResultDraw(int GameTime)
{

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
