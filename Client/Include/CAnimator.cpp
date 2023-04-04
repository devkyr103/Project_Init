#include "CAnimator.h"
#include "CResourceManager.h"
#include "GdiplusHelperfucntions.h"

namespace kyr
{
	CAnimator::CAnimator()
		: CComponent(eComponentType::Animator)
	{
	}

	CAnimator::~CAnimator()
	{
		for (auto &animation : mAnimations)
		{
			delete animation.second;
			animation.second = nullptr;
		}

		for (auto& events : mEvents)
		{
			SAFE_DELETE(events.second);
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

			if (mActiveAnimation->IsComplete())
			{
				CAnimator::Events* events = FindEvents(mActiveAnimation->GetName());

				if (events != nullptr)
					events->mCompleteEvent();

				mActiveAnimation->Reset();
			}

			if (mbLoop && mActiveAnimation->IsComplete())
				mActiveAnimation->Reset();
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
		animation->SetAnimationName(name);
		animation->SetAnimator(this);

		mAnimations.insert(std::make_pair(name, animation));
		Events* event = new Events();
		mEvents.insert(std::make_pair(name, event));
	}

	void CAnimator::CreateAnimations(const std::wstring& path, Vector2 offset, float duration)
	{
		UINT width{};
		UINT height{};
		UINT fileCount{};

		std::filesystem::path fs(path);
		std::vector<CImage*> images{};

		for (const auto& p : std::filesystem::recursive_directory_iterator(path))
		{
			std::wstring fileName = p.path().filename();
			std::wstring fullName = path + L"\\" + fileName;

			CImage* image = CResourceManager::Load<CImage>(fileName, fullName);

			images.push_back(image);

			// sprite 크기가 동일하지 않을 경우 sheet 생성 시 크기 설정
			if (width < image->GetWidth())
			{
				width = image->GetWidth();
			}

			if (height < image->GetHeight())
			{
				height = image->GetHeight();
			}

			fileCount++;
		}

		width++;
		height++;

		std::wstring key = fs.parent_path().filename();
		key += fs.filename();
		CImage* SpriteSheet = CImage::Create(key, width * fileCount, height);

		int index{};
		Gdiplus::Graphics* gp = new Gdiplus::Graphics(SpriteSheet->GetBitmap());

		for (CImage* image : images)
		{
			int centerX = (width - image->GetWidth()) / 2;
			int centerY = (height - image->GetHeight());

			gp->DrawImage(image->GetBitmap()
			, width * index + centerX, centerY
			, image->GetWidth(), image->GetHeight());

			index++;
		}

		delete gp;

		// Sheet 저장
		//CLSID pngClsid;
		//GetEncoderClsid(L"image/png", &pngClsid);
		//mSpriteSheet->GetBitmap()->Save(L"test.png", &pngClsid, NULL);

		CreateAnimation(key, SpriteSheet, Vector2::Zero, index, 1, index, offset, duration);
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
		if (mActiveAnimation != nullptr)
		{
			CAnimator::Events* prevEvents
				= FindEvents(mActiveAnimation->GetName());

			if (prevEvents != nullptr)
				prevEvents->mEndEvent();
		}

		mActiveAnimation = FindAnimation(name);
		mActiveAnimation->Reset();
		mbLoop = loop;

		CAnimator::Events* events
			= FindEvents(mActiveAnimation->GetName());

		if (events != nullptr)
			events->mStartEvent();
	}

	CAnimator::Events* CAnimator::FindEvents(const std::wstring& name)
	{
		std::map<std::wstring, Events*>::iterator iter = mEvents.find(name);

		if (iter == mEvents.end())
			return nullptr;

		return iter->second;
	}

	std::function<void()>& CAnimator::GetStartEvent(const std::wstring& name)
	{
		CAnimation* animation = FindAnimation(name);

		CAnimator::Events* events = FindEvents(animation->GetAnimationName());

		return events->mStartEvent.mEvent;
	}

	std::function<void()>& CAnimator::GetCompleteEvent(const std::wstring& name)
	{
		CAnimation* animation = FindAnimation(name);

		CAnimator::Events* events = FindEvents(animation->GetAnimationName());

		return events->mCompleteEvent.mEvent;
	}

	std::function<void()>& CAnimator::GetEndEvent(const std::wstring& name)
	{
		CAnimation* animation = FindAnimation(name);

		CAnimator::Events* events = FindEvents(animation->GetAnimationName());

		return events->mEndEvent.mEvent;
	}

}