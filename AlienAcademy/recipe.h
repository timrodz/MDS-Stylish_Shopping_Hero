#pragma once

#if !defined(__RECIPE_H__)
#define __RECIPE_H__

#include <vector>

class CIngredient;

class CRecipe
{
public:
	CRecipe();
	~CRecipe();
	CRecipe(int _RecipeNumber);

	void CreateChocolateCake();
	void CreatePavlova();
	void CreateSpaghettiBolognese();
	void CreateHawaiianPizza();
	void CreateChickenTeriyaki();
	void CreateShephersPie();

private:
	
	std::vector<CIngredient*> m_vecIngredients;
	std::string m_name;
};

#endif