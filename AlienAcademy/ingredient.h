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
	CIngredient(std::string _name);
	virtual ~CIngredient();

	bool Initialise(short _iType, float _fPosX, float _fPosY, float _fVelocityY);

	virtual void Draw();
	virtual void Process(float _fDeltaTick);

	float GetVelocityY() const;
	void SetVelocityY(float _fY);

	float GetRadius() const;

	std::string GetName();

private:
	CIngredient(const CIngredient& _kr);
	CIngredient& operator= (const CIngredient& _kr);


	// Member Variables
public:

protected:
	float m_fVelocityY;
	std::string m_name;

private:
	int m_iType;

};

#endif    // __BALL_H__
