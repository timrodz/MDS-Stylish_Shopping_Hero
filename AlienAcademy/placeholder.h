#pragma once

#if !defined(__PLACEHOLDER_H__)
#define __PLACEHOLDER_H__

// Library Includes

// Local Includes
#include "entity.h"

// Types

// Constants

// Prototypes
class CSprite;

class CPlaceHolder : public CEntity
{
	// Member Functions
public:
	CPlaceHolder();
	virtual ~CPlaceHolder();

	virtual bool Initialise();

	
	//void ChangeImage(int _iSpriteID, int _iSpriteMask);
	void ChangeImage(std::wstring _strFileName, std::wstring _strFileMask);

	virtual void Draw();
	virtual void Process(float _fDeltaTick);


protected:

private:
	CPlaceHolder(const CPlaceHolder& _kr);
	CPlaceHolder& operator= (const CPlaceHolder& _kr);

	// Member Variables
public:

protected:

private:

};

#endif