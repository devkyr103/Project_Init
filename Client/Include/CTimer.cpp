#include "CTimer.h"

double CTimer::m_DeltaTime{};
double CTimer::m_FPS{};

void CTimer::Init()
{
	QueryPerformanceFrequency(&m_CpuFrequency);
	QueryPerformanceCounter(&m_PrevFrequency);
}

void CTimer::Update()
{
	QueryPerformanceCounter(&m_CurFrequency);

	m_DeltaTime = (m_CurFrequency.QuadPart - m_PrevFrequency.QuadPart) / (double)m_CpuFrequency.QuadPart;

	m_PrevFrequency = m_CurFrequency;

	m_FPSTime += m_DeltaTime;

	if (m_Tick == 60)
	{
		m_FPS = m_Tick / m_FPSTime;
		m_Tick = m_FPSTime = 0;
	}
}
