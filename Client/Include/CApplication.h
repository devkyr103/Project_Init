#pragma once

#include "CommonInclude.h"
#include "SingletonMacro.h"
#include "Enums.h"

namespace kyr
{
	class CApplication
	{
	public:
		bool	Init(HINSTANCE hInst);
		int		Run();

	private:
		void Register();
		bool Create();

	private:
		void Logic();
		void Input();
		bool Update();
		bool PostUpdate();
		void Collision();
		void Render();

	public:
		HWND GetHWnd() { return mHWnd; }
		HDC GetHDC() { return mHDC; }

	private:
		HINSTANCE	mHInst;					// 프로그램 인스턴스 핸들
		HWND		mHWnd;					// 윈도우 인스턴스 핸들

		// GDI
		HDC			mHDC;					
		HBITMAP		mBackBuffer;			
		HDC			mBackHDC;

		// GDI+
		ULONG_PTR	gdiplusToken;			// GDI+ 토큰
		Gdiplus::Graphics* mBackGp;			// 백 그래픽스

		Gdiplus::SolidBrush* mBrush[(int)eColorType::Max];
		Gdiplus::Pen* mPen[(int)eColorType::Max];

		UINT	mWidth;
		UINT	mHeight;

		static bool m_Loop;			// 프로그램 종료에 사용됨(WndProc)

	private:
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

		DECLARE_SINGLE(CApplication)
	};

}