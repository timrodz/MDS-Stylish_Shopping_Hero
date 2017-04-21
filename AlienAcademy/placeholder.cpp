// Library Includes

// Local Includes
//#include "resource.h"
#include "utils.h"
#include "backbuffer.h"
#include "game.h"
#include "sprite.h"

// This Include
#include "placeholder.h"

// Static Variables

// Static Function Prototypes

// Implementation

CPlaceHolder::CPlaceHolder()
{}

CPlaceHolder::~CPlaceHolder()
{}

bool CPlaceHolder::Initialise() 
{
	//VALIDATE(CEntity::Initialise(IDB_MENU_1, IDB_BACKGROUNDMASK));
	VALIDATE(CEntity::Initialise(L"Sprites\\menu.bmp", L"Sprites\\BackgroundMask.bmp"));

	return (true);

}

//void CPlaceHolder::ChangeImage(int _iSpriteID, int _iSpriteMask)
void CPlaceHolder::ChangeImage(std::wstring _strFileName, std::wstring _strFileMask)
{

	m_pSprite->Deinitialise();
	//m_pSprite->Initialise(_iSpriteID, _iSpriteMask);
	m_pSprite->Initialise(_strFileName, _strFileMask, 0, 0);
}

void
CPlaceHolder::Draw() {

	CEntity::Draw();

}

void
CPlaceHolder::Process(float _fDeltaTick) {

	CEntity::Process(_fDeltaTick);

}