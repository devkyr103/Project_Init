#include "CApplication.h"
#include "Client.h"
#include "CTime.h"
#include "CInput.h"
#include "CSceneManager.h"
#include "CResources.h"
#include "CCollisionManager.h"
#include "CCamera.h"


namespace kyr
{
	DEFINITION_SINGLE(CApplication);

	bool CApplication::m_Loop = true;
	HWND CApplication::mHWnd{};
	UINT CApplication::mWidth{};
	UINT CApplication::mHeight{};
	RECT CApplication::mRect{};


	CApplication::CApplication()
	{
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		//_CrtSetBreakAlloc();
	}

	CApplication::~CApplication()
	{
		Gdiplus::GdiplusShutdown(gdiplusToken);
	}

	bool CApplication::Init(HINSTANCE hInst)
	{
		mHInst = hInst;

		// ������ ������
		mWidth = mRect.right = 1600;
		mHeight = mRect.bottom = 900;

		// ������ ��� �� ����
		Register();

		if (!Create())
			return false;

		//mWidth = GetSystemMetrics(SM_CXSCREEN);
		//mHeight = GetSystemMetrics(SM_CYSCREEN);


		// rect�� ���� Ŭ���̾�Ʈ ũ��� ����
		RECT rect{ 0, 0, (LONG)mWidth, (LONG)mHeight };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		//MoveWindow(mHWnd, 0, 0, rect.right - rect.left, rect.bottom - rect.top, TRUE);
		SetWindowPos(mHWnd, nullptr, 0, 0, rect.right - rect.left, rect.bottom - rect.top, 0);

		ShowWindow(mHWnd, TRUE);

		GetClientRect(mHWnd, &rect);

		// GDIplusStartup �Լ� ���ڷ� ����, GDI+ ����, 
		// ����� �ݹ� �Լ� �� ������ �������(������ �ʱ�ȭ��)
		Gdiplus::GdiplusStartupInput gdiplusStartupInput;

		// GDI+ Initialize
		Gdiplus::Status result = Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

		// GDI+ �ʱ�ȭ Ȯ��
		if (result != Gdiplus::Ok)
		{
			OutputDebugString(L"ERROR: GDI+ Initialize Failed");

			return false;
		}

		mHDC = GetDC(mHWnd);
		mBackBuffer = CreateCompatibleBitmap(mHDC, mWidth, mHeight);
		mBackHDC = CreateCompatibleDC(mHDC);

		HBITMAP defaultBitmap = (HBITMAP)SelectObject(mBackHDC, mBackBuffer);
		DeleteObject(defaultBitmap);

		mBackGp = new Gdiplus::Graphics(mBackHDC);

		// Ư�� ������ �ڵ鿡�� DC(Deivce Context) �ڵ��� ���´�.
		//mFrontGp = Gdiplus::Graphics::FromHWND(mHWnd);

		// ����ۿ� ��Ʈ��(��Ʈ�� ����� �켱 ��������� �����Ѵ�.)
		//mBackBmp = new Gdiplus::Bitmap(mWidth, mHeight);

		// �׷��Ƚ��� ����� ��Ʈ���� �������ش�.
		//mBackGp = Gdiplus::Graphics::FromImage(mBackBmp);

		CPaintTool::mBrush[(int)eColorType::Red] = new Gdiplus::SolidBrush(Gdiplus::Color(255, 0, 0));
		CPaintTool::mBrush[(int)eColorType::Green] = new Gdiplus::SolidBrush(Gdiplus::Color(0, 255, 0));
		CPaintTool::mBrush[(int)eColorType::Black] = new Gdiplus::SolidBrush(Gdiplus::Color(0, 0, 0));
		CPaintTool::mBrush[(int)eColorType::Blue] = new Gdiplus::SolidBrush(Gdiplus::Color(0, 0, 255));
		CPaintTool::mBrush[(int)eColorType::Yellow] = new Gdiplus::SolidBrush(Gdiplus::Color(255, 255, 0));
		CPaintTool::mBrush[(int)eColorType::White] = new Gdiplus::SolidBrush(Gdiplus::Color(255, 255, 255));

		CPaintTool::mPen[(int)eColorType::Red] = new Gdiplus::Pen(Gdiplus::Color(255, 0, 0));
		CPaintTool::mPen[(int)eColorType::Green] = new Gdiplus::Pen(Gdiplus::Color(0, 255, 0));
		CPaintTool::mPen[(int)eColorType::Black] = new Gdiplus::Pen(Gdiplus::Color(0, 0, 0));
		CPaintTool::mPen[(int)eColorType::Blue] = new Gdiplus::Pen(Gdiplus::Color(0, 0, 255));
		CPaintTool::mPen[(int)eColorType::Yellow] = new Gdiplus::Pen(Gdiplus::Color(255, 255, 0));
		CPaintTool::mPen[(int)eColorType::White] = new Gdiplus::Pen(Gdiplus::Color(255, 255, 255));

		// Initialize
		CTime::Initialize();
		CInput::Initialize();
		CSceneManager::Initialize();
		CCamera::Initialize();

		return true;
	}

