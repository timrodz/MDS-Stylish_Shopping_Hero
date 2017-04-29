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

	void CreateRecipe();

	std::vector<CRecipe*> getRecipes();

private:

	std::vector<CRecipe*> m_vecRecipes;
	
	CRecipe* m_Recipe1;
	CRecipe* m_Recipe2;
};

#endif