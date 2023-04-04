#include "CPaintingObj.h"
#include "CResourceManager.h"
#include "CImage.h"

namespace kyr
{
	CPaintingObj::CPaintingObj()
	{
	}

	CPaintingObj::~CPaintingObj()
	{
	}

	void CPaintingObj::Initialize()
	{

	}

	void CPaintingObj::Update()
	{
	}

	void CPaintingObj::Render(Gdiplus::Graphics* gp)
	{
		CGameObject::Render(gp);
	}

	void CPaintingObj::Release()
	{
		CGameObject::Release();
	}

	void CPaintingObj::OnCollisionEnter(CCollider* other)
	{
	}

	void CPaintingObj::OnCollisionStay(CCollider* other)
	{
	}

	void CPaintingObj::OnCollisionExit(CCollider* other)
	{
	}

}