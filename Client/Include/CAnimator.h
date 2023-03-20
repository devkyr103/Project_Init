#pragma once
#include "Component.h"
#include "CAnimation.h"
#include "CImage.h"

namespace kyr
{
	class CAnimator :
		public Component
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

		// Sprite Sheet
		void CreateAnimation(const std::wstring& name
			, CImage* sheet
			, Vector2 leftTop
			, UINT column, UINT row, UINT spriteLength
			, Vector2 offset, float duration);

		// Sprites
		void CreateAnimations(const std::wstring& path, Vector2 offset, float duration);

		CAnimation* FindAnimation(const std::wstring& name);
		void play(const std::wstring& name, bool loop);

		Events* FindEvents(const std::wstring& name);
		//std::function<void()>& getstartevent(const std::wstring& name);
		//std::function<void()>& getcompleteevent(const std::wstring& name);
		//std::function<void()>& getendevent(const std::wstring& name);

	private:
		std::map<std::wstring, CAnimation*> mAnimations;
		std::map<std::wstring, Events*> mEvents;
		CAnimation* mActiveAnimation{};
		//CImage* mSpriteSheet{};
		bool mbLoop{};
	};

}

