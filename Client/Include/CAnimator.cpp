#include "CAnimator.h"

namespace kyr
{
	CAnimator::CAnimator()
		: Component(eComponentType::Animator)
		, mActiveAnimation{}
		, mSpriteSheet{}
		, mbLoop{}
	{
	}

	CAnimator::~CAnimator()
	{
		for (auto animation : mAnimations)
		{
			delete animation.second;
			animation.second = nullptr;
		}

	}

	void CAnimator::Initialize()
	{
	}

	void CAnimator::Update()
	{
		if (mActiveAnimation)
		{
			mActiveAnimation->Update();

			if (mbLoop && mActiveAnimation->IsComplete())
			{
				mActiveAnimation->Reset();
			}
		}
	}

	void CAnimator::Render(Gdiplus::Graphics* gp)
	{
		if (mActiveAnimation)
		{
			mActiveAnimation->Render(gp);
		}
	}

	void CAnimator::Release()
	{
	}

	void CAnimator::CreateAnimation(const std::wstring& name, CImage* sheet, Vector2 leftTop, UINT column, UINT row, UINT spriteLength, Vector2 offset, float duration)
	{
		CAnimation* animation = FindAnimation(name);

		if (animation != nullptr)
			return;

		animation = new CAnimation();
		animation->Create(sheet, leftTop, column, row, spriteLength, offset, duration);
		animation->SetName(name);
		animation->SetAnimator(this);

		mAnimations.insert(std::make_pair(name, animation));
	}


	void CAnimator::CreateAnimations()
	{
	}

	CAnimation* CAnimator::FindAnimation(const std::wstring& name)
	{
		std::map<std::wstring, CAnimation*>::iterator iter = mAnimations.find(name);

		if (iter == mAnimations.end())
			return nullptr;

		return iter->second;
	}

	void CAnimator::play(const std::wstring& name, bool loop)
	{
		mActiveAnimation = FindAnimation(name);
		mbLoop = loop;
	}

	CAnimator::Events* CAnimator::FindEvents(const std::wstring& name)
	{
		return nullptr;
	}

	//std::function<void()>& CAnimator::GetStartEvent(const std::wstring& name)
	//{
	//	// // O: 여기에 return 문을 삽입합니다.
	//}

	//std::function<void()>& CAnimator::GetCompleteEvent(const std::wstring& name)
	//{
	//	// // O: 여기에 return 문을 삽입합니다.
	//}

	//std::function<void()>& CAnimator::GetEndEvent(const std::wstring& name)
	//{
	//	// // O: 여기에 return 문을 삽입합니다.
	//}

}