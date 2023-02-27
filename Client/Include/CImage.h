#pragma once
#include "CResource.h"

namespace kyr
{
	class CImage :
		public CResource
	{
	public:
		CImage();
		~CImage();

		virtual HRESULT Load(const std::wstring& path) override;

		Gdiplus::Image* GetImage() { return mImage; }
		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }

	private:
		Gdiplus::Image*				mImage;     // 로딩한 이미지
		UINT						mWidth;
		UINT						mHeight;
		//Gdiplus::ImageAttributes  ImageAtt;   // Alpha, Colorkey 설정을 위한 속성
		//Gdiplus::ColorMatrix      ColorMtrx;  // ImageAtt에 적용할 Mtrx(Alpha 값에 사용)
		//COLORREF					ColorKey;   // 지정한 RGB 값을 이미지에서 렌더링하지 않음
	};
}
