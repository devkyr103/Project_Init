#pragma once
#include "CScene.h"

namespace kyr
{
	class CSceneManager
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(Gdiplus::Graphics* gp);
		static void Release();

		static void LoadScene(eSceneType type);

	private:
		static std::vector<CScene*> mScenes;
		static CScene* mActiveScene;
	};
}


