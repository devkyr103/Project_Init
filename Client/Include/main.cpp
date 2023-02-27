#pragma

#include "CApplication.h"

#define MAX_LOADSTRING 100


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{

    if (!kyr::CApplication::GetInst()->Init(hInstance))
    {
        kyr::CApplication::DestroyInst();

        return 0;
    }

    int ReturnValue = kyr::CApplication::GetInst()->Run();

    kyr::CApplication::DestroyInst();

    return ReturnValue;
}

