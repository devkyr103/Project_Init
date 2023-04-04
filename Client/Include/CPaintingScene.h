#pragma once
#include "CScene.h"

namespace kyr
{
	class CBackGroundObj;
	class CPaintingObj;
	class CPaintingScene :
		public CScene
	{
	public:
		CPaintingScene();
		virtual ~CPaintingScene();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(Gdiplus::Graphics* gp);
		virtual void Destroy();
		virtual void Release();

		virtual void OnEnter();
		virtual void OnExit();

	private:
		CBackGroundObj* mBG;
		CPaintingObj*	mPainting;
	};


}

