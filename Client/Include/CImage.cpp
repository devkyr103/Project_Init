#include "CImage.h"
#include "CResources.h"

namespace kyr
{
	CImage::CImage()
	{
	}

	CImage::~CImage()
	{
	}

	CImage* CImage::Create(const std::wstring& name, UINT width, UINT height)
	{
		if (width == 0 || height == 0)
			return nullptr;

		CImage* image = CResources::Find<CImage>(name);

		if (image != nullptr)
			return image;

		image = new CImage();

		image->mBitmap = new Gdiplus::Bitmap(width, height);
		image->mWidth = width;
		image->mHeight = height;

		image->SetKey(name);
		CResources::Insert<CImage>(name, image);

		return image;
	}

	HRESULT CImage::Load(const std::wstring& path)
	{
		mBitmap = Gdiplus::Bitmap::FromFile((WCHAR*)path.c_str());

		if (!mBitmap)
			return E_FAIL;

		mWidth = mBitmap->GetWidth();
		mHeight = mBitmap->GetHeight();

		return S_OK;
	}

}