	int CApplication::Run()
	{
		MSG msg{};

		while (m_Loop)
		{
			if (PeekMessage(&msg, mHWnd, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				Logic();
			}
		}

		CSceneManager::Release();
		CResources::Release();

		return (int)msg.wParam;
	}

	void CApplication::Logic()
	{
		Input();
		Update();
		PostUpdate();
		Collision();
		Render();
	}

	void CApplication::Input()
	{

	}

	bool CApplication::Update()
	{
		CTime::Update();
		CInput::Update();
		CCamera::Update();

		CSceneManager::Update();
		CCollisionManager::Update();

		return true;
	}

	bool CApplication::PostUpdate()
	{
		return true;
	}

	void CApplication::Collision()
	{
	}

	void CApplication::Render()
	{
		mBackGp->FillRectangle(CPaintTool::mBrush[(int)eColorType::Black], 0, 0, mWidth, mHeight);
		CTime::Render();
		CInput::Render(mBackGp);
		mBackGp->SetClip(CCamera::GetPath());
		CSceneManager::Render(mBackGp);
		CCamera::Render(mBackGp);



		StretchBlt(mHDC, 0, 0, mRect.right, mRect.bottom, mBackHDC, 0, 0, mWidth, mHeight, SRCCOPY);
	}

	void CApplication::Register()
	{
		WNDCLASSEXW wcex{};

		wcex.cbSize = sizeof(WNDCLASSEXW);
		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = WndProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = mHInst;
		wcex.hIcon = LoadIcon(mHInst, MAKEINTRESOURCE(IDI_CLIENT));
		wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wcex.lpszMenuName = nullptr;
		wcex.lpszClassName = TEXT("Init()");
		wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

		RegisterClassExW(&wcex);
	}

	bool CApplication::Create()
	{
		mHWnd = CreateWindowW(TEXT("Init()"), TEXT("Init()"), WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, 0, mWidth, mHeight, nullptr, nullptr, mHInst, nullptr);

		if (!mHWnd)
		{
			return FALSE;
		}
		
		ShowWindow(mHWnd, SW_SHOW);
		UpdateWindow(mHWnd);

		return true;
	}

	LRESULT CApplication::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
		case WM_KEYDOWN:
		{
			switch (wParam)
			{
			case VK_F11:
				if (IsZoomed(mHWnd))
				{
					RECT rect{ 0, 0, (LONG)mWidth, (LONG)mHeight };
					AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
					SetWindowLongPtr(mHWnd, GWL_STYLE, WS_OVERLAPPEDWINDOW);
					MoveWindow(mHWnd, 0, 0, rect.right - rect.left, rect.bottom - rect.top, TRUE);
					ShowWindow(mHWnd, SW_SHOW);
				}
				else
					SendMessage(hWnd, WM_SIZE, SIZE_MAXIMIZED, NULL);
				break;
			default:
				break;
			}
		}
		break;
		case WM_SIZE:
		{
			switch (wParam)
			{
			case SIZE_MAXIMIZED:
				SetWindowLongPtr(mHWnd, GWL_STYLE, 0);
				ShowWindow(mHWnd, SW_SHOWMAXIMIZED);
				break;
			default:
				break;
			}
			GetClientRect(mHWnd, &mRect);
		}
		break;
		case WM_DESTROY:
			m_Loop = false;
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}

		return 0;
	}

}
