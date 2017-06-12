// Library Includes
#include <ctime>

#include <windows.h>
#include <string>
#include <algorithm>
#include "Mmsystem.h"


// Local Includes
#include "Game.h"
#include "player.h"
#include "ingredient.h"
#include "utils.h"
#include "backbuffer.h"
#include "recipe.h"
#include "resource.h"

// This Include
#include "Level.h"

// Constants
#define ALIEN_COLUMNS 10
#define ALIEN_ROWS 5

// Static Variables
int CLevel::m_iScoreA = 0;
int CLevel::m_iScoreB = 0;

// Static Function Prototypes

// Implementation

#define CHEAT_BOUNCE_ON_BACK_WALL

CLevel::CLevel()
	: m_pPlayer1(0)
	, m_pPlayer2(0)
	, m_iWidth(0)
	, m_iHeight(0)
	, fTimer(0.0f)
{

}

CLevel::~CLevel()
{

	while (m_vecIngredients.size() > 0)
	{
		CIngredient* pIngredient = m_vecIngredients[m_vecIngredients.size() - 1];

		m_vecIngredients.pop_back();

		delete pIngredient;
	}

	delete m_pPlayer1;
	m_pPlayer1 = 0;

	delete m_pPlayer2;
	m_pPlayer2 = 0;

}

////////////////////////////////////////////////////////////

bool CLevel::Initialise(int _iWidth, int _iHeight)
{
	m_iWidth = _iWidth;
	m_iHeight = _iHeight - 35;

	m_pPlayer1 = new CPlayer(true);

	VALIDATE(m_pPlayer1->Initialise());
	m_pPlayer1->SetScreenWidth(_iWidth);
	m_pPlayer1->SetScreenHeight(_iHeight);

	m_pPlayer1->SetX(m_iWidth / 4.0f);
	m_pPlayer1->SetY(m_iHeight - (2 * m_pPlayer1->GetHeight() / 2));

	m_pPlayer2 = new CPlayer(false);
	VALIDATE(m_pPlayer2->Initialise());
	m_pPlayer2->SetLeftPlayer(false);
	m_pPlayer2->SetScreenWidth(_iWidth);
	m_pPlayer2->SetScreenHeight(_iHeight);

	m_pPlayer2->SetX(m_iWidth * 3.0f / 4.0f);
	m_pPlayer2->SetY(m_iHeight - (2 * m_pPlayer2->GetHeight() / 2 -35));

	const int kiNumAliens = 55;
	const int kiStartX = _iWidth / 6 - 35 + ALIEN_COLUMNS;
	const int kiGap = 5;

	int iCurrentX = kiStartX;
	int iCurrentY = 0;

	CreateRecipe();

	UpdateScoreText();


	float fVelocity = 180.0f;
	CRecipe* _recipe1 = m_pPlayer1->GetRecipe();
	int x = 0;
	std::vector<CIngredient*> _ingredients = _recipe1->getIngredients();
	for (unsigned int i = 0; i < _ingredients.size(); i++)
	{
		x = (rand() % (m_iWidth / 2 - 100)) + 50;
		int type = _ingredients[i]->GetType();

		CIngredient* _pIngredient = new CIngredient();
		_pIngredient->Initialise(type, (float)x, 1.0f, fVelocity);
		m_vecFixedIngredients.push_back(_pIngredient);
	}

	int randomIngredient = (rand() % 41);
	for (int i = 0; i <= 41; i++)
	{
		x = (rand() % (m_iWidth / 2 - 100)) + 50;
		CIngredient* _pIngredient = new CIngredient();
		_pIngredient->Initialise(i, (float)x, 1.0f, fVelocity);
		m_vecFixedIngredients.push_back(_pIngredient);
	}

	std::random_shuffle(m_vecFixedIngredients.begin(), m_vecFixedIngredients.end());

	return (true);

}

////////////////////////////////////////////////////////////

void CLevel::Draw() {

	m_pPlayer1->Draw();
	m_pPlayer2->Draw();

	for (unsigned int i = 0; i < m_vecIngredients.size(); i++)
	{
		m_vecIngredients[i]->Draw();
	}

	DrawScore();
	DrawRecipe();

}

