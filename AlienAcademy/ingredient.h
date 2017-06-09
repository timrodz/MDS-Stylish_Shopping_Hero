#pragma once

#if !defined(__INGREDIENT_H__)
#define __INGREDIENT_H__

// Library Includes

// Local Includes
#include "entity.h"

// Types

// Constants

// Prototypes
class CSprite;

class CIngredient : public CEntity
{
	// Member Functions
public:
	CIngredient();
	CIngredient(std::string _name, int _type);
	virtual ~CIngredient();

	bool Initialise(int _iType, float _fPosX, float _fPosY, float _fVelocityY);

	virtual void Draw();
	virtual void Process(float _fDeltaTick);

	float GetVelocityY() const;
	void SetVelocityY(float _fY);

	float GetRadius() const;

	std::string GetName();

	bool IsActive() { return m_bActive; }
	void SetActive(bool _bActive) { m_bActive = _bActive; }

	int GetType() { return m_iType; }

private:
	CIngredient(const CIngredient& _kr);
	CIngredient& operator= (const CIngredient& _kr);


	// Member Variables
public:
	enum GroceryItem
	{
		apple,
		applejuice,
		bakingpowder,
		banana,
		bread,
		broccoli,
		capsicum,
		carrot,
		chicken,
		corn,
		cornflakes,
		cornflour,
		egg,
		flour,
		ketchup,
		lemon,
		lettuce,
		margarine,
		milk,
		onion,
		orange,
		potato,
		mushroom,
		steak,
		sugar,
		tomato,
		berry,
		butter,
		cheese,
		chocolate,
		cream,
		ginger,
		ham,
		honey,
		pea,
		pineapple,
		rice,
		soysauce,
		spaghetti,
		vanilla,
		yeast
	};

protected:
	float m_fVelocityY;
	std::string m_name;
	bool m_bActive;

private:
	int m_iType;

};

#endif    // __INGREDIENT_H__
