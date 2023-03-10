#pragma once
#include "Component.h"
#include "CImage.h"

namespace kyr
{
	class CTexture :
		public Component
	{
	public:
		CTexture();
		~CTexture();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(Gdiplus::Graphics* gp) override;
		virtual void Release() override;

		bool SetImage(std::wstring& name);

	private:
		CImage* mImage{};
	};
}


