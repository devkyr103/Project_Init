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
		void SetSize(Vector2 size) { mSize = size; }
		Vector2 GetPos() { return mPos; }
		Vector2 GetSize() { return mSize; }
		
	private:
		Vector2 mPos;
		Vector2 mSize;
	};
}


