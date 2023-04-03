#pragma once
#include "CEntity.h"
#include "CLayer.h"

namespace kyr
{
	class CScene :
		public CEntity
	{
	public:
		CScene();
		virtual ~CScene();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(Gdiplus::Graphics* gp);
		virtual void Destroy();
		virtual void Release();

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(CGameObject* obj, eLayerType layer);

		std::vector<CGameObject*>& GetGameObjects(eLayerType layer);

		Vector2 GetWorldSize() { return mWorldSize; }
		void SetWorldSize(Vector2 size) { mWorldSize = size; }

	private:
		std::vector<CLayer> mLayers{};

		Vector2 mWorldSize;
	};
}


