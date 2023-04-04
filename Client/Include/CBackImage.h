#pragma once
#include "CComponent.h"

namespace kyr
{
	class CImage;
	class CBackImage :
		public CComponent
	{
	public:
		CBackImage();
		~CBackImage();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(Gdiplus::Graphics* gp);
		virtual void Release();

	public:
		CImage* GetImage() { return mImage; }

		void SetImage(CImage* image) { mImage = image; }
		void SetSize(Vector2 size) { mSize = size; }
		void SetCache(bool b) { mCache = b; }
	private:
		CImage* mImage{};
		Vector2 mSize{Vector2(100.f, 100.f)};
		bool	mCache{};
	};

}

