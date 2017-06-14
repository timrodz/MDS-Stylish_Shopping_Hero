//Library Includes
#include <windows.h>
#include <windowsx.h>
#include <stdlib.h>
#include <time.h>

//Local Includes
#include "resource.h"
#include "Game.h"
#include "Clock.h"
#include "utils.h"
#include "level.h"
//#include "player.h"
#include "placeholder.h"
#include "cursor.h"
#include "backbuffer.h"

// Constants
#define WINDOW_CLASS_NAME L"BSENGGFRAMEWORK"
const int kiWidth = 1300;
const int kiHeight = 800;

// Global variables
HINSTANCE g_hInstance;
static int g_hCurrentPlayerShipSpeed;
static int g_hCurrentPlayerBulletSpeed;
static int g_hCurrentAlienShipSpeed;
static int g_hCurrentAlienBulletSpeed;

HWND ghwnd;

CBackBuffer* gpBackBuffer = 0;

BOOL CALLBACK
DebugWindowProc(HWND _hDlg, UINT _uiMsg, WPARAM _wParam, LPARAM _lParam) {

	switch (_uiMsg) {

	case WM_CLOSE:
	{

		//EndDialog(_hDlg, 0);
		return TRUE;
		break;

	}

	}

	return FALSE;

}

LRESULT CALLBACK
WindowProc(HWND _hWnd, UINT _uiMsg, WPARAM _wParam, LPARAM _lParam) {

	HINSTANCE _hInstance = CGame::GetInstance().GetAppInstance();
	switch (_uiMsg) {

	case WM_KEYUP:
	{

		switch (WPARAM(_wParam)) {

			// Change game state
		case VK_RETURN:

			if (CGame::GetInstance().GetState() == MENU) {

				switch (CGame::GetInstance().GetCursor()->GetCursorChoice()) {

				case 1:
					CGame::GetInstance().SetState(CREDITS);
					CGame::GetInstance().GetBackGround()->ChangeImage(L"Sprites\\Instructions.bmp", L"Sprites\\wallpaper story Mask.bmp");
					break;
				case 2:
					CGame::GetInstance().SetState(CREDITS);
					CGame::GetInstance().GetBackGround()->ChangeImage(L"Sprites\\wallpaper story.bmp", L"Sprites\\wallpaper story Mask.bmp");
					break;
				case 3:
					RECT _rect;
					GetClientRect(ghwnd, &_rect);
					CGame::GetInstance().Initialise(g_hInstance, ghwnd, _rect.right, _rect.bottom, gpBackBuffer);
					CGame::GetInstance().GetLevel()->Initialise(_rect.right, _rect.bottom);
					//CGame::GetInstance().GetLevel()->Initialise(kiWidth, kiHeight);
					CGame::GetInstance().GetLevel()->ResetScore();
					CGame::GetInstance().SetState(PLAY);
					CGame::GetInstance().GetBackGround()->ChangeImage(L"Sprites\\MarbleBackground.bmp", L"Sprites\\BackgroundMask.bmp");

					PlaySound(MAKEINTRESOURCE(IDR_WAVE4), _hInstance, SND_ASYNC | SND_RESOURCE);
					break;
				case 4:
					CGame::GetInstance().SetState(CREDITS);
					CGame::GetInstance().GetBackGround()->ChangeImage(L"Sprites\\Credits.bmp", L"Sprites\\BackgroundMask.bmp");
					break;
				case 5:
					PostQuitMessage(0);
					break;

				}

			}
			else if (CGame::GetInstance().GetState() == CREDITS) 
			{
				CGame::GetInstance().SetState(MENU);
				CGame::GetInstance().GetBackGround()->ChangeImage(L"Sprites\\Menu.bmp", L"Sprites\\BackgroundMask.bmp");
			}
			else if (CGame::GetInstance().GetState() == GAMEOVER) 
			{

				CGame::GetInstance().SetState(MENU);
				CGame::GetInstance().GetBackGround()->ChangeImage(L"Sprites\\Menu.bmp", L"Sprites\\BackgroundMask.bmp");
			}

			break;

		}

	}
	break;

	case WM_KEYDOWN:
	{

		switch (WPARAM(_wParam)) {

		case VK_ESCAPE:

			PostQuitMessage(0);

			return(0);

			break;
		}

	}
	break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;

		BeginPaint(_hWnd, &ps);

		if (gpBackBuffer)
		{
			gpBackBuffer->Present();
		}

		EndPaint(_hWnd, &ps);

		return 0;
	}
	break;

	case WM_DESTROY:
	{
		PostQuitMessage(0);

		return(0);
	}
	break;

	default:
		break;

	}

	return (DefWindowProc(_hWnd, _uiMsg, _wParam, _lParam));

}

HWND
CreateAndRegisterWindow(HINSTANCE _hInstance, int _iWidth, int _iHeight, const wchar_t* _pcTitle) {

	WNDCLASSEX winclass;

	winclass.cbSize = sizeof(WNDCLASSEX);
	winclass.style = CS_HREDRAW | CS_VREDRAW;
	winclass.lpfnWndProc = WindowProc;
	winclass.cbClsExtra = 0;
	winclass.cbWndExtra = 0;
	winclass.hInstance = _hInstance;
	winclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winclass.hbrBackground = static_cast<HBRUSH> (GetStockObject(BLACK_BRUSH));
	winclass.lpszMenuName = NULL;
	winclass.lpszClassName = WINDOW_CLASS_NAME;
	winclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&winclass)) {
		// Failed to register.
		return (0);
	}

	// Centering the window based on the screen's resolution
	int screenX = GetSystemMetrics(SM_CXSCREEN);
	int screenY = GetSystemMetrics(SM_CYSCREEN);

	// Center it based on the screens resolution minus the window's dimensions
	int centerX = (screenX / 2) - (kiWidth / 2) + 35;
	int centerY = (screenY / 2) - (kiHeight / 2) - 5;

	HWND hwnd = CreateWindowEx(
		NULL,
		WINDOW_CLASS_NAME,
		_pcTitle,
		WS_BORDER | WS_CAPTION | WS_SYSMENU | WS_VISIBLE,
		centerX, centerY,
		_iWidth, _iHeight,
		NULL,
		NULL,
		_hInstance,
		NULL
	);

	if (!hwnd) {
		// Failed to create.
		return (0);
	}

	return (hwnd);
}

int WINAPI
WinMain(HINSTANCE _hInstance, HINSTANCE _hPrevInstance, LPSTR _lpCmdline, int _iCmdshow) {

	MSG msg;
	RECT _rect;
	ZeroMemory(&msg, sizeof(MSG));

	HWND hwnd = CreateAndRegisterWindow(_hInstance, kiWidth, kiHeight, L"Stylish Shopping Hero v1.0.0");

	ghwnd = hwnd;

	srand((unsigned int)time(NULL));

	CGame& rGame = CGame::GetInstance();

	GetClientRect(hwnd, &_rect);

	gpBackBuffer = new CBackBuffer();
	gpBackBuffer->Initialise(ghwnd, _rect.right, _rect.bottom);

	if (!rGame.Initialise(_hInstance, hwnd, _rect.right, _rect.bottom, gpBackBuffer)) {
		// Failed
		return (0);

	}

	while (msg.message != WM_QUIT) {

		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {

			TranslateMessage(&msg);
			DispatchMessage(&msg);

		}
		else {

			rGame.ExecuteOneFrame();

		}

	}

	delete gpBackBuffer;
	gpBackBuffer = 0;


	CGame::DestroyInstance();

	return (static_cast<int>(msg.wParam));

}
