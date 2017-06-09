#pragma once

#if !defined(__PLAYER_H__)
#define __PLAYER_H__

// Library Includes

// Local Includes
#include "entity.h"
#include "Sprite.h"

// Types
class CBullet;
class CRecipe;

// Constants

// Prototypes
class CPlayer : public CEntity
{
	// Member Functions
public:
	CPlayer(bool _player1);
	virtual ~CPlayer();

	virtual bool Initialise();

	virtual void Draw();
	virtual void Process(float _fDeltaTick);

	void SetLeftPlayer(bool _b);
	void SetScreenWidth(int _iWidth);
	void SetScreenHeight(int _iHeight);

	int GetScore() { return m_iScore; }
	void AddToScore(int _iScore) { m_iScore += _iScore; }
	void ResetScore() { m_iScore = 0; }
	CRecipe* GetRecipe();
	void SetRecipe(CRecipe* _recipe);
	bool IsFinished() { return m_bFinished; }
	bool GetBonusAward() { return m_bBonusAwarded; }
	void SetBonusAward(bool _bBonusAward) { m_bBonusAwarded = _bBonusAward; }
	void CheckRecipe();

private:
	CPlayer(const CPlayer& _kr);
	CPlayer& operator= (const CPlayer& _kr);

	// Member Variables
private:

	float m_fSpeed;

	bool m_bLeftPlayer;

	int m_iScreenWidth;
	int m_iScreenHeight;

	int m_iScore;
	CRecipe* m_Recipe;
	bool m_bFinished;
	bool m_bBonusAwarded;

	bool m_bPlayer1;
};

#endif    // __PLAYER_H__
