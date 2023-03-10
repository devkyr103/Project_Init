#pragma once
#include "CGameObject.h"

namespace kyr
{
	class CImage;
	class CBackObject :
		public CGameObject
	{
		CBackObject();
		~CBackObject();

		void Initialize();
		void Update();
		void Render(Gdiplus::Graphics* gp);
		void Release();

	private:
		CImage* mImage;
	};
}


