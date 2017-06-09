#include "recipe.h"
#include "ingredient.h"

CRecipe::CRecipe()
{
}

CRecipe::~CRecipe()
{
	while (m_vecIngredients.size() > 0)
	{
		CIngredient* pIngredient = m_vecIngredients[m_vecIngredients.size() - 1];

		m_vecIngredients.pop_back();

		delete pIngredient;
	}
}

CRecipe::CRecipe(int _RecipeNumber)
{
	if (_RecipeNumber == 0)
	{
		CreateChocolateCake();
	}
	else if (_RecipeNumber == 1)
	{
		CreatePavlova();
	}
	else if (_RecipeNumber == 2)
	{
		CreateSpaghettiBolognese();
	}
	else if (_RecipeNumber == 3)
	{
		CreateHawaiianPizza();
	}
	else if (_RecipeNumber == 4)
	{
		CreateChickenTeriyaki();
	}
	else if (_RecipeNumber == 5)
	{
		CreateShephersPie();
	}
	else
	{
		CreateChocolateCake();
	}
}

void CRecipe::CreateChocolateCake()
{
	m_name = "CHOCOLATE CAKE";
	m_vecIngredients.push_back(new CIngredient("Flour", CIngredient::flour));
	m_vecIngredients.push_back(new CIngredient("Sugar", CIngredient::sugar));
	m_vecIngredients.push_back(new CIngredient("Milk", CIngredient::milk));
	m_vecIngredients.push_back(new CIngredient("Butter", CIngredient::butter));
	m_vecIngredients.push_back(new CIngredient("Eggs", CIngredient::egg));
	m_vecIngredients.push_back(new CIngredient("Vanilla", CIngredient::vanilla));
	m_vecIngredients.push_back(new CIngredient("Chocolate", CIngredient::chocolate));
}

void CRecipe::CreatePavlova()
{
	m_name = "PAVLOVA";
	m_vecIngredients.push_back(new CIngredient("Sugar", CIngredient::sugar));
	m_vecIngredients.push_back(new CIngredient("Egg Whites", CIngredient::egg));
	m_vecIngredients.push_back(new CIngredient("Cornflower", CIngredient::cornflour));
	m_vecIngredients.push_back(new CIngredient("Cream", CIngredient::cream));
	m_vecIngredients.push_back(new CIngredient("Vanilla", CIngredient::vanilla));
	m_vecIngredients.push_back(new CIngredient("Berries", CIngredient::berry));
}

void CRecipe::CreateSpaghettiBolognese()
{
	m_name = "SPAGHETTI BOLOGNESE";
	m_vecIngredients.push_back(new CIngredient("Beef", CIngredient::steak));
	m_vecIngredients.push_back(new CIngredient("Spaghetti", CIngredient::spaghetti));
	m_vecIngredients.push_back(new CIngredient("Tomatoes", CIngredient::tomato));
	m_vecIngredients.push_back(new CIngredient("Onions", CIngredient::onion));
	m_vecIngredients.push_back(new CIngredient("Mushrooms", CIngredient::mushroom));
	m_vecIngredients.push_back(new CIngredient("Cheese", CIngredient::cheese));
}

void CRecipe::CreateHawaiianPizza()
{
	m_name = "HAWAIIAN PIZZA";
	m_vecIngredients.push_back(new CIngredient("Flour", CIngredient::flour));
	m_vecIngredients.push_back(new CIngredient("Yeast", CIngredient::yeast));
	m_vecIngredients.push_back(new CIngredient("Ham", CIngredient::ham));
	m_vecIngredients.push_back(new CIngredient("Cheese", CIngredient::cheese));
	m_vecIngredients.push_back(new CIngredient("Pineapple", CIngredient::pineapple));
	m_vecIngredients.push_back(new CIngredient("Tomatoes", CIngredient::tomato));
}

void CRecipe::CreateChickenTeriyaki()
{
	m_name = "CHICKEN TERIYAKI";
	m_vecIngredients.push_back(new CIngredient("Chicken", CIngredient::chicken));
	m_vecIngredients.push_back(new CIngredient("Soy Sauce", CIngredient::soysauce));
	m_vecIngredients.push_back(new CIngredient("Ginger", CIngredient::ginger));
	m_vecIngredients.push_back(new CIngredient("Honey", CIngredient::honey));
	m_vecIngredients.push_back(new CIngredient("Rice", CIngredient::rice));
	m_vecIngredients.push_back(new CIngredient("Orange Juice", CIngredient::orange));
}

void CRecipe::CreateShephersPie()
{
	m_name = "SHEPHERD'S PIE";
	m_vecIngredients.push_back(new CIngredient("Potatoes", CIngredient::potato));
	m_vecIngredients.push_back(new CIngredient("Beef", CIngredient::steak));
	m_vecIngredients.push_back(new CIngredient("Carrots", CIngredient::carrot));
	m_vecIngredients.push_back(new CIngredient("Onions", CIngredient::onion));
	m_vecIngredients.push_back(new CIngredient("Cheese", CIngredient::cheese));
	m_vecIngredients.push_back(new CIngredient("Flour", CIngredient::flour));
	m_vecIngredients.push_back(new CIngredient("Peas", CIngredient::pea));
}

std::vector<CIngredient*> CRecipe::getIngredients()
{
	return m_vecIngredients;
}

std::string CRecipe::getName()
{
	return m_name;
}