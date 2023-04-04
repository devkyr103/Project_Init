#pragma once
#include "CGameObject.h"

namespace kyr
{
	class CBackImage;
	class CPaintingObj :
		public CGameObject
	{
	public:
		CPaintingObj();
		~CPaintingObj();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(Gdiplus::Graphics* gp);
		virtual void Release();

		virtual void OnCollisionEnter(class CCollider* other);
		virtual void OnCollisionStay(class CCollider* other);
		virtual void OnCollisionExit(class CCollider* other);

	private:
		CBackImage* mBackImage{};
	};

}
