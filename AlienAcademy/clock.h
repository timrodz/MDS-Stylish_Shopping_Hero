
#pragma once

#if !defined(__CLOCK_H__)
#define __CLOCK_H__

// Library Includes
#include <Windows.h>

// Local Includes

// Types

// Constants

// Prototypes
class CClock
{
	// Member Functions
public:
	CClock();
	~CClock();

	bool Initialise();

	void Process();

	float GetDeltaTick();

	int CountFramesPerSecond(float _DeltaTick);

	static void SetIsPaused(bool _b);

protected:

private:
	CClock(const CClock& _kr);
	CClock& operator= (const CClock& _kr);
	static bool m_bIsPaused;

	// Member Variables
public:

protected:
	double m_fTimeElapsed;
	double m_fDeltaTime;
	double m_fLastTime;
	double m_fCurrentTime;
	double m_SecondsPerCount;
	int m_iFrameCount;

private:

};

#endif    // __CLOCK_H__
