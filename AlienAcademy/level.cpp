// Library Includes
#include <ctime>
// Local Includes
#include "Game.h"
#include "player.h"
//#include "alien.h"
#include "ingredient.h"
#include "utils.h"
#include "backbuffer.h"
//#include "framecounter.h"
#include "placeholder.h"
//#include "barrier.h"
//#include "resource.h"
#include "recipeManager.h"

// This Include
#include "Level.h"

// Constants
#define ALIEN_COLUMNS 10
#define ALIEN_ROWS 5

// Static Variables
int CLevel::m_iScore = 0;
int CLevel::m_iPlayerLives = 3;

// Static Function Prototypes

// Implementation

#define CHEAT_BOUNCE_ON_BACK_WALL

CLevel::CLevel()
	: m_iAliensRemaining(0)
	, m_pPlayer(0)
	, m_iWidth(0)
	, m_iHeight(0)
	, m_fpsCounter(0)
	, m_pSpecialAlien(0)
	, m_bSpecialAlien(false)
	, m_iPreviousAlienShipSpeed(20)
	, fTimer(0.0f)
{

	m_iLowestAlien[10] = (0);

}

CLevel::~CLevel() {

	/*for (int i = 0; i < ALIEN_COLUMNS; i++) {

		while (m_aliens[i].size() > 0) {

			CAlien* pBrick = m_aliens[i].at(m_aliens[i].size() - 1);

			m_aliens[i].pop_back();

			delete pBrick;

		}

	}*/

	while (m_vecEnemyBullets.size() > 0)
	{
		CIngredient* pInvader = m_vecEnemyBullets[m_vecEnemyBullets.size() - 1];
		
		m_vecEnemyBullets.pop_back();

		delete pInvader;
	}

	delete m_pPlayer;
	m_pPlayer = 0;

	//delete m_fpsCounter;
	//m_fpsCounter = 0;

}

////////////////////////////////////////////////////////////

bool CLevel::Initialise(int _iWidth, int _iHeight) 
{
	m_iWidth = _iWidth;
	m_iHeight = _iHeight - 35;

	m_pPlayer = new CPlayer();
	VALIDATE(m_pPlayer->Initialise());
	m_pPlayer->SetScreenWidth(_iWidth);
	m_pPlayer->SetScreenHeight(_iHeight);

	// Set the paddle's position to be centered on the x, 
	// and a little bit up from the bottom of the window.
	m_pPlayer->SetX(m_iWidth / 4.0f);
	m_pPlayer->SetY(m_iHeight - (2 * m_pPlayer->GetHeight() / 2));

	m_pPlayer2 = new CPlayer();
	VALIDATE(m_pPlayer2->Initialise());
	m_pPlayer2->SetLeftPlayer(false);
	m_pPlayer2->SetScreenWidth(_iWidth);
	m_pPlayer2->SetScreenHeight(_iHeight);

	// Set the paddle's position to be centered on the x, 
	// and a little bit up from the bottom of the window.
	m_pPlayer2->SetX(m_iWidth * 3.0f/ 4.0f);
	m_pPlayer2->SetY(m_iHeight - (2 * m_pPlayer2->GetHeight() / 2));

	const int kiNumAliens = 55;
	const int kiStartX = _iWidth / 6 - 35 + ALIEN_COLUMNS;
	const int kiGap = 5;

	int iCurrentX = kiStartX;
	int iCurrentY = 0.0f;



/*
	for (int i = 0; i < ALIEN_COLUMNS; i++) {

		m_aliens[i].clear();
		iCurrentY = 60;

		for (int j = 0; j < ALIEN_ROWS; j++) {

			CAlien* pAlien;

			if (j == 0)
				pAlien = new CAlien(40);
			else if (j == 1 || j == 2)
				pAlien = new CAlien(30);
			else
				pAlien = new CAlien(20);

			VALIDATE(pAlien->Initialise());

			pAlien->SetX(static_cast<float>(iCurrentX));
			pAlien->SetY(static_cast<float>(iCurrentY));

			iCurrentY += 50;

			m_aliens[i].push_back(pAlien);

		}

		iCurrentX += static_cast<int>(12 * kiGap);

		if (iCurrentX > (_iWidth / 2 + _iWidth / 4 + _iWidth / 6)) {

			iCurrentX = kiStartX;
			iCurrentY += 50;

		}

	}

	// Draw the barriers
	m_barriers.clear();

	for (int i = 0; i < 4; i++) {

		CBarrier* barrier = new CBarrier();
		barrier->Initialise();
		barrier->SetX(110.0f + (i * 175.0f));
		barrier->SetY(m_iHeight - 200.0f);

		m_barriers.push_back(barrier);

	}

	m_lifeIcons.clear();

	// Draw the lives
	for (int i = 0; i < m_iPlayerLives; i++) {

		CPlaceHolder* icon = new CPlaceHolder();
		icon->Initialise();
		icon->ChangeImage(IDB_PLAYER_LIFE, IDB_PLAYER_LIFE_MASK);
		icon->SetX(30.0f + (i * 40.0f));
		icon->SetY(m_iHeight + 10.0f);

		m_lifeIcons.push_back(icon);

	}
	
	SetAliensRemaining(ALIEN_COLUMNS * ALIEN_ROWS);
	m_fpsCounter = new CFPSCounter();
	VALIDATE(m_fpsCounter->Initialise());
	*/
	return (true);

}

