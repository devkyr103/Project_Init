#pragma once

#include "GameInfo.h"
#include "SingletonMacro.h"

class CGameManager
{
private:
	HINSTANCE	m_hInst;		// ���α׷� �ν��Ͻ� �ڵ�
	HWND		m_hWnd;			// ������ �ν��Ͻ� �ڵ�
	ULONG_PTR	gdiplusToken;	// GDI+ ��ū

	class CTimer* m_Timer;

	HMENU		m_hMenu;		// �޴� �ڵ�

	static bool m_Loop;			// ���α׷� ���ῡ ����(WndProc)

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

