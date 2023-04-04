#include "CBackGroundObj.h"
#include "CImage.h"
#include "CTransform.h"
#include "CBackImage.h"
#include "CResourceManager.h"

namespace kyr
{
	CBackGroundObj::CBackGroundObj()
	{
	}

	CBackGroundObj::~CBackGroundObj()
	{
	}

	void CBackGroundObj::Initialize()
	{
		CGameObject::Initialize();
	}

	void CBackGroundObj::Update()
	{
	}

	void CBackGroundObj::Render(Gdiplus::Graphics* gp)
	{
		CGameObject::Render(gp);

		/*Vector2 pos = GetComponent<CTransform>()->GetPos();
		
		gp->DrawCachedBitmap(mImage->GetCachedBitmap(), pos.x, pos.y);*/

		/*gp->DrawImage(mImage->GetBitmap()
			, Gdiplus::RectF(pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight())
			, 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, Gdiplus::UnitPixel, mImage->GetImageAttributes());*/
	}

	void CBackGroundObj::Release()
	{
	}

	void CBackGroundObj::OnCollisionEnter(CCollider* other)
	{
	}

	void CBackGroundObj::OnCollisionStay(CCollider* other)
	{
	}

	void CBackGroundObj::OnCollisionExit(CCollider* other)
	{
	}

}