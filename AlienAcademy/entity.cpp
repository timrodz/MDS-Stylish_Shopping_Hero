// Library Includes

// Local Includes
//#include "resource.h"
#include "Sprite.h"
#include "utils.h"

// This Include
#include "entity.h"

// Static Variables

// Static Function Prototypes

// Implementation

CEntity::CEntity()
	: m_fX(0.0f)
	, m_fY(0.0f)
{

}

CEntity::~CEntity()
{
	delete m_pSprite;
	m_pSprite = 0;
}

bool CEntity::Initialise(std::wstring _strFileName, std::wstring _strFileMask, int _iWidth, int _iHeight)
{
	//if (m_pSprite == nullptr)
	m_pSprite = new CSprite();

	VALIDATE(m_pSprite->Initialise(_strFileName, _strFileMask, _iWidth, _iHeight));

	return (true);
}

void
CEntity::Draw()
{
	m_pSprite->Draw();
}

void
CEntity::Process(float _fDeltaTick)
{
	m_pSprite->SetX(static_cast<int>(m_fX));
	m_pSprite->SetY(static_cast<int>(m_fY));

	m_pSprite->Process(_fDeltaTick);
}

float
CEntity::GetX() const
{
	return (m_fX);
}

float
CEntity::GetY() const
{
	return (m_fY);
}

float
CEntity::GetWidth() const
{
	return (static_cast<float>(m_pSprite->GetWidth()));
}

float
CEntity::GetHeight() const
{
	return (static_cast<float>(m_pSprite->GetHeight()));
}

void
CEntity::SetX(float _f)
{
	m_fX = _f;
}

void
CEntity::SetY(float _f)
{
	m_fY = _f;
}
