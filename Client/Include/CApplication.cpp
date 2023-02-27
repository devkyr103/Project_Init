#include "CApplication.h"
#include "Client.h"
#include "CTime.h"
#include "CInput.h"
#include "CSceneManager.h"
#include "CResources.h"


namespace kyr
{
    DEFINITION_SINGLE(CApplication);

    bool CApplication::m_Loop = true;

    CApplication::CApplication()
        : mHInst{}
        , mHWnd{}
        , gdiplusToken{}
        , mBackGp{}
        , mBrush{}
        , mPen{}
        , mWidth{}
        , mHeight{}
        , mHDC{}
        , mBackBuffer{}
        , mBackHDC{}
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
        
        // 윈도우 등록 및 생성
        Register();

        if (!Create())
            return false;

        //mWidth = GetSystemMetrics(SM_CXSCREEN);
        //mHeight = GetSystemMetrics(SM_CYSCREEN);

        mWidth = 1600;
        mHeight = 900;
        //
        ////// rect를 실제 클라이언트 크기로 설정
        //RECT rect{ 0, 0, (LONG)mWidth, (LONG)mHeight };
        ////AdjustWindowRect(&rect, WS_POPUP, false);
        //
        //MoveWindow(mHWnd, 0, 0, rect.right - rect.left, rect.bottom - rect.top, TRUE);
        ////SetWindowPos(mHWnd, nullptr, 0, 0, rect.right - rect.left, rect.bottom - rect.top, 0);
        //
        //ShowWindow(mHWnd, TRUE);

        // GDIplusStartup 함수 인자로 사용됨, GDI+ 버전, 
        // 디버그 콜백 함수 등 정보를 담고있음(생성시 초기화됨)
        Gdiplus::GdiplusStartupInput gdiplusStartupInput;

        // GDI+ Initialize
        Gdiplus::Status result = Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

        // GDI+ 초기화 확인
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

        // 특정 윈도우 핸들에서 DC(Deivce Context) 핸들을 얻어온다.
        //mFrontGp = Gdiplus::Graphics::FromHWND(mHWnd);

        // 백버퍼용 비트맵(비트맵 사이즈를 우선 정사이즈로 설정한다.)
        //mBackBmp = new Gdiplus::Bitmap(mWidth, mHeight);

        // 그래픽스에 백버퍼 비트맵을 지정해준다.
        //mBackGp = Gdiplus::Graphics::FromImage(mBackBmp);

        mBrush[(int)eColorType::Red] = new Gdiplus::SolidBrush(Gdiplus::Color(255, 0, 0));
        mBrush[(int)eColorType::Green] = new Gdiplus::SolidBrush(Gdiplus::Color(0, 255, 0));
        mBrush[(int)eColorType::Black] = new Gdiplus::SolidBrush(Gdiplus::Color(0, 0, 0));
        mBrush[(int)eColorType::Blue] = new Gdiplus::SolidBrush(Gdiplus::Color(0, 0, 255));
        mBrush[(int)eColorType::Yellow] = new Gdiplus::SolidBrush(Gdiplus::Color(255, 255, 0));

        mPen[(int)eColorType::Red] = new Gdiplus::Pen(Gdiplus::Color(255, 0, 0));
        mPen[(int)eColorType::Green] = new Gdiplus::Pen(Gdiplus::Color(0, 255, 0));
        mPen[(int)eColorType::Black] = new Gdiplus::Pen(Gdiplus::Color(0, 0, 0));
        mPen[(int)eColorType::Blue] = new Gdiplus::Pen(Gdiplus::Color(0, 0, 255));
        mPen[(int)eColorType::Yellow] = new Gdiplus::Pen(Gdiplus::Color(255, 255, 0));

        // Initialize
        CTime::Initialize();
        CInput::Initialize();
        CSceneManager::Initialize();

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
        CSceneManager::Update();

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
        mBackGp->FillRectangle(mBrush[(int)eColorType::Blue], 0, 0, 1600, 900);
        CTime::Render();
        CInput::Render(mBackGp);
        CSceneManager::Render(mBackGp);

        BitBlt(mHDC, 0, 0, mWidth, mHeight, mBackHDC, 0, 0, SRCCOPY);
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
            CW_USEDEFAULT, 0, 1600, 900, nullptr, nullptr, mHInst, nullptr);

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
