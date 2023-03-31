#pragma once
#include "Component.h"

namespace kyr
{
	class CCollider :
		public Component
	{
	public:
		CCollider();
		~CCollider();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(Gdiplus::Graphics* gp);
		virtual void Release();

		virtual void OnCollisionEnter(CCollider* other);
		virtual void OnCollisionStay(CCollider* other);
		virtual void OnCollisionExit(CCollider* other);

		void SetPos(Vector2 pos) { mPos = pos; }
		void SetSize(Vector2 size) { mSize = size; };
		void SetOffset(Vector2 offset) { mOffset = offset; }

		Vector2 GetPos() { return mPos; }
		Vector2 GetSize() { return mSize; }
		Vector2 GetOffset() { return mOffset; }

		UINT GetID() { return mID; }

	private:
		static UINT ColliderNumber;
		UINT mCollisionCount{};
		UINT mID{};
		
		Vector2 mPos{};
		Vector2 mSize{100.f, 100.f};
		Vector2 mOffset{};
	};

}

