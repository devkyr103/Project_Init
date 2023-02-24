#include "CGameManager.h"
#include "CTimer.h"
#include "resource.h"

DEFINITION_SINGLE(CGameManager);

bool CGameManager::m_Loop = true;

CGameManager::CGameManager()
    : m_hInst{}
    , m_hWnd{}
    , gdiplusToken{}
    , m_Timer{}
    , m_hMenu{}
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //_CrtSetBreakAlloc();
}

CGameManager::~CGameManager()
{
    SAFE_DELETE(m_Timer);

    Gdiplus::GdiplusShutdown(gdiplusToken);
}

bool CGameManager::Init(HINSTANCE hInst)
{
    m_hInst = hInst;

    Register();

    Create();

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

    m_Timer = new CTimer{};

    m_Timer->Init();

    return true;
}

int CGameManager::Run()
{
    MSG msg{};

    
    while (m_Loop)
    {
        if (!PeekMessage(&msg, m_hWnd, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            Logic();
        }
    }

    return (int)msg.wParam;
}

void CGameManager::Logic()
{
    m_Timer->Update();
  
    Input();
    Update();
    PostUpdate();
    Collision();
    Render();

}

void CGameManager::Input()
{
}

bool CGameManager::Update()
{
    return true;
}

bool CGameManager::PostUpdate()
{
    return true;
}

void CGameManager::Collision()
{
}

void CGameManager::Render()
{
    
}

void CGameManager::Register()
{
    WNDCLASSEXW wcex{};

    wcex.cbSize = sizeof(WNDCLASSEXW);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = m_hInst;
    wcex.hIcon = LoadIcon(m_hInst, MAKEINTRESOURCE(IDI_CLIENT));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = TEXT("Init()");
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    RegisterClassExW(&wcex);
}

bool CGameManager::Create()
{
    m_hWnd = CreateWindowW(TEXT("Init()"), TEXT("Init()"), WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, m_hInst, nullptr);

    if (!m_hWnd)
    {
        return FALSE;
    }

    ShowWindow(m_hWnd, SW_SHOW);
    UpdateWindow(m_hWnd);

    return true;
}

LRESULT CGameManager::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
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
