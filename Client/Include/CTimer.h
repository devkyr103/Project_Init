#pragma once

#include "GameInfo.h"

class CTimer
{
private:
	LARGE_INTEGER			m_CpuFrequency;			// 초 당 고해상도 시간
	LARGE_INTEGER			m_PrevFrequency;	
	LARGE_INTEGER			m_CurFrequency;	
	static double			m_DeltaTime;	// (현재 프레임 시간 - 이전 프레임 시간) / m_Second
	static double			m_FPS;			// 초 당 프레임 = m_Tick / m_FPSTime
	double					m_FPSTime;		// 60 프레임 당 누적 DeltaTime
	int						m_Tick;			// 60 Tick = 60 프레임

public:
	__forceinline static double GetDeltaTime() { return m_DeltaTime; }
						 
	__forceinline static double GetFPS() { return m_FPS; }

public:
	void Init();
	void Update();
};

