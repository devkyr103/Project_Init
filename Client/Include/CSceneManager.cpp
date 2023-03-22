#include "CSceneManager.h"
#include "CTitleScene.h"
#include "CPlayScene.h"
#include "CollisionManager.h"

namespace kyr
{
	std::vector<CScene*> CSceneManager::mScenes{};
	CScene* CSceneManager::mActiveScene{};

	void CSceneManager::Initialize()
	{
		mScenes.resize((UINT)eSceneType::End);

		mScenes[(UINT)eSceneType::Title] = new CTitleScene();
		mScenes[(UINT)eSceneType::Play] = new CPlayeScene();

		for (CScene* scene : mScenes)
		{
			if (scene == nullptr)
				continue;

			scene->Initialize();
		}


		//mActiveScene = mScenes[(UINT)eSceneType::Play];

		LoadScene(eSceneType::Play);
	}

	void CSceneManager::Update()
	{
		mActiveScene->Update();
	}

	void CSceneManager::Render(Gdiplus::Graphics* gp)
	{
		mActiveScene->Render(gp);
	}

	void CSceneManager::Release()
	{
		for (CScene* scene : mScenes)
		{
			if (scene == nullptr)
				continue;

			delete scene;
			scene = nullptr;
		}
	}

	void CSceneManager::LoadScene(eSceneType type)
	{
		if(mActiveScene)
			mActiveScene->OnExit();

		CollisionManager::Clear();

		mActiveScene = mScenes[(UINT)type];
		mActiveScene->OnEnter();
	}

}