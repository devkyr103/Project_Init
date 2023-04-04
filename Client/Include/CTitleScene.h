#pragma once
#include "CScene.h"

namespace kyr
{
	class CTitleObject;
	class CTitleScene : public CScene
	{
	public:
		CTitleScene();
		~CTitleScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(Gdiplus::Graphics* gp) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
		CTitleObject* mTitleObject{};
	};
}