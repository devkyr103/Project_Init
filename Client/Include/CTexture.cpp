#include "CTexture.h"
#include "CTransform.h"
#include "CGameObject.h"

namespace kyr
{
	CTexture::CTexture()
		: Component(eComponentType::Texture)
	{
	}

	CTexture::~CTexture()
	{
	}

	void CTexture::Initialize()
	{
	}

	void CTexture::Update()
	{
	}

	void CTexture::Render(Gdiplus::Graphics* gp)
	{
		CTransform* tr = GetOwner()->GetComponent<CTransform>();

		Vector2 pos = tr->GetPos();

		gp->DrawImage(mImage->GetImage(), pos.x, pos.y);
	}

	void CTexture::Release()
	{
	}

	bool CTexture::SetImage(std::wstring& name)
	{
		return false;
	}

}