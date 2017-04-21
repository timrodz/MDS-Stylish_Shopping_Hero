// Library Includes
#include <windows.h>

// Local Includes
#include "game.h"
#include "Clock.h"

// Static Variables
bool CClock::m_bIsPaused = false;
// Static Function Prototypes

// Implementation

CClock::CClock()
	: m_fTimeElapsed(0.0)
	, m_fDeltaTime(0.0)
	, m_fLastTime(0.0)
	, m_fCurrentTime(0.0)
	, m_iFrameCount(0)


{}

CClock::~CClock()
{}

bool
CClock::Initialise()
{
	__int64 _TimerFrequency, _currTime;
	QueryPerformanceFrequency((LARGE_INTEGER*)&_TimerFrequency);
	m_SecondsPerCount = 1.0 / static_cast<double>(_TimerFrequency);

	QueryPerformanceCounter((LARGE_INTEGER*)&_currTime);
	m_fCurrentTime = static_cast<double>(_currTime);
	m_fLastTime = static_cast<double>(_currTime);

	return (true);
}

void
CClock::Process()
{

	//Get the time this frame.
	__int64 currTime;

	QueryPerformanceCounter((LARGE_INTEGER*)&currTime);

	m_fCurrentTime = static_cast<double>(currTime);

	//Time difference between this frame and the previous frame

	if (!m_bIsPaused)
	{
		m_fDeltaTime = (m_fCurrentTime - m_fLastTime) * m_SecondsPerCount;
	}


	//Prepare for the next frame
	m_fLastTime = m_fCurrentTime;

	//Force non-negative
	if (m_fDeltaTime < 0.0)
	{
		m_fDeltaTime = 0.0;
	}

	m_fTimeElapsed += m_fDeltaTime;

}

float
CClock::GetDeltaTick()
{
	return static_cast<float>(m_fDeltaTime);
}

void CClock::SetIsPaused(bool _b)
{
	m_bIsPaused = _b;
}
