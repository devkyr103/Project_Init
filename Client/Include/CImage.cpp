#include "CImage.h"
#include "CResourceManager.h"
#include "CApplication.h"

namespace kyr
{
	CImage::CImage()
	{
	}

	CImage::~CImage()
	{
	}

	CImage* CImage::Create(const std::wstring& name, UINT width, UINT height, Gdiplus::Color argb)
	{
		if (width == 0 || height == 0)
			return nullptr;

		CImage* image = CResourceManager::Find<CImage>(name);

		if (image != nullptr)
			return image;

		image = new CImage();

		image->mBitmap = new Gdiplus::Bitmap(width, height);
		image->mWidth = width;
		image->mHeight = height;
		
		image->SetKey(name);
		CResourceManager::Insert<CImage>(name, image);

		Gdiplus::Graphics* gp = new Gdiplus::Graphics(image->GetBitmap());
		Gdiplus::Brush* brush = new Gdiplus::SolidBrush(argb);

		gp->FillRectangle(brush, 0, 0, width, height);

		SAFE_DELETE(gp);
		SAFE_DELETE(brush);
		
		return image;
	}

	HRESULT CImage::Load(const std::wstring& path)
	{
		mBitmap = Gdiplus::Bitmap::FromFile((WCHAR*)path.c_str());

		if (!mBitmap)
			return E_FAIL;

		mWidth = mBitmap->GetWidth();
		mHeight = mBitmap->GetHeight();

		mCachedBitmap = new Gdiplus::CachedBitmap(mBitmap, CApplication::GetBackGP());

		return S_OK;
	}

}