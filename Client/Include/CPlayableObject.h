#pragma once
#include "CGameObject.h"
#include "CImage.h"

namespace kyr
{
	class CAnimator;
	class CPlayableObject :
		public CGameObject
	{
	public:
		CPlayableObject();
		~CPlayableObject();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(Gdiplus::Graphics* gp) override;
		virtual void Release() override;

	private:
		CImage* mImage{};
		CAnimator* mAnimator{};
	};
}


