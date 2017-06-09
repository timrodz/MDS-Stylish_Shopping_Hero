// Library Includes

// Local Includes
//#include "resource.h"
#include "utils.h"
#include "recipe.h"
#include "ingredient.h"

// This Include
#include "player.h"

// Static Variables

// Static Function Prototypes

// Implementation

CPlayer::CPlayer(bool _player1) :
	m_fSpeed(500),
	m_bLeftPlayer(true),
	m_iScore(0),
	m_bFinished(false),
	m_bBonusAwarded(false)
{
	m_bPlayer1 = _player1;
}

CPlayer::~CPlayer()
{
	delete m_Recipe;
	m_Recipe = 0;
}

bool CPlayer::Initialise() 
{
	if (m_bPlayer1)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\shopping_hero.bmp", L"Sprites\\shopping_hero_mask.bmp"));
	}	
	else
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\shopping hero 2.bmp", L"Sprites\\shopping hero 2_mask.bmp"));
	}
		

	return (true);

}

void CPlayer::Draw() 
{

	CEntity::Draw();

}

void CPlayer::Process(float _fDeltaTick) 
{
	if (!m_bFinished) {

		CheckRecipe();

		if (!m_bLeftPlayer)
		{

			float fHalfPaddleW = m_pSprite->GetWidth() / 2.0f;

			if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {

				m_pSprite->Deinitialise();
				if (m_bPlayer1)
				{
					m_pSprite->Initialise(L"Sprites\\shopping_hero_RIGHT.bmp", L"Sprites\\shopping_hero_mask_RIGHT.bmp", 0, 0);
				}
				else
				{
					m_pSprite->Initialise(L"Sprites\\shopping hero 2.bmp", L"Sprites\\shopping hero 2_mask.bmp", 0, 0);
				}
					
				m_fX += m_fSpeed * _fDeltaTick;

			}
			else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {

				m_pSprite->Deinitialise();
				if (m_bPlayer1)
				{
					m_pSprite->Initialise(L"Sprites\\shopping_hero.bmp", L"Sprites\\shopping_hero_mask.bmp", 0, 0);
				}
				else 
				{
					m_pSprite->Initialise(L"Sprites\\shopping hero 2.bmp", L"Sprites\\shopping hero 2_mask.bmp", 0, 0);
				}
				m_fX -= m_fSpeed * _fDeltaTick;

			}
			else
			{
				//m_pSprite->Deinitialise();
				//m_pSprite->Initialise(L"Sprites\\shopping_hero.bmp", L"Sprites\\shopping_hero_mask.bmp", 0, 0);
			}

			if (m_fX - fHalfPaddleW <= m_iScreenWidth / 2) {

				m_fX = fHalfPaddleW + m_iScreenWidth/2;

			}
			else if (m_fX + fHalfPaddleW >= m_iScreenWidth) {

				m_fX = m_iScreenWidth - fHalfPaddleW;

			}
		}
		else
		{

			float fHalfPaddleW = m_pSprite->GetWidth() / 2.0f;

			if (GetAsyncKeyState(68) & 0x8000) {

				m_pSprite->Deinitialise();
				m_pSprite->Initialise(L"Sprites\\shopping_hero_RIGHT.bmp", L"Sprites\\shopping_hero_mask_RIGHT.bmp", 0, 0);
				m_fX += m_fSpeed * _fDeltaTick;

			}
			else if (GetAsyncKeyState(65) & 0x8000) {

				m_pSprite->Deinitialise();
				m_pSprite->Initialise(L"Sprites\\shopping_hero.bmp", L"Sprites\\shopping_hero_mask.bmp", 0, 0);
				m_fX -= m_fSpeed * _fDeltaTick;

			}
			else
			{
				//m_pSprite->Deinitialise();
				//m_pSprite->Initialise(L"Sprites\\shopping_hero.bmp", L"Sprites\\shopping_hero_mask.bmp", 0, 0);
			}

			if (m_fX - fHalfPaddleW <= 0) {

				m_fX = fHalfPaddleW;

			}
			else if (m_fX + fHalfPaddleW >= m_iScreenWidth/2 ) {

				m_fX = m_iScreenWidth / 2 - fHalfPaddleW;

			}
		}

		CEntity::Process(_fDeltaTick);

	}

}

void CPlayer::SetLeftPlayer(bool _b)
{
	m_bLeftPlayer = _b;
}

void CPlayer::SetScreenWidth(int _iWidth)
{
	m_iScreenWidth = _iWidth;
}

void CPlayer::SetScreenHeight(int _iHeight)
{
	m_iScreenHeight = _iHeight;
}

CRecipe* CPlayer::GetRecipe() 
{ 
	return m_Recipe; 
}

void CPlayer::SetRecipe(CRecipe* _recipe)
{
	m_Recipe = _recipe;
}

void CPlayer::CheckRecipe()
{
	std::vector<CIngredient*> _vecIngredients = m_Recipe->getIngredients();
	for (int i = 0; i < _vecIngredients.size(); i++)
	{
		if (_vecIngredients[i]->IsActive())
		{
			m_bFinished = false;
			return;
		}
	}
	m_bFinished = true;
}