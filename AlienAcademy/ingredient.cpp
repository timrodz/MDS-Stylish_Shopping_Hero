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
	Initialise(1, 0.0f, 0.0f, 0.0f);
}

CIngredient::~CIngredient()
{}

bool CIngredient::Initialise(short _iType, float _fPosX, float _fPosY, float _fVelocityY) {

	m_iType = _iType;

	if (m_iType == 0) 
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\apple juice.bmp", L"Sprites\\food_sprites\\apple juice_mask.bmp"));
	}
	else if (m_iType == 2)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\apple juice.bmp", L"Sprites\\food_sprites\\baking powder_mask.bmp"));
	}
	else if (m_iType == 2)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\bananas.bmp", L"Sprites\\food_sprites\\bananas_mask.bmp"));
	}
	else if (m_iType == 2)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\bread.bmp", L"Sprites\\food_sprites\\bread_mask.bmp"));
	}
	else if (m_iType == 2)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\brocolli.bmp", L"Sprites\\food_sprites\\brocolli_mask.bmp"));
	}
	else if (m_iType == 2)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\capsicum.bmp", L"Sprites\\food_sprites\\capsicum_mask.bmp"));
	}
	else if (m_iType == 2)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\carrot.bmp", L"Sprites\\food_sprites\\carrot_mask.bmp"));
	}
	else if (m_iType == 2)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\chicken.bmp", L"Sprites\\food_sprites\\chicken_mask.bmp"));
	}
	else if (m_iType == 2)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\corn.bmp", L"Sprites\\food_sprites\\corn_mask.bmp"));
	}
	else if (m_iType == 2)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\cornflakes.bmp", L"Sprites\\food_sprites\\cornflakes_mask.bmp"));
	}
	else if (m_iType == 2)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\eggs.bmp", L"Sprites\\food_sprites\\eggs_mask.bmp"));
	}
	else if (m_iType == 2)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\flour.bmp", L"Sprites\\food_sprites\\flour_mask.bmp"));
	}
	else if (m_iType == 2)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\ketchup.bmp", L"Sprites\\food_sprites\\ketchup_mask.bmp"));
	}
	else if (m_iType == 2)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\lemon.bmp", L"Sprites\\food_sprites\\lemon_mask.bmp"));
	}
	else if (m_iType == 2)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\lettuce.bmp", L"Sprites\\food_sprites\\lettuce_mask.bmp"));
	}
	else if (m_iType == 2)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\margarine.bmp", L"Sprites\\food_sprites\\margarine_mask.bmp"));
	}
	else if (m_iType == 2)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\milk.bmp", L"Sprites\\food_sprites\\milk_mask.bmp"));
	}
	else if (m_iType == 2)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\onion.bmp", L"Sprites\\food_sprites\\onion_mask.bmp"));
	}
	else if (m_iType == 2)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\oranges.bmp", L"Sprites\\food_sprites\\oranges_mask.bmp"));
	}
	else if (m_iType == 2)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\potatoes.bmp", L"Sprites\\food_sprites\\potatoes_mask.bmp"));
	}
	else if (m_iType == 2)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\shrooms.bmp", L"Sprites\\food_sprites\\shrooms_mask.bmp"));
	}
	else if (m_iType == 2)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\steak.bmp", L"Sprites\\food_sprites\\steak_mask.bmp"));
	}
	else if (m_iType == 2)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\sugar.bmp", L"Sprites\\food_sprites\\sugar_mask.bmp"));
	}
	else if (m_iType == 2)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\tomato.bmp", L"Sprites\\food_sprites\\tomato_mask.bmp"));
	}
	else 
	{

		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\apple.bmp", L"Sprites\\apple_mask.bmp"));
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

std::string CIngredient::GetName()
{
	return m_name;
}