////////////////////////////////////////////////////////////

void CLevel::Process(float _fDeltaTick)
{

	CheckGameOver();

	m_pPlayer1->Process(_fDeltaTick);
	m_pPlayer2->Process(_fDeltaTick);

	int x = (rand() % (m_iWidth / 2 - 100)) + 50;

	if (fTimer > 0.8f)
	{
		/*CIngredient* _pIngredient = new CIngredient();
		float fVelocity = 200.0f;
		int randomIngredient = (rand() % 41);
		_pIngredient->Initialise(randomIngredient, (float)x, 1.0f, fVelocity);
		m_vecIngredients.push_back(_pIngredient);

		CIngredient* _pIngredient2 = new CIngredient();
		_pIngredient2->Initialise(randomIngredient, (float)x + m_iWidth / 2, 1.0f, fVelocity);
		m_vecIngredients.push_back(_pIngredient2);*/

		if (iIndex >= m_vecFixedIngredients.size())
		{
			iIndex = 0;
		}
		////CIngredient* _pIngredient = new CIngredient();
		float fVelocity = 180.0f;
		//int randomIngredient = (rand() % 41);
		//_pIngredient->Initialise(randomIngredient, (float)x, 1.0f, fVelocity);
		//m_vecIngredients.push_back(_pIngredient);

		//CIngredient* _pIngredient2 = new CIngredient();
		//_pIngredient2->Initialise(randomIngredient, (float)x + m_iWidth / 2, 1.0f, fVelocity);
		//m_vecIngredients.push_back(_pIngredient2);

		CIngredient* ingredientFromArray = m_vecFixedIngredients[iIndex];
		int type = ingredientFromArray->GetType();

		CIngredient* _pIngredient = new CIngredient();
		_pIngredient->Initialise(type, (float)x, 1.0f, fVelocity);
		m_vecIngredients.push_back(_pIngredient);

		CIngredient* _pIngredient2 = new CIngredient();
		_pIngredient2->Initialise(type, (float)x + m_iWidth / 2, 1.0f, fVelocity);
		m_vecIngredients.push_back(_pIngredient2);

		iIndex++;

		fTimer = 0.0f;
	}
	fTimer += _fDeltaTick;

	for (unsigned int i = 0; i < m_vecIngredients.size(); i++)
	{
		m_vecIngredients[i]->Process(_fDeltaTick);
	}

	ProcessCollisions(m_pPlayer1);
	ProcessCollisions(m_pPlayer2);

	std::vector<CRecipe*> _vecRecipes;
	CRecipe* _recipe1 = m_pPlayer1->GetRecipe();
	CRecipe* _recipe2 = m_pPlayer2->GetRecipe();
	_vecRecipes.push_back(_recipe1);
	_vecRecipes.push_back(_recipe2);

	for (unsigned int i = 0; i < _vecRecipes.size(); i++)
	{
		std::vector<CIngredient*> _ingredients = _vecRecipes[i]->getIngredients();
		for (unsigned int j = 0; j < _ingredients.size(); j++)
		{
			_ingredients[j]->Process(_fDeltaTick);
		}
	}

	for (unsigned int i = 0; i < m_vecIngredients.size(); i++) 
	{
		if (m_vecIngredients[i]->GetY() > m_iHeight) {

			m_vecIngredients.erase(std::remove(m_vecIngredients.begin(), m_vecIngredients.end(), m_vecIngredients[i]), m_vecIngredients.end());
			continue;

		}

	}

}

