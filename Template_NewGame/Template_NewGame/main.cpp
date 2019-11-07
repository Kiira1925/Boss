#include "main.h"

//////////////////////////////////////////////////////////////////////////
//	�e�Q�[���Ŏg�p����N���X�C���X�^���X��O���[�o���ϐ��͂����ɋL�q
//

int game_scene;

//�n���h���錾
int title_handle;
int game_handle;
int result_handle;
int sprite_handle;

//�ϐ��錾
int gravity;
int button_timer;

//�\���̎��̐錾
MapData Map;
Character Player;

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
	//�ϐ��̏�����
	game_scene = Title;
	gravity = 3;
	//�\���̂̏�����
	Map = { 0,0 };
	Player = { 60, 892, 0, 0, 10, 0, true, false, false, 0, true, None, 0, 0, 0 };

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
	TimeController();
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		game_scene = Result;
	}
	movePlayer(&Player);
	setPlayerCollWithChip(Map, &Player);
	affectGravity(&Player, gravity);
	exeJump(&Player, gravity, checkPressButton(&button_timer));
}

// �Q�[���`�揈��
void GameDraw(int GameTime)
{
	DrawGraph(0, 0, game_handle, true);
	drawMapChip(Map, sprite_handle);
	drawPlayer(&Player, sprite_handle);
	drawDebugString(Player, gravity,button_timer);
}

// ���U���g�X�V����
void UpdateResult(int GameTime)
{

}

// ���U���g�`�揈��
void ResultDraw(int GameTime)
{
	DrawGraph(0, 0, result_handle, true);
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
