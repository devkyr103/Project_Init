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

		static CImage* Create(const std::wstring& name, UINT width, UINT height);

		virtual HRESULT Load(const std::wstring& path) override;

		void SetAlpha(float alpha)
		{
			Gdiplus::ColorMatrix* cm = GetColorMatrix();

			*cm = { 1.0f, 0.0f, 0.0f, 0.0f, 0.0f
				, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f
				, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f
				, 0.0f, 0.0f, 0.0f, alpha, 0.0f
				, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f };

			mImageAtt.SetColorMatrix(cm);
		}

		void SetColorKey(UCHAR r, UCHAR g, UCHAR b)
		{
			mColorKey = RGB(r, g, b);
			mEnableColorKey = true;
			mImageAtt.SetColorKey(RGB(r, g, b), RGB(r, g, b));
		}

		Gdiplus::Bitmap* GetBitmap() { return mBitmap; }

		Gdiplus::ImageAttributes* GetImageAttributes() { return &mImageAtt; }
		Gdiplus::ColorMatrix* GetColorMatrix() { return &mColorMtrx; }
		COLORREF& GetColorKey() { return mColorKey; }

		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }

	private:
		Gdiplus::Bitmap* mBitmap{};     // 로딩한 이미지

		Gdiplus::ImageAttributes	mImageAtt{};		// Alpha, Colorkey 설정을 위한 속성
		Gdiplus::ColorMatrix		mColorMtrx{};		// ImageAtt에 적용할 Mtrx(Alpha 값에 사용)
		COLORREF					mColorKey{};		// 지정한 RGB 값을 이미지에서 렌더링하지 않음
		bool						mEnableColorKey{};	

		UINT mWidth{};
		UINT mHeight{};
	};
}
