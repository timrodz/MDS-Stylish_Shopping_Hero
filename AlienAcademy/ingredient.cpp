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

CIngredient::CIngredient(std::string _name, int _type)
	: m_name(_name)
{
	Initialise(_type, 100.0f, 100.0f, 0.0f);
}

CIngredient::~CIngredient()
{}

bool CIngredient::Initialise(int _iType, float _fPosX, float _fPosY, float _fVelocityY)
{
	m_bActive = true;
	m_iType = _iType;

	if (m_iType == apple) 
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\apple.bmp", L"Sprites\\food_sprites\\apple_mask.bmp"));
	}
	else if (m_iType == applejuice)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\apple juice.bmp", L"Sprites\\food_sprites\\apple juice_mask.bmp"));
	}
	else if (m_iType == bakingpowder)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\baking powder.bmp", L"Sprites\\food_sprites\\baking powder_mask.bmp"));
	}
	else if (m_iType == banana)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\bananas.bmp", L"Sprites\\food_sprites\\bananas_mask.bmp"));
	}
	else if (m_iType == bread)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\bread.bmp", L"Sprites\\food_sprites\\bread_mask.bmp"));
	}
	else if (m_iType == broccoli)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\broccoli.bmp", L"Sprites\\food_sprites\\broccoli_mask.bmp"));
	}
	else if (m_iType == capsicum)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\capsicum.bmp", L"Sprites\\food_sprites\\capsicum_mask.bmp"));
	}
	else if (m_iType == carrot)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\carrot.bmp", L"Sprites\\food_sprites\\carrot_mask.bmp"));
	}
	else if (m_iType == chicken)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\chicken.bmp", L"Sprites\\food_sprites\\chicken_mask.bmp"));
	}
	else if (m_iType == corn)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\corn.bmp", L"Sprites\\food_sprites\\corn_mask.bmp"));
	}
	else if (m_iType == cornflakes)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\cornflakes.bmp", L"Sprites\\food_sprites\\cornflakes_mask.bmp"));
	}
	else if (m_iType == cornflour)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\cornflour.bmp", L"Sprites\\food_sprites\\cornflour_mask.bmp"));
	}
	else if (m_iType == egg)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\eggs.bmp", L"Sprites\\food_sprites\\eggs_mask.bmp"));
	}
	else if (m_iType == flour)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\flour.bmp", L"Sprites\\food_sprites\\flour_mask.bmp"));
	}
	else if (m_iType == ketchup)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\ketchup.bmp", L"Sprites\\food_sprites\\ketchup_mask.bmp"));
	}
	else if (m_iType == lemon)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\lemon.bmp", L"Sprites\\food_sprites\\lemon_mask.bmp"));
	}
	else if (m_iType == lettuce)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\lettuce.bmp", L"Sprites\\food_sprites\\lettuce_mask.bmp"));
	}
	else if (m_iType == margarine)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\margarine.bmp", L"Sprites\\food_sprites\\margarine_mask.bmp"));
	}
	else if (m_iType == milk)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\milk.bmp", L"Sprites\\food_sprites\\milk_mask.bmp"));
	}
	else if (m_iType == onion)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\onion.bmp", L"Sprites\\food_sprites\\onion_mask.bmp"));
	}
	else if (m_iType == orange)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\oranges.bmp", L"Sprites\\food_sprites\\oranges_mask.bmp"));
	}
	else if (m_iType == potato)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\potatoes.bmp", L"Sprites\\food_sprites\\potatoes_mask.bmp"));
	}
	else if (m_iType == mushroom)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\shrooms.bmp", L"Sprites\\food_sprites\\shrooms_mask.bmp"));
	}
	else if (m_iType == steak)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\steak.bmp", L"Sprites\\food_sprites\\steak_mask.bmp"));
	}
	else if (m_iType == sugar)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\sugar.bmp", L"Sprites\\food_sprites\\sugar_mask.bmp"));
	}
	else if (m_iType == tomato)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\tomato.bmp", L"Sprites\\food_sprites\\tomato_mask.bmp"));
	}
	else if (m_iType == berry)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\berries.bmp", L"Sprites\\food_sprites\\berries_mask.bmp"));
	}
	else if (m_iType == butter)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\butter.bmp", L"Sprites\\food_sprites\\butter_mask.bmp"));
	}
	else if (m_iType == cheese)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\cheese.bmp", L"Sprites\\food_sprites\\cheese_mask.bmp"));
	}
	else if (m_iType == chocolate)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\chocolate.bmp", L"Sprites\\food_sprites\\chocolate_mask.bmp"));
	}
	else if (m_iType == cream)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\cream.bmp", L"Sprites\\food_sprites\\cream_mask.bmp"));
	}
	else if (m_iType == ginger)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\ginger.bmp", L"Sprites\\food_sprites\\ginger_mask.bmp"));
	}
	else if (m_iType == ham)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\ham.bmp", L"Sprites\\food_sprites\\ham_mask.bmp"));
	}
	else if (m_iType == honey)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\honey.bmp", L"Sprites\\food_sprites\\honey_mask.bmp"));
	}
	else if (m_iType == pea)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\peas.bmp", L"Sprites\\food_sprites\\peas_mask.bmp"));
	}
	else if (m_iType == pineapple)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\pineapple.bmp", L"Sprites\\food_sprites\\pineapple_mask.bmp"));
	}
	else if (m_iType == rice)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\rice.bmp", L"Sprites\\food_sprites\\rice_mask.bmp"));
	}
	else if (m_iType == soysauce)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\soysauce.bmp", L"Sprites\\food_sprites\\soysauce_mask.bmp"));
	}
	else if (m_iType == spaghetti)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\spaghetti.bmp", L"Sprites\\food_sprites\\spaghetti_mask.bmp"));
	}
	else if (m_iType == vanilla)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\vanilla.bmp", L"Sprites\\food_sprites\\vanilla_mask.bmp"));
	}
	else if (m_iType == yeast)
	{
		VALIDATE(CEntity::Initialise(L"Sprites\\food_sprites\\yeast.bmp", L"Sprites\\food_sprites\\yeast_mask.bmp"));
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

void CIngredient::Draw() 
{
	if (m_bActive)
	{
		CEntity::Draw();
	}	
}

void CIngredient::Process(float _fDeltaTick) 
{

	m_fY += m_fVelocityY * _fDeltaTick;

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
