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

class CLevel
{
	// Member Functions
public:
	CLevel();
	virtual ~CLevel();

	virtual bool Initialise(int _iWidth, int _iHeight);

	virtual void Draw();
	virtual void Process(float _fDeltaTick);

	void ResetLevel();

	void ResetScore();
	int GetScoreA() const;
	int GetScoreB() const;

	void CreateRecipe();
	void CheckGameOver();

protected:

	void ProcessCheckForWin();

	void UpdateScoreText();
	void DrawScore();
	void DrawRecipe();

	void ProcessCollisions(CPlayer* _pPlayer);

public:

protected:

private:
	CLevel(const CLevel& _kr);
	CLevel& operator= (const CLevel& _kr);

	// Member Variables
protected:
	CPlayer* m_pPlayer1;
	CPlayer* m_pPlayer2;

	std::vector<CIngredient*> m_vecFixedIngredients;

	std::vector<CIngredient*> m_vecIngredients;

	std::string m_strScoreA;
	std::string m_strScoreB;

	int m_iWidth;
	int m_iHeight;

private:

	static int m_iScoreA;
	static int m_iScoreB;

	float fTimer;

	int iIndex;
};

#endif    // __LEVEL_H__