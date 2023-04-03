#pragma once
#include "CGameObject.h"
#include "CScene.h"
#include "CSceneManager.h"
#include "CTransform.h"

namespace kyr
{
	template<typename T>
	static inline T* Instantiate(eLayerType type)
	{
		T* gameObj = new T();
		CScene* scene = CSceneManager::GetActiveScene();
		scene->AddGameObject(gameObj, type);
		gameObj->Initialize();

		return gameObj;
	}

	template<typename T>
	static inline T* Instantiate(Vector2 pos, eLayerType type)
	{
		T* gameObj = new T();
		CScene* scene = CSceneManager::GetActiveScene();
		scene->AddGameObject(gameObj, type);
		gameObj->CGameObject::GetComponent<CTransform>()->SetPos(pos);
		gameObj->Initialize();

		return gameObj;
	}

	static void Destroy(CGameObject* obj)
	{
		obj->SetState(CGameObject::eState::InActive);
	}
}