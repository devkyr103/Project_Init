#include "CBackImage.h"
#include "CGameObject.h"
#include "CTransform.h"
#include "CImage.h"

namespace kyr
{
	CBackImage::CBackImage()
		: CComponent(eComponentType::BackImage)
	{
	}

	CBackImage::~CBackImage()
	{
	}

	void CBackImage::Initialize()
	{
	}

	void CBackImage::Update()
	{
	}

	void CBackImage::Render(Gdiplus::Graphics* gp)
	{
		CTransform* tr = GetOwner()->GetComponent<CTransform>();
		Vector2 pos = tr->GetPos();
		Vector2 pivot = tr->GetPivot();

		if (mCache)
		{
			pos.x -= mImage->GetWidth() * pivot.x;
			pos.y -= mImage->GetHeight() * pivot.y;

			gp->DrawCachedBitmap(mImage->GetCachedBitmap(), pos.x, pos.y);
		}
		else
		{
			pos.x -= mSize.x * pivot.x;
			pos.y -= mSize.y * pivot.y;

			gp->DrawImage(mImage->GetBitmap()
				, Gdiplus::RectF(pos.x, pos.y, mSize.x, mSize.y)
				, 0, 0, mImage->GetWidth(), mImage->GetHeight()
				, Gdiplus::UnitPixel, mImage->GetImageAttributes());
		}
	}

	void CBackImage::Release()
	{
	}

}