// Library Includes

// Local Includes
//#include "resource.h"
#include "utils.h"

// This Includes
#include "ingredient.h"

// Static Variables

// Static Function Prototypes

// Implementation

CIngredient::CIngredient()
	: m_fVelocityY(0.0f)
{}

CIngredient::CIngredient(std::string _name)
	: m_name(_name)
{
}

CIngredient::~CIngredient()
{}

bool CIngredient::Initialise(short _iType, float _fPosX, float _fPosY, float _fVelocityY) {

	m_iType = _iType;

	// Player Bullet
	if (m_iType == 0) {

		//VALIDATE(CEntity::Initialise(IDB_BULLET_PLAYER_SPRITE, IDB_BULLET_PLAYER_MASK));

	}
	// Enemy Bullet
	else {

		//VALIDATE(CEntity::Initialise(IDB_BULLET_ENEMY_SPRITE, IDB_BULLET_ENEMY_MASK));
		VALIDATE(CEntity::Initialise(L"Sprites\\apple.bmp", L"Sprites\\apple_mask.bmp"));
	}

	m_fX = _fPosX;
	m_fY = _fPosY;

	m_fVelocityY = _fVelocityY;

	return (true);
}

void
CIngredient::Draw() {

	CEntity::Draw();

}

void
CIngredient::Process(float _fDeltaTick) {

	if (m_iType == 0) {

		m_fY -= m_fVelocityY * _fDeltaTick;

	}
	else {

		m_fY += m_fVelocityY * _fDeltaTick;

	}

	CEntity::Process(_fDeltaTick);

}

float
CIngredient::GetVelocityY() const {

	return (m_fVelocityY);

}

void
CIngredient::SetVelocityY(float _fY) {

	m_fVelocityY = _fY;

}

float
CIngredient::GetRadius() const {

	return (GetWidth() / 2.0f);

}
