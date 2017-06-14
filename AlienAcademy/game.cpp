// Library Includes

// Local Includes
#include "Clock.h"
#include "Level.h"
#include "BackBuffer.h"
#include "utils.h"
#include "placeholder.h"
#include "resource.h"
#include "cursor.h"

// This Include
#include "Game.h"

// Static Variables
CGame* CGame::s_pGame = 0;

// Static Function Prototypes

// Implementation

CGame::CGame()
	: m_pLevel(0)
	, m_pClock(0)
	, m_hApplicationInstance(0)
	, m_hMainWindow(0)
	, m_pBackBuffer(0)
{

	m_iState = MENU;

}

CGame::~CGame() {

	delete m_pLevel;
	m_pLevel = 0;

	//delete m_pBackBuffer;
	//m_pBackBuffer = 0;

	delete m_pClock;
	m_pClock = 0;

	delete m_pCursor;
	m_pCursor = 0;

	delete m_pBackground;
	m_pBackground = 0;

}

bool CGame::Initialise(HINSTANCE _hInstance, HWND _hWnd, int _iWidth, int _iHeight, CBackBuffer* _pBackBuffer)
{
	PlaySound(MAKEINTRESOURCE(IDR_WAVE1), _hInstance, SND_ASYNC | SND_RESOURCE | SND_LOOP);

	ShowCursor(true);

	m_hApplicationInstance = _hInstance;
	m_hMainWindow = _hWnd;

	m_pClock = new CClock();
	VALIDATE(m_pClock->Initialise());
	m_pClock->Process();

	m_pBackBuffer = _pBackBuffer;
	//m_pBackBuffer = new CBackBuffer();
	//VALIDATE(m_pBackBuffer->Initialise(_hWnd, _iWidth, _iHeight));

	m_pLevel = new CLevel();
	VALIDATE(m_pLevel->Initialise(_iWidth, _iHeight));

	m_pCursor = new CCursor(5);
	VALIDATE(m_pCursor->Initialise());
	m_pCursor->SetX(375);
	m_pCursor->SetY(400);

	m_pBackground = new CPlaceHolder();
	VALIDATE(m_pBackground->Initialise());

	m_pBackground->SetX((float)_iWidth / 2);
	m_pBackground->SetY((float)_iHeight / 2);

	return (true);
}

void
CGame::Draw() {

	m_pBackBuffer->Clear();

	m_pBackground->Draw();

	switch (m_iState) {

	case MENU:
		m_pCursor->Draw();
		break;
	case PLAY:
		m_pLevel->Draw();
		break;
	case GAMEOVER:

		HDC hdc = CGame::GetInstance().GetBackBuffer()->GetBFDC();

		SetBkMode(hdc, TRANSPARENT);

		std::string m_strScoreA = "Player 1: " + std::to_string(m_pLevel->GetScoreA());
		std::string m_strScoreB = "Player 2: " + std::to_string(m_pLevel->GetScoreB());

		HFONT font = CreateFontA(90, 54, 0, 0,
			FW_NORMAL, FALSE, FALSE, FALSE,
			ANSI_CHARSET, OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
			DEFAULT_PITCH | FF_DONTCARE,
			"SmackyFormula");

		SelectObject(hdc, font);
		SetTextColor(hdc, RGB(0, 0, 0));
		SetTextAlign(hdc, TA_CENTER);
		TextOutA(hdc, (int) m_pBackground->GetWidth() / 2, 250, m_strScoreA.c_str(), static_cast<int>(m_strScoreA.size()));
		TextOutA(hdc, (int)m_pBackground->GetWidth() / 2, 350, m_strScoreB.c_str(), static_cast<int>(m_strScoreB.size()));
		SetTextColor(hdc, RGB(0, 0, 0));

		std::string m_strGameOver;
		std::string m_strPressEnter = "***press enter***";

		if (m_pLevel->GetScoreA() > m_pLevel->GetScoreB())
		{
			m_strGameOver = "Player 2 Wins!";
		}
		else if (m_pLevel->GetScoreA() < m_pLevel->GetScoreB())
		{
			m_strGameOver = "Player 1 Wins!";
		}
		else
		{
			m_strGameOver = "Draw!";
		}

		TextOutA(hdc, (int)m_pBackground->GetWidth() / 2, 0, m_strGameOver.c_str(), static_cast<int>(m_strGameOver.size()));
		TextOutA(hdc, (int)m_pBackground->GetWidth() / 2, 650, m_strPressEnter.c_str(), static_cast<int>(m_strPressEnter.size()));

		

		DeleteObject(font);

		break;

	}

	m_pBackBuffer->Present();
}

void CGame::Process(float _fDeltaTick) 
{
	m_pBackground->Process(_fDeltaTick);

	switch (m_iState) 
	{
	case MENU:
		m_pCursor->Process(_fDeltaTick);
		break;
	case PLAY:
		m_pLevel->Process(_fDeltaTick);
		break;
	case GAMEOVER:
//		m_pLevel->SetLives(3);
		break;
	}
}

void
CGame::ExecuteOneFrame() {

	float fDT = m_pClock->GetDeltaTick();

	Process(fDT);
	Draw();

	m_pClock->Process();

	Sleep(2);

}

CClock*
CGame::GetClock() {

	return (m_pClock);

}

CCursor*
CGame::GetCursor() {

	return (m_pCursor);

}

CPlaceHolder*
CGame::GetBackGround() {

	return (m_pBackground);

}

CBackBuffer*
CGame::GetBackBuffer() {

	return (m_pBackBuffer);

}

CLevel*
CGame::GetLevel() {

	return (m_pLevel);

}

HINSTANCE
CGame::GetAppInstance() {

	return (m_hApplicationInstance);

}

HWND
CGame::GetWindow() {

	return (m_hMainWindow);

}

void CGame::GameOver() 
{

	m_pBackground->ChangeImage(L"Sprites\\Game Over.bmp", L"Sprites\\BackgroundMask.bmp");
	m_iState = GAMEOVER;

}

int
CGame::GetState() const {

	return (m_iState);

}

void CGame::SetState(int _iState) {

	m_iState = _iState;

}

CGame&
CGame::GetInstance() {

	if (s_pGame == 0) {
		s_pGame = new CGame();
	}

	return (*s_pGame);
}

void
CGame::DestroyInstance() {

	delete s_pGame;
	s_pGame = 0;

}