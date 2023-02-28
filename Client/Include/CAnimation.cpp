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

		if (mSpriteSheet[mSpriteIndex].duration < mTime)
		{
			mTime = 0.f;

			if (mSpriteSheet.size() <= (size_t)mSpriteIndex + 1)
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
		
		gp->DrawImage(mSheetImage->GetImage(), tr->GetPos().x, tr->GetPos().y
			, mSpriteSheet[mSpriteIndex].leftTop.x, mSpriteSheet[mSpriteIndex].leftTop.y
			, mSpriteSheet[mSpriteIndex].size.x, mSpriteSheet[mSpriteIndex].size.y
			, Gdiplus::UnitPixel);
	}

	void CAnimation::Create(CImage* sheet, Vector2 leftTop, UINT column, UINT row, UINT spriteLength, Vector2 offset, float duration)
	{
		mSheetImage = sheet;

		Vector2 size = Vector2::One;
		size.x = mSheetImage->GetWidth() / (float)column;
		size.y = mSheetImage->GetHeight() / (float)row;

		for (size_t i = 0; i < spriteLength; i++)
		{
			Sprite spriteInfo;

			spriteInfo.leftTop.x = leftTop.x + (size.x * i);
			spriteInfo.leftTop.y = leftTop.y;
			spriteInfo.size = size;
			spriteInfo.offset = offset;
			spriteInfo.duration = duration;

			mSpriteSheet.push_back(spriteInfo);
		}
	}

	void CAnimation::Reset()
	{
		mSpriteIndex = 0;
		mTime = 0.0f;
		mbComplete = false;
	}

}