#include "CScene.h"
#include "CSceneManager.h"
#include "CApplication.h"

namespace kyr
{
	CScene::CScene()
	{
		mLayers.reserve(5);
		mLayers.resize((UINT)eLayerType::End);
	}

	CScene::~CScene()
	{
	}

	void CScene::Initialize()
	{
		CSceneManager::SetActiveScene(this);

		mWorldSize.x = (float)CApplication::GetClientWidth();
		mWorldSize.y = (float)CApplication::GetClientHeight();
	}

	void CScene::Update()
	{
		for (CLayer& layer : mLayers)
		{
			layer.Update();
		}
	}

	void CScene::Render(Gdiplus::Graphics* gp)
	{
		for (CLayer& layer : mLayers)
		{
			layer.Render(gp);
		}
	}

	void CScene::Destroy()
	{
		std::vector<CGameObject*> deleteGameObjects{};

		for (CLayer& layer : mLayers)
		{
			std::vector<CGameObject*>& gameObjects = layer.GetGameObjects();

			for (std::vector<CGameObject*>::iterator iter = gameObjects.begin();
				iter != gameObjects.end();)
			{
				if ((*iter)->GetState() == CGameObject::eState::InActive)
				{
					deleteGameObjects.push_back(*iter);
					iter = gameObjects.erase(iter);
				}
				else
				{
					iter++;
				}
			}
		}

		for (CGameObject* gameObject : deleteGameObjects)
		{
			SAFE_DELETE(gameObject);
		}
	}

	void CScene::Release()
	{
	}

	void CScene::OnEnter()
	{
	}

	void CScene::OnExit()
	{
	}

	void CScene::AddGameObject(CGameObject* obj, eLayerType layer)
	{
		mLayers[(UINT)layer].AddGameObject(obj);
	}

	std::vector<CGameObject*>& CScene::GetGameObjects(eLayerType layer)
	{
		return mLayers[(UINT)layer].GetGameObjects();
	}

}