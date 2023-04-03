#pragma once
#include "CComponent.h"
#include "CAnimation.h"
#include "CImage.h"

namespace kyr
{
	class CAnimator :
		public CComponent
	{
	public:
		struct  Event
		{
			void operator=(std::function<void()> func)
			{
				mEvent = std::move(func);
			}

			void operator()()
			{
				if (mEvent)
					mEvent();
			}

			std::function<void()> mEvent;
		};

		struct Events
		{
			Event mStartEvent;
			Event mCompleteEvent;
			Event mEndEvent;
		};

	public:
		CAnimator();
		~CAnimator();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(Gdiplus::Graphics* gp) override;
		virtual void Release() override;

		// Sprite Sheet를 지정하여 Animation 생성
		void CreateAnimation(const std::wstring& name
			, CImage* sheet
			, Vector2 leftTop
			, UINT column, UINT row, UINT spriteLength
			, Vector2 offset, float duration);

		// 개별 Sprite로 SpriteSheet 생성하고 CreateAnimation() 호출
		void CreateAnimations(const std::wstring& path, Vector2 offset, float duration);

		CAnimation* FindAnimation(const std::wstring& name);
		void play(const std::wstring& name, bool loop);

		Events* FindEvents(const std::wstring& name);

		std::function<void()>& GetStartEvent(const std::wstring& name);
		std::function<void()>& GetCompleteEvent(const std::wstring& name);
		std::function<void()>& GetEndEvent(const std::wstring& name);

		bool IsComplete() { return mActiveAnimation->IsComplete(); }

	private:
		std::map<std::wstring, CAnimation*> mAnimations{};
		std::map<std::wstring, Events*> mEvents{};

		CAnimation* mActiveAnimation{};
		bool mbLoop{};
	};

}

