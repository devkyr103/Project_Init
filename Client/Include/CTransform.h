#pragma once
#include "Component.h"

namespace kyr
{
	class CTransform :
		public Component
	{
	public:
		CTransform();
		~CTransform();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(Gdiplus::Graphics* gp) override;
		virtual void Release() override;

		void SetPos(Vector2 pos) { mPos = pos; }
		void SetScale(Vector2 size) { mScale = size; }
		void SetPivot(Vector2 pivot) { mPivot = pivot; }
		Vector2 GetPos() { return mPos; }
		Vector2 GetScale() { return mScale; }
		Vector2 GetPivot() { return mPivot; }
		
	private:
		Vector2 mPos{Vector2::Zero};
		Vector2 mScale{Vector2::One};
		Vector2 mPivot{};
	};
}


