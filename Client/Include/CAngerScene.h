#pragma once
#include "CScene.h"

namespace kyr
{
    class CAngerScene :
        public CScene
    {
	public:
		CAngerScene();
		~CAngerScene();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(Gdiplus::Graphics* gp);
		virtual void Release();

		virtual void OnEnter();
		virtual void OnExit();
    };
}


