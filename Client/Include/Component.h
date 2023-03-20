#pragma once
#include "CEntity.h"

namespace kyr
{
	class CGameObject;
	class Component
		: public CEntity
	{
	public:
		Component(eComponentType type);
		~Component();
		
		virtual void Initialize();
		virtual void Update();
		virtual void Render(Gdiplus::Graphics* gp);
		virtual void Release();

		eComponentType GetType() { return mType; }
		void SetOwner(CGameObject* owner) { mOwner = owner; }
		CGameObject* GetOwner() { return mOwner; }

	private:
		const eComponentType mType{};
		CGameObject* mOwner{};
	};
}


