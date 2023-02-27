#include "CImage.h"

namespace kyr
{
	CImage::CImage()
		: mImage{}
		, mWidth{}
		, mHeight{}
	{
	}

	CImage::~CImage()
	{
	}

	HRESULT CImage::Load(const std::wstring& path)
	{
		mImage = Gdiplus::Image::FromFile((WCHAR*)path.c_str());

		if (!mImage)
			return E_FAIL;

		mWidth = mImage->GetWidth();
		mHeight = mImage->GetHeight();

		return S_OK;
	}

}