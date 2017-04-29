#include "recipeManager.h"
#include "recipe.h"
#include "ingredient.h"

CRecipeManager::CRecipeManager()
{
	CreateRecipe();
}

CRecipeManager::~CRecipeManager()
{
	delete m_Recipe1;
	m_Recipe1 = 0;

	delete m_Recipe2;
	m_Recipe2 = 0;
}

void CRecipeManager::CreateRecipe()
{
	int iNumberOfRecipes = 6;
	int randomRecipe = (rand() % iNumberOfRecipes);
	m_Recipe1 = new CRecipe(randomRecipe);
	m_Recipe2 = new CRecipe(randomRecipe);
	m_vecRecipes.push_back(m_Recipe1);
	m_vecRecipes.push_back(m_Recipe2);
}

std::vector<CRecipe*> CRecipeManager::getRecipes()
{
	return m_vecRecipes;
}

