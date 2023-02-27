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
		Gdiplus::Image*				mImage;     // �ε��� �̹���
		UINT						mWidth;
		UINT						mHeight;
		//Gdiplus::ImageAttributes  ImageAtt;   // Alpha, Colorkey ������ ���� �Ӽ�
		//Gdiplus::ColorMatrix      ColorMtrx;  // ImageAtt�� ������ Mtrx(Alpha ���� ���)
		//COLORREF					ColorKey;   // ������ RGB ���� �̹������� ���������� ����
	};
}
