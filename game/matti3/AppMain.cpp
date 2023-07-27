#include"DxLib.h"

#include"FreamControl.h"

#include"InputControl.h"

#include"SceneManager.h"

#define SCREEN_HEIGHT   (480)
#define SCREEN_WIDTH    (640)
#define SCREEN_COLORBIT (32)
#define FONT_SIZE       (20)

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_
	LPSTR lpCmdLine, _In_ int nShowCmd)
{
	SetMainWindowText("Match 3 Puzzle");

	ChangeWindowMode(TRUE);
	
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLORBIT);

	if (DxLib_Init() == D_ERROR)
	{
		return D_ERROR;
	}

	FreamControl_Initialize();
	Input_Initialize();

	if (SceneManager_Initialize(E_TITLE) == D_ERROR)
	{
		return D_ERROR;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	SetFontSize(FONT_SIZE);

	while (ProcessMessage() != D_ERROR && Input_Escape() == FALSE)
	{
		Input_Update();

		SceneManager_Update();

		ClearDrawScreen();

		SceneManager_Draw();

		FreamControl_Update();

		ScreenFlip();

	}

		DxLib_End();

	return 0;
}