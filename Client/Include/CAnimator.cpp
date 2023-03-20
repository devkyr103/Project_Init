#include "CAnimator.h"
#include "CResources.h"
#include "GdiplusHelperfucntions.h"

namespace kyr
{
	CAnimator::CAnimator()
		: Component(eComponentType::Animator)
	{
	}

	CAnimator::~CAnimator()
	{
		for (auto &animation : mAnimations)
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

			CImage* image = CResources::Load<CImage>(fileName, fullName);

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