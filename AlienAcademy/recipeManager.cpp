#include "recipeManager.h"
#include "recipe.h"
#include "ingredient.h"

CRecipeManager::CRecipeManager()
{
	CreateRecipes();
}

CRecipeManager::~CRecipeManager()
{
	delete m_Recipe;
	m_Recipe = 0;
}

void CRecipeManager::CreateRecipes()
{
	int iNumberOfRecipes = 6;
	int randomRecipe = (rand() % iNumberOfRecipes);
	m_Recipe = new CRecipe(randomRecipe);
}

