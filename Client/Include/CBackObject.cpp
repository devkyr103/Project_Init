#include "CBackObject.h"
#include "CTransform.h"
#include "CResources.h"

namespace kyr
{
	CBackObject::CBackObject()
	{
	}

	CBackObject::~CBackObject()
	{
	}

	void CBackObject::Initialize()
	{
		CImage* image = CResources::Load<CImage>(L"BackImage", L"..\\Resources\\blankWall\blankWall_1.png");

		CGameObject::Initialize();
	}

	void CBackObject::Update()
	{
	}

	void CBackObject::Render(Gdiplus::Graphics* gp)
	{
	}

	void CBackObject::Release()
	{
	}

}