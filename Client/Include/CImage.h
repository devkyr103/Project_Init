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
		Gdiplus::Bitmap* mBitmap{};     // �ε��� �̹���

		Gdiplus::ImageAttributes	mImageAtt{};		// Alpha, Colorkey ������ ���� �Ӽ�
		Gdiplus::ColorMatrix		mColorMtrx{};		// ImageAtt�� ������ Mtrx(Alpha ���� ���)
		COLORREF					mColorKey{};		// ������ RGB ���� �̹������� ���������� ����
		bool						mEnableColorKey{};	

		UINT mWidth{};
		UINT mHeight{};
	};
}
