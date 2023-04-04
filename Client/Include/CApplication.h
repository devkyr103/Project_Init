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
		HDC GetHDC() { return mHDC; }

		static HWND GetHWnd() { return mHWnd; }


		static UINT GetClientWidth() { return mWidth; }
		static UINT GetClientHeight() { return mHeight; }

		static Gdiplus::Graphics* GetBackGP() { return mBackGp; }

	private:
		static HWND		mHWnd;				// 윈도우 인스턴스 핸들
		HINSTANCE	mHInst{};				// 프로그램 인스턴스 핸들

	private:
		// GDI
		HDC			mHDC{};
		HBITMAP		mBackBuffer{};
		HDC			mBackHDC{};

		// GDI+
		ULONG_PTR	gdiplusToken{};			// GDI+ 토큰
		static Gdiplus::Graphics* mBackGp;		// 백 그래픽스

		// Buff Size
		static UINT	mWidth;
		static UINT	mHeight;

		// Client Rect
		static RECT mRect;


		static bool m_Loop;			// 프로그램 종료에 사용됨(WndProc)

	private:
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

		DECLARE_SINGLE(CApplication)
	};

}