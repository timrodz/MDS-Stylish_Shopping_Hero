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
	CIngredient Flour("Flour");
	CIngredient Sugar("Sugar");
	CIngredient Milk("Milk");
	CIngredient Butter("Butter");
	CIngredient Eggs("Eggs");
	CIngredient Vanilla("Vanilla");
	CIngredient Chocolate("Chocolate");
	m_name = "CHOCOLATE CAKE";
	m_vecIngredients.push_back(new CIngredient("Flour"));
	m_vecIngredients.push_back(new CIngredient("Sugar"));
	m_vecIngredients.push_back(new CIngredient("Milk"));
	m_vecIngredients.push_back(new CIngredient("Butter"));
	m_vecIngredients.push_back(new CIngredient("Eggs"));
	m_vecIngredients.push_back(new CIngredient("Vanilla"));
	m_vecIngredients.push_back(new CIngredient("Chocolate"));
}

void CRecipe::CreatePavlova()
{
	CIngredient EggWhites("Egg Whites");
	CIngredient Cornflower("Cornflower");
	CIngredient Cream("Cream");
	CIngredient Berries("Berries");
	m_name = "PAVLOVA";
	m_vecIngredients.push_back(new CIngredient("Sugar"));
	m_vecIngredients.push_back(new CIngredient("Egg Whites"));
	m_vecIngredients.push_back(new CIngredient("Cornflower"));
	m_vecIngredients.push_back(new CIngredient("Cream"));
	m_vecIngredients.push_back(new CIngredient("Vanilla"));
	m_vecIngredients.push_back(new CIngredient("Berries"));
}

void CRecipe::CreateSpaghettiBolognese()
{
	CIngredient BeefMince("Beef Mince");
	CIngredient Spaghetti("Spaghetti");
	CIngredient Tomatoes("Tomatoes");
	CIngredient Onions("Onions");
	CIngredient Mushrooms("Mushrooms");
	CIngredient Oregano("Oregano");
	m_name = "SPAGHETTI BOLOGNESE";
	m_vecIngredients.push_back(new CIngredient("Beef Mince"));
	m_vecIngredients.push_back(new CIngredient("Spaghetti"));
	m_vecIngredients.push_back(new CIngredient("Tomatoes"));
	m_vecIngredients.push_back(new CIngredient("Onions"));
	m_vecIngredients.push_back(new CIngredient("Mushrooms"));
	m_vecIngredients.push_back(new CIngredient("Oregano"));
}

void CRecipe::CreateHawaiianPizza()
{
	CIngredient Yeast("Yeast");
	CIngredient Ham("Ham");
	CIngredient Cheese("Cheese");
	CIngredient Pineapple("Pineapple");
	m_name = "HAWAIIAN PIZZA";
	m_vecIngredients.push_back(new CIngredient("Flour"));
	m_vecIngredients.push_back(new CIngredient("Yeast"));
	m_vecIngredients.push_back(new CIngredient("Ham"));
	m_vecIngredients.push_back(new CIngredient("Cheese"));
	m_vecIngredients.push_back(new CIngredient("Pineapple"));
	m_vecIngredients.push_back(new CIngredient("Tomatoes"));
}

void CRecipe::CreateChickenTeriyaki()
{
	CIngredient Chicken("Chicken");
	CIngredient SoySauce("Soy Sauce");
	CIngredient Ginger("Ginger");
	CIngredient Honey("Honey");
	CIngredient Rice("Rice");
	CIngredient OrangeJuice("Orange Juice");
	m_name = "CHICKEN TERIYAKI";
	m_vecIngredients.push_back(new CIngredient("Chicken"));
	m_vecIngredients.push_back(new CIngredient("Soy Sauce"));
	m_vecIngredients.push_back(new CIngredient("Ginger"));
	m_vecIngredients.push_back(new CIngredient("Honey"));
	m_vecIngredients.push_back(new CIngredient("Rice"));
	m_vecIngredients.push_back(new CIngredient("Orange Juice"));
}

void CRecipe::CreateShephersPie()
{
	CIngredient Potatoes("Potatoes");
	CIngredient Carrots("Carrots");
	CIngredient Peas("Peas");
	m_name = "SHEPHERD'S PIE";
	m_vecIngredients.push_back(new CIngredient("Potatoes"));
	m_vecIngredients.push_back(new CIngredient("Beef Mince"));
	m_vecIngredients.push_back(new CIngredient("Carrots"));
	m_vecIngredients.push_back(new CIngredient("Onions"));
	m_vecIngredients.push_back(new CIngredient("Cheese"));
	m_vecIngredients.push_back(new CIngredient("Flour"));
	m_vecIngredients.push_back(new CIngredient("Peas"));
}

std::vector<CIngredient*> CRecipe::getIngredients()
{
	return m_vecIngredients;
}

std::string CRecipe::getName()
{
	return m_name;
}