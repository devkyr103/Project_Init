#pragma once

#include "GameInfo.h"

class CTimer
{
private:
	LARGE_INTEGER			m_CpuFrequency;			// �� �� ���ػ� �ð�
	LARGE_INTEGER			m_PrevFrequency;	
	LARGE_INTEGER			m_CurFrequency;	
	static double			m_DeltaTime;	// (���� ������ �ð� - ���� ������ �ð�) / m_Second
	static double			m_FPS;			// �� �� ������ = m_Tick / m_FPSTime
	double					m_FPSTime;		// 60 ������ �� ���� DeltaTime
	int						m_Tick;			// 60 Tick = 60 ������

public:
	__forceinline static double GetDeltaTime() { return m_DeltaTime; }
						 
	__forceinline static double GetFPS() { return m_FPS; }

public:
	void Init();
	void Update();
};

