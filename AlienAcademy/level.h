#pragma once

#if !defined(__LEVEL_H__)
#define __LEVEL_H__

// Library Includes
#include <vector>
#include <string>

// Local Includes

// Types

// Constants

// Prototypes
class CIngredient;
class CPlayer;
class CAlien;
class CBarrier;
class CFPSCounter;
class CPlaceHolder;

class CLevel
{
	// Member Functions
public:
	CLevel();
	virtual ~CLevel();

	virtual bool Initialise(int _iWidth, int _iHeight);

	virtual void Draw();
	virtual void Process(float _fDeltaTick);

	void SetLives(int _iLives);

	void ResetLevel();
	void NextLevel();
	void SetAlienShipSpeed(float _fSpeed);
	void SetAlienBulletSpeed(float _fSpeed);

	void ResetScore();
	int GetScore() const;

protected:
	void ProcessPlayerBulletCollision();
	void ProcessAlienBulletCollision();

	void ProcessCheckForWin();

	void UpdateScoreText();
	void DrawScore();

public:
	CPlayer* GetPlayer() const;

protected:
	int GetAliensRemaining() const;
	void SetAliensRemaining(int _i);

private:
	CLevel(const CLevel& _kr);
	CLevel& operator= (const CLevel& _kr);

	// Member Variables
protected:
	CPlayer* m_pPlayer;
	CPlayer* m_pPlayer2;
	std::vector<CAlien*> m_aliens[11];
	CAlien* m_pSpecialAlien;
	bool m_bSpecialAlien;

	std::vector<CIngredient*> m_vecEnemyBullets;

	CFPSCounter* m_fpsCounter;

	std::string m_strScore;

	int m_iWidth;
	int m_iHeight;

	int m_iAliensRemaining;

	static int m_iPlayerLives;

	int m_iLowestAlien[10];

private:
	int m_iPreviousAlienShipSpeed;

	static int m_iScore;
	std::vector<CBarrier*> m_barriers;
	std::vector<CPlaceHolder*> m_lifeIcons;

	float fTimer;
};

#endif    // __LEVEL_H__