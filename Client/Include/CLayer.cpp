#include "CLayer.h"

namespace kyr
{
	CLayer::CLayer()
	{
	}

	CLayer::~CLayer()
	{
		for (CGameObject* gameObj : mGameObjects)
		{
			delete gameObj;
			gameObj = nullptr;
		}
	}

	void CLayer::Initialize()
	{
		for (CGameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Initialize();
		}
	}

	void CLayer::Update()
	{
		for (CGameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Update();
		}
	}

	void CLayer::Render(Gdiplus::Graphics* gp)
	{
		for (CGameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Render(gp);
		}
	}

	void CLayer::Release()
	{
	}

	void CLayer::AddGameObject(CGameObject* gameObj)
	{
		if (gameObj == nullptr)
			return;

		mGameObjects.push_back(gameObj);
	}

}