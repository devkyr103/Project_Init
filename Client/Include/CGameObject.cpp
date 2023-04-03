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
		for (CComponent* comp : mComponents)
		{
			delete comp;
			comp = nullptr;
		}
	}

	void CGameObject::Initialize()
	{
		for (CComponent* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Initialize();
		}
	}

	void CGameObject::Update()
	{
		for (CComponent* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Update();
		}
	}

	void CGameObject::Render(Gdiplus::Graphics* gp)
	{
		for (CComponent* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Render(gp);
		}
	}

	void CGameObject::Release()
	{
	}

	void CGameObject::OnCollisionEnter(CCollider* other)
	{
	}

	void CGameObject::OnCollisionStay(CCollider* other)
	{
	}

	void CGameObject::OnCollisionExit(CCollider* other)
	{
	}

}