void CLevel::ProcessCollisions(CPlayer* _pPlayer)
{
	HINSTANCE _hInstance = CGame::GetInstance().GetAppInstance();

	if (!_pPlayer->IsFinished())
	{

		float fPlayerX = _pPlayer->GetX();
		float fPlayerY = _pPlayer->GetY();
		float fPlayerH = _pPlayer->GetHeight();
		float fPlayerW = _pPlayer->GetWidth();

		for (unsigned int i = 0; i < m_vecIngredients.size(); i++)
		{
			if (m_vecIngredients[i]->IsActive())
			{
				//if (itr != nullptr) {

				float fBulletR = m_vecIngredients[i]->GetRadius();
				float fBulletX = m_vecIngredients[i]->GetX();
				float fBulletY = m_vecIngredients[i]->GetY();

				// Process the player
				if ((fBulletX + fBulletR > fPlayerX - fPlayerW / 2) &&
					(fBulletX - fBulletR < fPlayerX + fPlayerW / 2) &&
					(fBulletY + fBulletR > fPlayerY - fPlayerH / 2) &&
					(fBulletY - fBulletR < fPlayerY + fPlayerH / 2))
				{
					m_vecIngredients[i]->SetActive(false);
					//m_pPlayer->SetHit(true);

					std::vector<CIngredient*> _recipeIngredients = _pPlayer->GetRecipe()->getIngredients();

					bool _bFound = false;
					for (int j = 0; j < _recipeIngredients.size(); j++)
					{
						if (m_vecIngredients[i]->GetType() == _recipeIngredients[j]->GetType())
						{
							PlaySound(MAKEINTRESOURCE(IDR_WAVE3), _hInstance, SND_ASYNC | SND_RESOURCE);

							//mciSendString(L"Open \sound1.wav\ type waveaudio", NULL, 0, 0);
							//mciSendString(L"Play \sound1.wav", NULL, 0, 0);

							_recipeIngredients[j]->SetActive(false);
							//_pPlayer->AddToScore(100);
							_bFound = true;
						}

					}
					if (!_bFound)
					{
						PlaySound(MAKEINTRESOURCE(IDR_WAVE2), _hInstance, SND_ASYNC | SND_RESOURCE);
						//mciSendString(L"Open \sound2.wav\ type waveaudio", NULL, 0, 0);
						//mciSendString(L"Play \sound2.wav", NULL, 0, 0);

						_pPlayer->AddToScore(10);
						
					}
					UpdateScoreText();
					return;
				}
				// Process the bounds
				/*else if (m_aliens[i].at(j)->GetBullet()->GetY() > m_iHeight - m_aliens[i].at(j)->GetBullet()->GetHeight())
				{

					m_aliens[i].at(j)->DestroyBullet();
					m_aliens[i].at(j)->SetBulletReset();
					return;

				}*/

			}

		}

	}

}

////////////////////////////////////////////////////////////


void CLevel::ResetScore()
{

	m_pPlayer1->ResetScore();
	m_pPlayer2->ResetScore();

}

int CLevel::GetScoreA() const
{

	return (m_pPlayer1->GetScore());

}

int CLevel::GetScoreB() const
{

	return (m_pPlayer2->GetScore());

}

void CLevel::DrawScore()
{

	HDC hdc = CGame::GetInstance().GetBackBuffer()->GetBFDC();

	const int kiXa = m_iWidth / 2 - 10;
	const int kiXb = m_iWidth - 10;
	const int kiY = m_iHeight;
	SetBkMode(hdc, TRANSPARENT);

	HFONT font = CreateFontA(23, 11, 0, 0,
		FW_NORMAL, FALSE, FALSE, FALSE,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE,
		"SmackyFormula");

	SelectObject(hdc, font);
	SetTextColor(hdc, RGB(0, 0, 0));
	SetTextAlign(hdc, TA_RIGHT);
	TextOutA(hdc, kiXa, kiY, m_strScoreA.c_str(), static_cast<int>(m_strScoreA.size()));
	TextOutA(hdc, kiXb, kiY, m_strScoreB.c_str(), static_cast<int>(m_strScoreB.size()));
	SetTextColor(hdc, RGB(0, 0, 0));

	DeleteObject(font);

}

