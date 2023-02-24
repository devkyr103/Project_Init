#pragma once

#include "GameInfo.h"
#include "SingletonMacro.h"

class CGameManager
{
private:
	HINSTANCE	m_hInst;		// 프로그램 인스턴스 핸들
	HWND		m_hWnd;			// 윈도우 인스턴스 핸들
	ULONG_PTR	gdiplusToken;	// GDI+ 토큰

	class CTimer* m_Timer;

	HMENU		m_hMenu;		// 메뉴 핸들

	static bool m_Loop;			// 프로그램 종료에 사용됨(WndProc)

public:
	bool	Init(HINSTANCE hInst);
	int		Run();

private:
	void Logic();
	void Input();
	bool Update();
	bool PostUpdate();
	void Collision();
	void Render();

private:
	void Register();
	bool Create();

private:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	DECLARE_SINGLE(CGameManager)
};

