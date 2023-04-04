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
		static HWND		mHWnd;				// ������ �ν��Ͻ� �ڵ�
		HINSTANCE	mHInst{};				// ���α׷� �ν��Ͻ� �ڵ�

	private:
		// GDI
		HDC			mHDC{};
		HBITMAP		mBackBuffer{};
		HDC			mBackHDC{};

		// GDI+
		ULONG_PTR	gdiplusToken{};			// GDI+ ��ū
		static Gdiplus::Graphics* mBackGp;		// �� �׷��Ƚ�

		// Buff Size
		static UINT	mWidth;
		static UINT	mHeight;

		// Client Rect
		static RECT mRect;


		static bool m_Loop;			// ���α׷� ���ῡ ����(WndProc)

	private:
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

		DECLARE_SINGLE(CApplication)
	};

}