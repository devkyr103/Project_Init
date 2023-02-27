#include "CGameObject.h"
#include "CTransform.h"

namespace kyr
{
	CGameObject::CGameObject()
	{
		mComponents.resize((UINT)eComponentType::End);
		AddComponent<CTransform>();
	}

	CGameObject::~CGameObject()
	{
		for (Component* comp : mComponents)
		{
			delete comp;
			comp = nullptr;
		}
	}

	void CGameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Initialize();
		}
	}

	void CGameObject::Update()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Update();
		}
	}

	void CGameObject::Render(Gdiplus::Graphics* gp)
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Render(gp);
		}
	}

	void CGameObject::Release()
	{
	}

}