void CLevel::DrawRecipe()
{
	float posX = 50.0f;
	float posY = 100.0f;

	HDC hdc = CGame::GetInstance().GetBackBuffer()->GetBFDC();

	int kiX = 0;
	int kiY = 10;
	SetBkMode(hdc, TRANSPARENT);

	HFONT font = CreateFontA(23, 11, 0, 0,
		FW_NORMAL, FALSE, FALSE, FALSE,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE,
		"SmackyFormula");

	SelectObject(hdc, font);

	SetTextAlign(hdc, TA_LEFT);
	//SetTextAlign(hdc, TA_RIGHT);
	std::vector<CRecipe*> _vecRecipes;
	CRecipe* _recipe1 = m_pPlayer1->GetRecipe();
	CRecipe* _recipe2 = m_pPlayer2->GetRecipe();
	_vecRecipes.push_back(_recipe1);
	_vecRecipes.push_back(_recipe2);

	for (unsigned int i = 0; i < _vecRecipes.size(); i++)
	{
		kiY = 10;
		posY = 100.0f;

		std::string _strRecipe = _vecRecipes[i]->getName();
		SetTextColor(hdc, RGB(0, 0, 0));
		TextOutA(hdc, kiX, kiY, _strRecipe.c_str(), static_cast<int>(_strRecipe.size()));

		std::vector<CIngredient*> _ingredients = _vecRecipes[i]->getIngredients();
		for (unsigned int j = 0; j < _ingredients.size(); j++)
		{
			if (j == 0)
			{
				kiY = 40;
			}
			else
			{
				kiY += 20;
			}
			std::string _strIngredient = _ingredients[j]->GetName();
			if (_ingredients[j]->IsActive())
			{
				SetTextColor(hdc, RGB(0, 0, 0));
			}
			else
			{
				SetTextColor(hdc, RGB(200, 200, 200));
			}
			TextOutA(hdc, kiX, kiY, _strIngredient.c_str(), static_cast<int>(_strIngredient.size()));
			_ingredients[j]->SetX(posX);
			_ingredients[j]->SetY(posY);
			//_ingredients[j]->Draw();

			posY += 50.0f;
		}

		kiX = m_iWidth / 2 + 5;
		posX += m_iWidth / 2 + 50;
	}

	//SetTextColor(hdc, RGB(0, 0, 0));

	DeleteObject(font);
}

void CLevel::UpdateScoreText() {

	m_strScoreA = "Penalty: ";
	m_strScoreA += ToString(m_pPlayer1->GetScore());

	m_strScoreB = "Penalty: ";
	m_strScoreB += ToString(m_pPlayer2->GetScore());

}

////////////////////////////////////////////////////////////

void CLevel::ResetLevel() {

	//if (m_iPlayerLives <= 0) {

	//	CGame::GetInstance().GameOver();
	//	return;

	//}

	m_pPlayer1 = new CPlayer(true);
	m_pPlayer1->Initialise();

	// Set the paddle's position to be centered on the x, 
	// and a little bit up from the bottom of the window.
	m_pPlayer1->SetX(m_iWidth / 2.0f);
	m_pPlayer1->SetY(m_iHeight - (2 * m_pPlayer1->GetHeight() / 2));

}

void CLevel::CreateRecipe()
{
	int iNumberOfRecipes = 6;
	int randomRecipe = (rand() % iNumberOfRecipes);
	m_pPlayer1->SetRecipe(new CRecipe(randomRecipe));
	m_pPlayer2->SetRecipe(new CRecipe(randomRecipe));
}

void CLevel::CheckGameOver()
{
	bool bPlayer1Finshed = m_pPlayer1->IsFinished();
	bool bPlayer2Finshed = m_pPlayer2->IsFinished();

	if (bPlayer1Finshed && !bPlayer2Finshed)
	{
		if (!m_pPlayer1->GetBonusAward())
		{
			//m_pPlayer1->AddToScore(1000);
			m_pPlayer1->AddToScore(-50);
			m_pPlayer1->SetBonusAward(true);
			UpdateScoreText();
		}
	}
	if (!bPlayer1Finshed && bPlayer2Finshed)
	{
		if (!m_pPlayer2->GetBonusAward())
		{
			//m_pPlayer2->AddToScore(1000);
			m_pPlayer2->AddToScore(-50);
			m_pPlayer2->SetBonusAward(true);
			UpdateScoreText();
		}
	}
	if (bPlayer1Finshed && bPlayer2Finshed)
	{
		m_vecIngredients.clear();
		CGame::GetInstance().GameOver();
	}
}