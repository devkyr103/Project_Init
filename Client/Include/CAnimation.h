#pragma once
#include "CEntity.h"

namespace kyr
{
	class CImage;
	class CAnimator;
	class CAnimation :
		public CEntity
	{
	public:
		struct Sprite
		{
			Vector2 leftTop{};
			Vector2 size{};
			Vector2 offset{};
			float duration{};

			Sprite()
			{

			}
		};

		CAnimation();
		~CAnimation();

		void Initialize();
		void Update();
		void Render(Gdiplus::Graphics* gp);
		void Create(CImage* sheet, Vector2 leftTop, UINT column, UINT row, UINT spriteLength, Vector2 offset, float duration);
		void Reset();

		bool IsComplete() { return mbComplete; }
		void SetAnimator(CAnimator* animator) { mAnimator = animator; }

	private:
		CAnimator* mAnimator{};
		CImage* mSheetImage{};
		std::vector<Sprite> mSpriteSheet{};
		float mTime{};
		bool mbComplete{};
		int mSpriteIndex{};
	};
}

