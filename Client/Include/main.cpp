#pragma

#include "CGameManager.h"

#define MAX_LOADSTRING 100


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
   
    if (!CGameManager::GetInst()->Init(hInstance))
    {
        CGameManager::DestroyInst();

        return 0;
    }

    int ReturnValue = CGameManager::GetInst()->Run();

    CGameManager::DestroyInst();

    return ReturnValue;
}

