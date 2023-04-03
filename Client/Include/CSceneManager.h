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
		static void Destroy();
		static void Release();

		static void LoadScene(eSceneType type);
		static CScene* GetActiveScene() { return mActiveScene; }
		static Vector2 GetWorldSize() { return mActiveScene->GetWorldSize(); }
		static void SetActiveScene(CScene* scene) { mActiveScene = scene; }
		static void SetWorldSize(Vector2 size) { mActiveScene->SetWorldSize(size); }

	private:
		static std::vector<CScene*> mScenes;
		static CScene* mActiveScene;
	};
}


