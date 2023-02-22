#include "CGameManager.h"
#include "resource.h"

DEFINITION_SINGLE(CGameManager);

bool CGameManager::m_Loop = true;

CGameManager::CGameManager()
    : m_hInst{}
    , m_hWnd{}
    , gdiplusToken{}
    , m_hMenu{}
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //_CrtSetBreakAlloc();
}

CGameManager::~CGameManager()
{

}

bool CGameManager::Init(HINSTANCE hInst)
{
    m_hInst = hInst;

    Register();

    Create();

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
    return false;
}

bool CGameManager::PostUpdate()
{
    return false;
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
