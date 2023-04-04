#pragma once
#include "CScene.h"

namespace kyr
{

	class CPrideScene :
		public CScene
	{
	public:
		CPrideScene();
		virtual ~CPrideScene();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(Gdiplus::Graphics* gp);
		virtual void Release();

		virtual void OnEnter();
		virtual void OnExit();
	};

}

