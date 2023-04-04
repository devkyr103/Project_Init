#include "CSoundManager.h"
#include "CApplication.h"

namespace kyr
{
	LPDIRECTSOUND8 CSoundManager::mSoundDevice;

	bool CSoundManager::Initialize()
	{
		if (FAILED(DirectSoundCreate8(NULL, &mSoundDevice, NULL)))
		{
			MessageBox(NULL, L"사운드디바이스생성실패", L"SYSTEM ERROR", MB_OK);
			return false;
		}

		// 사운드 디바이스 협조레벨 설정.
		HWND hWnd = CApplication::GetHWnd();
		if (FAILED(mSoundDevice->SetCooperativeLevel(hWnd, DISCL_EXCLUSIVE))) // Flag값 정리
		{
			MessageBox(NULL, L"사운드디바이스 협조레벨 설정", L"SYSTEM ERROR", MB_OK);
			return false;
		}

		return true;
	}
}