////////////////////////////////////////////////////////////

void CLevel::Draw() {

	m_pPlayer->Draw();
	m_pPlayer2->Draw();

	for (unsigned int i = 0; i < m_vecEnemyBullets.size(); i++)
	{
		m_vecEnemyBullets[i]->Draw();
	}

	// Draw the life icons
	//for (unsigned int i = 0; i < m_lifeIcons.size(); i++) {

	//	m_lifeIcons[i]->Draw();

	//}

	//// Draw the barriers
	//for (unsigned int i = 0; i < m_barriers.size(); i++) {

	//	m_barriers[i]->Draw();

	//}

	//for (int i = 0; i < ALIEN_COLUMNS; i++) {

	//	for (int j = 0; j < ALIEN_ROWS; j++) {

	//		m_aliens[i].at(j)->Draw();

	//	}

	//}

	//if (m_pSpecialAlien != nullptr)
	//	m_pSpecialAlien->Draw();

	//DrawScore();

}

////////////////////////////////////////////////////////////

void CLevel::Process(float _fDeltaTick) {

	m_pPlayer->Process(_fDeltaTick);
	m_pPlayer2->Process(_fDeltaTick);

	// Bullets
	int x = (rand() % m_iWidth - 50) + 50;

	//if ((m_bCanShoot == true) && (m_fX > x) && (m_fX < (x + 1)) && (!m_bSpecial)) {
	if (fTimer > 1.0f) 
	{
		CIngredient* m_pBullet = new CIngredient();
		float fVelocity = 125.0f;
		m_pBullet->Initialise(1, x, 1.0f, fVelocity);
		//m_bCanShoot = false;
		//m_bBulletHasBeenReset = false;
		m_vecEnemyBullets.push_back(m_pBullet);

		fTimer = 0.0f;
	}
	fTimer += _fDeltaTick;

	for (unsigned int i = 0; i < m_vecEnemyBullets.size(); i++)
	{
		m_vecEnemyBullets[i]->Process(_fDeltaTick);
	}

	// Process the life icons
	//for (unsigned int i = 0; i < m_lifeIcons.size(); i++) {

	//	m_lifeIcons[i]->Process(_fDeltaTick);

	//}

	//// Process the barriers
	//for (unsigned int i = 0; i < m_barriers.size(); i++) {

	//	m_barriers[i]->Process(_fDeltaTick);

	//}

	////ProcessBulletEdgeCollision();
	//ProcessPlayerBulletCollision();
	//ProcessAlienBulletCollision();

	//ProcessCheckForWin();

	//// Check alien edge of screen
	//// Check if movement change needs to occur

	//bool bLeft = false;
	//bool bRight = false;

	//for (int i = 0; i < ALIEN_COLUMNS; i++) {

	//	for (int j = 0; j < ALIEN_ROWS; j++) {

	//		if (!m_aliens[i].at(j)->IsHit()) {

	//			// Check if aliens need to move left
	//			if (((m_aliens[i].at(j)->GetX()) + ((m_aliens[i].at(j)->GetWidth()) / 2)) > 740) {

	//				bLeft = true;
	//			}


	//			// Check if aliens need to move right
	//			if (((m_aliens[i].at(j)->GetX()) - ((m_aliens[i].at(j)->GetWidth()) / 2)) < 6) {

	//				bRight = true;
	//			}

	//		}

	//	}

	//}

	//// Adjust the bool variables for each alien accordingly
	//for (int i = 0; i < ALIEN_COLUMNS; i++) {

	//	for (int j = 0; j < ALIEN_ROWS; j++) {

	//		if (!m_aliens[i].at(j)->IsHit()) {

	//			if (bLeft == true) {

	//				m_aliens[i].at(j)->SetMoveLeft(true);
	//				m_aliens[i].at(j)->SetMoveRight(false);

	//			}
	//			else if (bRight == true) {

	//				m_aliens[i].at(j)->SetMoveLeft(false);
	//				m_aliens[i].at(j)->SetMoveRight(true);

	//			}
	//			else {

	//				m_aliens[i].at(j)->SetMoveLeft(false);
	//				m_aliens[i].at(j)->SetMoveRight(false);

	//			}

	//		}

	//	}

	//}

	//// Find lowest alien ship in each column
	//int count = 0;

	//for (int i = 0; i < ALIEN_COLUMNS; i++) {

	//	for (int j = 0; j < ALIEN_ROWS; j++) {

	//		if (!m_aliens[i].at(j)->IsHit()) {

	//			m_iLowestAlien[i] = j;

	//		}
	//		else {

	//			count++;

	//		}
	//		if (count == 5) { // Column empty

	//			m_iLowestAlien[i] = 9;

	//		}

	//	}

	//	count = 0;

	//}

	//// Set can shoot
	//for (int i = 0; i < ALIEN_COLUMNS; i++) {

	//	if (m_iLowestAlien[i] != 9) {

	//		m_aliens[i].at(m_iLowestAlien[i])->SetCanShoot();
	//	}

	//}

	//// Process the aliens
	//for (int i = 0; i < ALIEN_COLUMNS; i++) {

	//	for (int j = 0; j < ALIEN_ROWS; j++) {

	//		m_aliens[i].at(j)->Process(_fDeltaTick);

	//		if (m_aliens[i].at(j)->GetY() >= m_iHeight / 2 + 125) {

	//			CGame::GetInstance().GameOver();

	//		}

	//	}

	//}

	//// Creating a special alien
	//if ((m_iAliensRemaining == 39 || m_iAliensRemaining == 12) && !m_bSpecialAlien) {

	//	m_pSpecialAlien = new CAlien(100);
	//	m_pSpecialAlien->Initialise();
	//	m_pSpecialAlien->SetX(-30);
	//	m_pSpecialAlien->SetY(30);
	//	m_pSpecialAlien->SetShipSpeed(60);
	//	m_pSpecialAlien->SetCanShoot();
	//	m_pSpecialAlien->Process(_fDeltaTick);
	//	m_pSpecialAlien->SetSpecial();
	//	m_bSpecialAlien = true;

	//}

	//if (m_pSpecialAlien != nullptr) {

	//	m_pSpecialAlien->Process(_fDeltaTick);
	//	m_bSpecialAlien = false;

	//}

	//// Update the game's FPS
	//m_fpsCounter->CountFramesPerSecond(_fDeltaTick);

}

