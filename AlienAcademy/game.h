
#pragma once

#if !defined(__GAME_H__)
#define __GAME_H__

// Library Includes
#include <windows.h>

// Local Includes
#include "clock.h"

// Types

// Constants

// Prototypes
class CLevel;
class CBackBuffer;
class CPlaceHolder;
class CCursor;

enum GameState {

	MENU,
	PLAY,
	CREDITS,
	GAMEOVER

};

class CGame
{
	// Member Functions
public:
	virtual ~CGame();

	virtual bool Initialise(HINSTANCE _hInstance, HWND _hWnd, int _iWidth, int _iHeight);

	virtual void Draw();
	virtual void Process(float _fDeltaTick);

	void ExecuteOneFrame();

	CClock* GetClock();
	CCursor* GetCursor();
	CPlaceHolder* GetBackGround();
	CBackBuffer* GetBackBuffer();
	CLevel* GetLevel();
	HINSTANCE GetAppInstance();
	HWND GetWindow();
	void GameOver();

	// Singleton Methods
	static CGame& GetInstance();
	static void DestroyInstance();

	int GetState() const;
	void SetState(int _iState);

protected:

private:
	CGame();
	CGame(const CGame& _kr);
	CGame& operator= (const CGame& _kr);

	// Member Variables
public:

protected:
	CCursor* m_pCursor;

	CPlaceHolder* m_pBackground;
	CClock* m_pClock;
	CLevel* m_pLevel;

	CBackBuffer* m_pBackBuffer;

	//Application data
	HINSTANCE m_hApplicationInstance;
	HWND m_hMainWindow;

	// Singleton Instance
	static CGame* s_pGame;

private:
	int m_iState;

};

#endif    // __GAME_H__

