#pragma once
#include "CResource.h"

namespace kyr
{
	class CSound :
		public CResource
	{
	public:
		virtual HRESULT Load(const std::wstring& path) override;
		bool LoadWavFile(const std::wstring& path);
		void Play(bool loop);
		void Stop(bool reset);
		void SetPosition(float position, bool loop);
		void SetVolume(float volume);
		int GetDecibel(float volume);

	private:
		LPDIRECTSOUNDBUFFER		mSoundBuffer{};
		DSBUFFERDESC			mBufferDesc{};
		int mVolume{};

	};

}

