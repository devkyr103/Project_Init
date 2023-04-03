#pragma once
#include "CScene.h"

namespace kyr
{
	class CPlayableObject;
	class CPlayeScene : public CScene
	{
	public:
		CPlayeScene();
		~CPlayeScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(Gdiplus::Graphics* gp) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
		CPlayableObject* mPlayableObject{};
	};
}