void CLevel::SetLives(int _iLives) {

	CLevel::m_iPlayerLives = _iLives;

}

////////////////////////////////////////////////////////////

void CLevel::ProcessPlayerBulletCollision() {

	//if (m_pPlayer->GetBullet() != nullptr) {

	//	float fBulletR = m_pPlayer->GetBullet()->GetRadius();
	//	float fBulletX = m_pPlayer->GetBullet()->GetX();
	//	float fBulletY = m_pPlayer->GetBullet()->GetY();

	//	// Bullet on barrier
	//	for (unsigned int i = 0; i < m_barriers.size(); i++) {

	//		if (!m_barriers[i]->IsHit()) {

	//			float fBarrierX = m_barriers[i]->GetX();
	//			float fBarrierY = m_barriers[i]->GetY();
	//			float fBarrierH = m_barriers[i]->GetHeight();
	//			float fBarrierW = m_barriers[i]->GetWidth();

	//			if ((fBulletX + fBulletR > fBarrierX - fBarrierW / 2) &&
	//				(fBulletX - fBulletR < fBarrierX + fBarrierW / 2) &&
	//				(fBulletY + fBulletR > fBarrierY - fBarrierH / 2) &&
	//				(fBulletY - fBulletR < fBarrierY + fBarrierH / 2))
	//			{

	//				m_pPlayer->DestroyBullet();
	//				m_barriers[i]->LoseALife();

	//				return;

	//			}

	//		}

	//	}

	//	// Bullet on alien
	//	for (int i = 0; i < ALIEN_COLUMNS; i++) {

	//		for (int j = 0; j < ALIEN_ROWS; j++) {

	//			if (!m_aliens[i].at(j)->IsHit()) {

	//				float fAlienX = m_aliens[i].at(j)->GetX();
	//				float fAlienY = m_aliens[i].at(j)->GetY();
	//				float fAlienH = m_aliens[i].at(j)->GetHeight();
	//				float fAlienW = m_aliens[i].at(j)->GetWidth();

	//				if ((fBulletX + fBulletR > fAlienX - fAlienW / 2) &&
	//					(fBulletX - fBulletR < fAlienX + fAlienW / 2) &&
	//					(fBulletY + fBulletR > fAlienY - fAlienH / 2) &&
	//					(fBulletY - fBulletR < fAlienY + fAlienH / 2))
	//				{

	//					m_iScore += m_aliens[i].at(j)->GetAwardedPoints();

	//					m_pPlayer->DestroyBullet();

	//					m_aliens[i].at(j)->SetHit(true);

	//					SetAliensRemaining(GetAliensRemaining() - 1);

	//					SetAlienShipSpeed(m_aliens[i].at(j)->GetShipSpeed() + 3.5f);

	//					return;

	//				}

	//			}

	//		}

	//	}

	//	// Special alien
	//	if (m_pSpecialAlien != nullptr) {

	//		if (!m_pSpecialAlien->IsHit()) {

	//			float fAlienX = m_pSpecialAlien->GetX();
	//			float fAlienY = m_pSpecialAlien->GetY();
	//			float fAlienH = m_pSpecialAlien->GetHeight();
	//			float fAlienW = m_pSpecialAlien->GetWidth();

	//			if ((fBulletX + fBulletR > fAlienX - fAlienW / 2) &&
	//				(fBulletX - fBulletR < fAlienX + fAlienW / 2) &&
	//				(fBulletY + fBulletR > fAlienY - fAlienH / 2) &&
	//				(fBulletY - fBulletR < fAlienY + fAlienH / 2))
	//			{

	//				m_iScore += m_pSpecialAlien->GetAwardedPoints();

	//				m_pPlayer->DestroyBullet();

	//				m_pSpecialAlien->SetHit(true);

	//				UpdateScoreText();

	//				return;

	//			}

	//		}

	//	}

	//	// Bullet on edge
	//	if (m_pPlayer->GetBullet() != nullptr) {

	//		if (m_pPlayer->GetBullet()->GetY() < -m_pPlayer->GetBullet()->GetHeight()) {

	//			m_pPlayer->DestroyBullet();

	//		}

	//	}

	//}

}

