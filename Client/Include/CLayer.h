#pragma once
#include "CEntity.h"
#include "CGameObject.h"

namespace kyr
{
	class CLayer :
		public CEntity
	{
	public:
		CLayer();
		virtual ~CLayer();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(Gdiplus::Graphics* gp);
		virtual void Release();

		void AddGameObject(CGameObject* gameObj);
		std::vector<CGameObject*>& GetGameObjects() { return mGameObjects; }

	private:
		std::vector<CGameObject*> mGameObjects;
	};
}


