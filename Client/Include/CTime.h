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
		static LARGE_INTEGER	mCpuFrequency;	// 초 당 고해상도 시간
		static LARGE_INTEGER	mPrevFrequency;
		static LARGE_INTEGER	mCurFrequency;
		static double			mDeltaTime;	// (현재 프레임 시간 - 이전 프레임 시간) / m_Second
		static double			mFPS;			// 초 당 프레임 = m_Tick / m_FPSTime
		static double			mFPSTime;		// 60 프레임 당 누적 GetDeltaTime
		static int				mTick;			// 60 Tick = 60 프레임
	};
}


