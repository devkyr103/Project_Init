#pragma once

#include "CommonInclude.h"

namespace kyr
{
	class CTime
	{
	public:
		static void Initialize();
		static void Update();
		static void Render();

	public:
		__forceinline static double GetDeltaTime() { return mDeltaTime; }
		__forceinline static double GetFPS() { return mFPS; }

	private:
		static LARGE_INTEGER	mCpuFrequency;	// �� �� ���ػ� �ð�
		static LARGE_INTEGER	mPrevFrequency;
		static LARGE_INTEGER	mCurFrequency;
		static double			mDeltaTime;	// (���� ������ �ð� - ���� ������ �ð�) / m_Second
		static double			mFPS;			// �� �� ������ = m_Tick / m_FPSTime
		static double			mFPSTime;		// 60 ������ �� ���� GetDeltaTime
		static int				mTick;			// 60 Tick = 60 ������
	};
}


