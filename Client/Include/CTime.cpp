#include "CTime.h"
#include "CApplication.h"

namespace kyr
{
	LARGE_INTEGER CTime::mCpuFrequency{};
	LARGE_INTEGER CTime::mPrevFrequency{};
	LARGE_INTEGER CTime::mCurFrequency{};
	double CTime::mDeltaTime{};
	double CTime::mFPS{};
	double CTime::mFPSTime{};
	int	CTime::mTick{};


	void CTime::Initialize()
	{
		QueryPerformanceFrequency(&mCpuFrequency);
		QueryPerformanceCounter(&mPrevFrequency);
	}

	void CTime::Update()
	{
		QueryPerformanceCounter(&mCurFrequency);

		mDeltaTime = (mCurFrequency.QuadPart - mPrevFrequency.QuadPart) / (double)mCpuFrequency.QuadPart;

		mPrevFrequency = mCurFrequency;

		mFPSTime += mDeltaTime;

		if (mTick == 60)
		{
			mFPS = mTick / mFPSTime;
			mFPSTime = mTick = 0;
		}
	}

	void CTime::Render()
	{
		HWND hWnd = CApplication::GetInst()->GetHWnd();

		wchar_t szFloat[50] = {};
		float FPS = 1.0f / (float)mDeltaTime;
		swprintf_s(szFloat, 50, L"FPS : %d", (UINT)FPS);
		//int iLen = wcsnlen_s(szFloat, 50);
		SetWindowText(hWnd, szFloat);
	}

}