void CLevel::ProcessAlienBulletCollision() {

	//if (!m_pPlayer->IsHit()) {

	//	float fPlayerX = m_pPlayer->GetX();
	//	float fPlayerY = m_pPlayer->GetY();
	//	float fPlayerH = m_pPlayer->GetHeight();
	//	float fPlayerW = m_pPlayer->GetWidth();

	//	for (int i = 0; i < ALIEN_COLUMNS; i++) {

	//		for (int j = 0; j < ALIEN_ROWS; j++) {

	//			if (!m_aliens[i].at(j)->IsHit()) {

	//				if (m_aliens[i].at(j)->GetBullet() != nullptr) {

	//					float fBulletR = m_aliens[i].at(j)->GetBullet()->GetRadius();
	//					float fBulletX = m_aliens[i].at(j)->GetBullet()->GetX();
	//					float fBulletY = m_aliens[i].at(j)->GetBullet()->GetY();

	//					// Process the barriers
	//					for (unsigned int k = 0; k < m_barriers.size(); k++) {

	//						if (!m_barriers[k]->IsHit()) {

	//							float fBarrierX = m_barriers[k]->GetX();
	//							float fBarrierY = m_barriers[k]->GetY();
	//							float fBarrierH = m_barriers[k]->GetHeight();
	//							float fBarrierW = m_barriers[k]->GetWidth();

	//							if ((fBulletX + fBulletR > fBarrierX - fBarrierW / 2) &&
	//								(fBulletX - fBulletR < fBarrierX + fBarrierW / 2) &&
	//								(fBulletY + fBulletR > fBarrierY - fBarrierH / 2) &&
	//								(fBulletY - fBulletR < fBarrierY + fBarrierH / 2))
	//							{

	//								m_barriers[k]->LoseALife();
	//								m_aliens[i].at(j)->DestroyBullet();
	//								m_aliens[i].at(j)->SetBulletReset();
	//								return;

	//							}

	//						}

	//					}
	//					// Process the player
	//					if ((fBulletX + fBulletR > fPlayerX - fPlayerW / 2) &&
	//						(fBulletX - fBulletR < fPlayerX + fPlayerW / 2) &&
	//						(fBulletY + fBulletR > fPlayerY - fPlayerH / 2) &&
	//						(fBulletY - fBulletR < fPlayerY + fPlayerH / 2))
	//					{

	//						m_aliens[i].at(j)->DestroyBullet();
	//						m_pPlayer->SetHit(true);
	//						return;

	//					}
	//					// Process the bounds
	//					else if (m_aliens[i].at(j)->GetBullet()->GetY() > m_iHeight - m_aliens[i].at(j)->GetBullet()->GetHeight()) {

	//						m_aliens[i].at(j)->DestroyBullet();
	//						m_aliens[i].at(j)->SetBulletReset();
	//						return;

	//					}

	//				}

	//			}

	//		}

	//	}

	//}

}

