#pragma once
#include "CGameObject.h"

namespace kyr
{
	class CImage;
	class CBackGroundObj :
		public CGameObject
	{
	public:
		CBackGroundObj();
		~CBackGroundObj();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(Gdiplus::Graphics* gp);
		virtual void Release();

		virtual void OnCollisionEnter(class CCollider* other);
		virtual void OnCollisionStay(class CCollider* other);
		virtual void OnCollisionExit(class CCollider* other);

	};

}

