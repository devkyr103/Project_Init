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
		HINSTANCE	mHInst;					// ���α׷� �ν��Ͻ� �ڵ�
		HWND		mHWnd;					// ������ �ν��Ͻ� �ڵ�

		// GDI
		HDC			mHDC;					
		HBITMAP		mBackBuffer;			
		HDC			mBackHDC;

		// GDI+
		ULONG_PTR	gdiplusToken;			// GDI+ ��ū
		Gdiplus::Graphics* mBackGp;			// �� �׷��Ƚ�

		Gdiplus::SolidBrush* mBrush[(int)eColorType::Max];
		Gdiplus::Pen* mPen[(int)eColorType::Max];

		UINT	mWidth;
		UINT	mHeight;

		static bool m_Loop;			// ���α׷� ���ῡ ����(WndProc)

	private:
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

		DECLARE_SINGLE(CApplication)
	};

}