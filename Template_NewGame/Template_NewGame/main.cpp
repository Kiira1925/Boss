#include "main.h"

//////////////////////////////////////////////////////////////////////////
//	�e�Q�[���Ŏg�p����N���X�C���X�^���X��O���[�o���ϐ��͂����ɋL�q
//

int game_scene;

int title_handle;
int game_handle;
int result_handle;

//
// ��`�����܂�
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//	��������Q�[���̏���
//

// �Q�[���J�n�O����
void AfterInit(void)
{
	title_handle = LoadGraph("Title.jpg");
	game_handle = LoadGraph("Game.jpg");
	result_handle = LoadGraph("Result.jpg");
	game_scene = Title;
}

// �^�C�g���X�V����
void UpdateTitle(int GameTime)
{
	if (CheckHitKey(KEY_INPUT_SPACE))
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
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		game_scene = Result;
	}
}

// �Q�[���`�揈��
void GameDraw(int GameTime)
{
	DrawGraph(0, 0, game_handle, true);
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
