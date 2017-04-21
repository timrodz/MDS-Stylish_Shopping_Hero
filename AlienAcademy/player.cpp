// Library Includes

// Local Includes
//#include "resource.h"
#include "utils.h"
//#include "bullet.h"

// This Include
#include "player.h"

// Static Variables

// Static Function Prototypes

// Implementation

CPlayer::CPlayer() :
	m_fSpeed(550),
	m_fBulletSpeed(750),
	m_bCanShoot(true),
	m_bHit(false),
	m_bLeftPlayer(true)
{}

CPlayer::~CPlayer()
{}

bool CPlayer::Initialise() 
{
	//VALIDATE(CEntity::Initialise(IDB_SHIP_PLAYER_SPRITE, IDB_SHIP_PLAYER_MASK));
	VALIDATE(CEntity::Initialise(L"Sprites\\shopping_hero.bmp", L"Sprites\\shopping_hero_mask.bmp"));

	return (true);

}

void CPlayer::Draw() {

	if (!m_bHit) {

		/*if (m_pBullet != nullptr)
			m_pBullet->Draw();*/

		CEntity::Draw();

	}

}

void CPlayer::Process(float _fDeltaTick) {

	if (!m_bHit) {

		if (!m_bLeftPlayer)
		{
			if (m_bCanShoot && GetAsyncKeyState(VK_SPACE) & 0x8000) {

				/*m_pBullet = new CBullet();
				m_pBullet->Initialise(0, m_fX, m_fY - 28, GetBulletSpeed());*/

				m_bCanShoot = false;

			}

			float fHalfPaddleW = m_pSprite->GetWidth() / 2.0f;

			if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {

				m_pSprite->Deinitialise();
				//m_pSprite->Initialise(IDB_SHIP_PLAYER_RIGHT_SPRITE, IDB_SHIP_PLAYER_RIGHT_MASK);
				//m_pSprite->Initialise(L"Sprites\\shipPlayerRightSprite.bmp", L"Sprites\\shipPlayerRightMask.bmp", 0, 0);
				m_pSprite->Initialise(L"Sprites\\shopping_hero.bmp", L"Sprites\\shopping_hero_mask.bmp", 0, 0);
				m_fX += m_fSpeed * _fDeltaTick;

			}
			else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {

				m_pSprite->Deinitialise();
				//m_pSprite->Initialise(IDB_SHIP_PLAYER_LEFT_SPRITE, IDB_SHIP_PLAYER_LEFT_MASK);
				//m_pSprite->Initialise(L"Sprites\\shipPlayerLeftSprite.bmp", L"Sprites\\shipPlayerLeftMask.bmp", 0, 0);
				m_pSprite->Initialise(L"Sprites\\shopping_hero.bmp", L"Sprites\\shopping_hero_mask.bmp", 0, 0);
				m_fX -= m_fSpeed * _fDeltaTick;

			}
			else
			{
				m_pSprite->Deinitialise();
				//m_pSprite->Initialise(IDB_SHIP_PLAYER_SPRITE, IDB_SHIP_PLAYER_MASK);
				//m_pSprite->Initialise(L"Sprites\\shipPlayerSprite.bmp", L"Sprites\\shipPlayerMask.bmp", 0, 0);
				m_pSprite->Initialise(L"Sprites\\shopping_hero.bmp", L"Sprites\\shopping_hero_mask.bmp", 0, 0);
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
			if (m_bCanShoot && GetAsyncKeyState(VK_SPACE) & 0x8000) {

				/*m_pBullet = new CBullet();
				m_pBullet->Initialise(0, m_fX, m_fY - 28, GetBulletSpeed());*/

				m_bCanShoot = false;

			}

			float fHalfPaddleW = m_pSprite->GetWidth() / 2.0f;

			if (GetAsyncKeyState(68) & 0x8000) {

				m_pSprite->Deinitialise();
				//m_pSprite->Initialise(IDB_SHIP_PLAYER_RIGHT_SPRITE, IDB_SHIP_PLAYER_RIGHT_MASK);
				//m_pSprite->Initialise(L"Sprites\\shipPlayerRightSprite.bmp", L"Sprites\\shipPlayerRightMask.bmp", 0, 0);
				m_pSprite->Initialise(L"Sprites\\shopping_hero.bmp", L"Sprites\\shopping_hero_mask.bmp", 0, 0);
				m_fX += m_fSpeed * _fDeltaTick;

			}
			else if (GetAsyncKeyState(65) & 0x8000) {

				m_pSprite->Deinitialise();
				//m_pSprite->Initialise(IDB_SHIP_PLAYER_LEFT_SPRITE, IDB_SHIP_PLAYER_LEFT_MASK);
				//m_pSprite->Initialise(L"Sprites\\shipPlayerLeftSprite.bmp", L"Sprites\\shipPlayerLeftMask.bmp", 0, 0);
				m_pSprite->Initialise(L"Sprites\\shopping_hero.bmp", L"Sprites\\shopping_hero_mask.bmp", 0, 0);
				m_fX -= m_fSpeed * _fDeltaTick;

			}
			else
			{
				m_pSprite->Deinitialise();
				//m_pSprite->Initialise(IDB_SHIP_PLAYER_SPRITE, IDB_SHIP_PLAYER_MASK);
				//m_pSprite->Initialise(L"Sprites\\shipPlayerSprite.bmp", L"Sprites\\shipPlayerMask.bmp", 0, 0);
				m_pSprite->Initialise(L"Sprites\\shopping_hero.bmp", L"Sprites\\shopping_hero_mask.bmp", 0, 0);
			}

			if (m_fX - fHalfPaddleW <= 0) {

				m_fX = fHalfPaddleW;

			}
			else if (m_fX + fHalfPaddleW >= m_iScreenWidth/2 ) {

				m_fX = m_iScreenWidth / 2 - fHalfPaddleW;

			}
		}
		

		//if (m_pBullet != nullptr)
		//	m_pBullet->Process(_fDeltaTick);

		CEntity::Process(_fDeltaTick);

	}

}

void CPlayer::DestroyBullet() {

	m_bCanShoot = true;
	m_pBullet = nullptr;

}

CBullet* CPlayer::GetBullet() const {

	return (m_pBullet);

}

void
CPlayer::SetShipSpeed(float _fSpeed) {

	m_fSpeed = _fSpeed;

}

float
CPlayer::GetBulletSpeed() const {

	return (m_fBulletSpeed);

}

void
CPlayer::SetBulletSpeed(float _fSpeed) {

	m_fBulletSpeed = _fSpeed;

}

void
CPlayer::SetHit(bool _b) {

	m_bHit = _b;

}

bool
CPlayer::IsHit() const {

	return (m_bHit);

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