////////////////////////////////////////////////////////////

void CLevel::ProcessCheckForWin() {

	/*if (m_pPlayer->IsHit()) {

		m_iPlayerLives--;

		ResetLevel();

		return;

	}
	else {

		for (int i = 0; i < ALIEN_COLUMNS; i++) {

			for (int j = 0; j < ALIEN_ROWS; j++) {

				if (!m_aliens[i].at(j)->IsHit()) {

					return;

				}

			}

		}

	}

	CGame::GetInstance().GetLevel()->NextLevel();*/

}

void CLevel::ResetScore() {

	m_iScore = 0;

}

int CLevel::GetScore() const {

	return (m_iScore);

}

void CLevel::DrawScore() {

	HDC hdc = CGame::GetInstance().GetBackBuffer()->GetBFDC();

	const int kiX = m_iWidth - 10;
	const int kiY = m_iHeight;
	SetBkMode(hdc, TRANSPARENT);

	HFONT font = CreateFontA(23, 11, 0, 0,
		FW_NORMAL, FALSE, FALSE, FALSE,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE,
		"SmackyFormula");

	SelectObject(hdc, font);
	SetTextColor(hdc, RGB(255, 255, 255));
	SetTextAlign(hdc, TA_RIGHT);
	TextOutA(hdc, kiX, kiY, m_strScore.c_str(), static_cast<int>(m_strScore.size()));
	SetTextColor(hdc, RGB(0, 0, 0));

	DeleteObject(font);

}

void CLevel::UpdateScoreText() {

	m_strScore = "SCORE: ";
	m_strScore += ToString(m_iScore);

}

////////////////////////////////////////////////////////////

void CLevel::ResetLevel() {

	//if (m_iPlayerLives <= 0) {

	//	CGame::GetInstance().GameOver();
	//	return;

	//}

	//m_lifeIcons.clear();

	//// Draw the lives
	//for (int i = 0; i < m_iPlayerLives; i++) {

	//	CPlaceHolder* icon = new CPlaceHolder();
	//	icon->Initialise();
	//	icon->ChangeImage(IDB_PLAYER_LIFE, IDB_PLAYER_LIFE_MASK);
	//	icon->SetX(30.0f + (i * 40.0f));
	//	icon->SetY(m_iHeight + 10.0f);

	//	m_lifeIcons.push_back(icon);

	//}

	m_pPlayer = new CPlayer();
	m_pPlayer->Initialise();

	// Set the paddle's position to be centered on the x, 
	// and a little bit up from the bottom of the window.
	m_pPlayer->SetX(m_iWidth / 2.0f);
	m_pPlayer->SetY(m_iHeight - (2 * m_pPlayer->GetHeight() / 2));

}

void CLevel::NextLevel() {

	Initialise(m_iWidth, m_iHeight + 35);

	SetAlienShipSpeed(m_iPreviousAlienShipSpeed + 10.0f);

}

void CLevel::SetAlienShipSpeed(float _fSpeed) {

	/*for (int i = 0; i < ALIEN_COLUMNS; i++) {

		for (int j = 0; j < ALIEN_ROWS; j++) {

			m_aliens[i].at(j)->SetShipSpeed(_fSpeed);

		}

	}*/

}

void CLevel::SetAlienBulletSpeed(float _fSpeed) {

	/*for (int i = 0; i < ALIEN_COLUMNS; i++) {

		for (int j = 0; j < ALIEN_ROWS; j++) {

			m_aliens[i].at(j)->SetBulletSpeed(_fSpeed);

		}

	}*/

}

CPlayer* CLevel::GetPlayer() const {

	return (m_pPlayer);

}

int CLevel::GetAliensRemaining() const {

	return (m_iAliensRemaining);

}

void CLevel::SetAliensRemaining(int _i) {

	m_iAliensRemaining = _i;
	UpdateScoreText();

}