#pragma once

#if !defined(__RECIPEMANAGER_H__)
#define __RECIPEMANAGER_H__

#include <vector>

class CRecipe;

class CRecipeManager
{
public:
	CRecipeManager();
	~CRecipeManager();

	void CreateRecipes();

private:

	std::vector<CRecipe> m_vecRecipes;
	CRecipe* m_Recipe;
};

#endif