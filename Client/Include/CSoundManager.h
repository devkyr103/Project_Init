#pragma once
#include "CommonInclude.h"

namespace kyr
{
	class CSound;
	class CSoundManager
	{
	public:
		static bool Initialize();
		static LPDIRECTSOUND8 GetDevice() { return mSoundDevice; }

	private:
		static LPDIRECTSOUND8 mSoundDevice;
	};

}


