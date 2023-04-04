#include "CSceneManager.h"
#include "CTitleScene.h"
#include "CPrideScene.h"
#include "CAngerScene.h"
#include "CGreedScene.h"
#include "CCollisionManager.h"
#include "CCamera.h"

namespace kyr
{
	std::vector<CScene*> CSceneManager::mScenes{};
	CScene* CSceneManager::mActiveScene{};

	void CSceneManager::Initialize()
	{
		mScenes.resize((UINT)eSceneType::End);

		mScenes[(UINT)eSceneType::Title] = new CTitleScene();
		mScenes[(UINT)eSceneType::Pride] = new CPrideScene();
		mScenes[(UINT)eSceneType::Anger] = new CAngerScene();
		mScenes[(UINT)eSceneType::Greed] = new CGreedScene();
	

		for (CScene* scene : mScenes)
		{
			if (scene == nullptr)
				continue;

			scene->Initialize();
		}


		//mActiveScene = mScenes[(UINT)eSceneType::Play];

		LoadScene(eSceneType::Title);
	}

	void CSceneManager::Update()
	{
		mActiveScene->Update();
	}

	void CSceneManager::Render(Gdiplus::Graphics* gp)
	{
		mActiveScene->Render(gp);
	}

	void CSceneManager::Destroy()
	{
		mActiveScene->Destroy();
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
		CCamera::Clear();

		if(mActiveScene)
			mActiveScene->OnExit();

		CCollisionManager::Clear();

		mActiveScene = mScenes[(UINT)type];
		mActiveScene->OnEnter();
	}

}