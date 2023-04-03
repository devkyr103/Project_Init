#pragma once
#include "CEntity.h"
#include "Component.h"

namespace kyr
{
	class CGameObject :
		public CEntity
	{
	public:
		enum class eState
		{
			Active,
			Pause,
			InActive
		};

		CGameObject();
		virtual ~CGameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(Gdiplus::Graphics* gp);
		virtual void Release();

		virtual void OnCollisionEnter(class CCollider* other);
		virtual void OnCollisionStay(class CCollider* other);
		virtual void OnCollisionExit(class CCollider* other);

		template<typename T>
		T* AddComponent()
		{
			T* comp = new T();
			UINT compType = (UINT)comp->GetType();
			mComponents[compType] = comp;
			comp->SetOwner(this);

			return comp;
		}

		template<typename T>
		T* GetComponent()
		{
			for (Component* comp : mComponents)
			{
				if (dynamic_cast<T*>(comp))
					return dynamic_cast<T*>(comp);
			}

			return nullptr;
		}

		eState GetState() { return mState; }

		void SetState(eState state) { mState = state; }
		
	private:
		std::vector<Component*> mComponents{};
		eState mState = eState::Active;
	};

}

