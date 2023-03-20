#include "CAnimation.h"
#include "CTime.h"
#include "CImage.h"
#include "CAnimator.h"
#include "CTransform.h"
#include "CGameObject.h"

namespace kyr
{
	CAnimation::CAnimation()
	{
	}

	CAnimation::~CAnimation()
	{
	}

	void CAnimation::Initialize()
	{
	}

	void CAnimation::Update()
	{
		if (mbComplete == true)
			return;

		mTime += (float)CTime::GetDeltaTime();

		if (mVecSpriteInfo[mSpriteIndex].duration < mTime)
		{
			mTime = 0.f;

			if (mVecSpriteInfo.size() <= (size_t)mSpriteIndex + 1)
			{
				mbComplete = true;
			}
			else
			{
				mSpriteIndex++;
			}
		}
	}

	void CAnimation::Render(Gdiplus::Graphics* gp)
	{
		CTransform* tr = mAnimator->GetOwner()->GetComponent<CTransform>();

		/*gp->DrawImage(mSpriteSheet->GetBitmap(), tr->GetPos().x, tr->GetPos().y
			, mSpriteSheet[mSpriteIndex].leftTop.x, mSpriteSheet[mSpriteIndex].leftTop.y
			, mSpriteSheet[mSpriteIndex].size.x, mSpriteSheet[mSpriteIndex].size.y
			, Gdiplus::UnitPixel);*/

		Vector2 pos = tr->GetPos();
		Vector2 scale = tr->GetScale();
		Vector2 pivot = tr->GetPivot();
		//Vector2 size = mVecSpriteInfo[mSpriteIndex].size;

		

		// scale, offset, pivot 적용됨 -- 정리 필요 
		gp->DrawImage(mSpriteSheet->GetBitmap()
			, Gdiplus::RectF(pos.x - (mVecSpriteInfo[mSpriteIndex].size.x * scale.x * pivot.x) + (mVecSpriteInfo[mSpriteIndex].offset.x * scale.x)
				, pos.y - (mVecSpriteInfo[mSpriteIndex].size.y * scale.y * pivot.y) + (mVecSpriteInfo[mSpriteIndex].offset.y * scale.y)
				, mVecSpriteInfo[mSpriteIndex].size.x * scale.x
				, mVecSpriteInfo[mSpriteIndex].size.y * scale.y)
			, mVecSpriteInfo[mSpriteIndex].leftTop.x, mVecSpriteInfo[mSpriteIndex].leftTop.y
			, mVecSpriteInfo[mSpriteIndex].size.x, mVecSpriteInfo[mSpriteIndex].size.y
			, Gdiplus::UnitPixel, mSpriteSheet->GetImageAttributes());
	}

	void CAnimation::Create(CImage* sheet, Vector2 leftTop, UINT column, UINT row, UINT spriteLength, Vector2 offset, float duration)
	{
		mSpriteSheet = sheet;

		Vector2 size = Vector2::One;
		size.x = mSpriteSheet->GetWidth() / (float)column;
		size.y = mSpriteSheet->GetHeight() / (float)row;

		for (size_t i = 0; i < spriteLength; i++)
		{
			SpriteInfo spriteInfo;

			spriteInfo.leftTop.x = leftTop.x + (size.x * i);
			spriteInfo.leftTop.y = leftTop.y;
			spriteInfo.size = size;
			spriteInfo.offset = offset;
			spriteInfo.duration = duration;

			mVecSpriteInfo.push_back(spriteInfo);
		}
	}

	void CAnimation::Reset()
	{
		mSpriteIndex = 0;
		mTime = 0.0f;
		mbComplete = false;
	}

}