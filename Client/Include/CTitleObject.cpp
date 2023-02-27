#include "CTitleObject.h"
#include "CTime.h"
#include "CSceneManager.h"
#include "CInput.h"
#include "CResources.h"
#include "CTransform.h"

namespace kyr
{
	CTitleObject::CTitleObject()
		: mImage{}
	{
	}

	CTitleObject::~CTitleObject()
	{
	}

	void CTitleObject::Initialize()
	{
		mImage = CResources::Load<CImage>(L"TitleObject", L"..\\Resources\\spr_abe_1.png");

		CGameObject::Initialize();
	}

	void CTitleObject::Update()
	{
		CGameObject::Update();

		CTransform* tr = GetComponent<CTransform>();
		Vector2 pos = tr->GetPos();

		if (CInput::GetKeyState(eKeyCode::A) == eKeyState::Pressed)
		{
			pos.x -= 100.0f * CTime::GetDeltaTime();
		}

		if (CInput::GetKeyState(eKeyCode::D) == eKeyState::Pressed)
		{
			pos.x += 100.0f * CTime::GetDeltaTime();
		}

		if (CInput::GetKeyState(eKeyCode::W) == eKeyState::Pressed)
		{
			pos.y -= 100.0f * CTime::GetDeltaTime();
		}

		if (CInput::GetKeyState(eKeyCode::S) == eKeyState::Pressed)
		{
			pos.y += 100.0f * CTime::GetDeltaTime();
		}
		tr->SetPos(pos);
	}

	void CTitleObject::Render(Gdiplus::Graphics* gp)
	{
		CGameObject::Render(gp);
		CTransform* tr = GetComponent<CTransform>();
		Vector2 pos = tr->GetPos();
		gp->DrawImage(mImage->GetImage(), (int)pos.x, (int)pos.y, 0, 0, (int)mImage->GetWidth(), (int)mImage->GetHeight(), Gdiplus::UnitPixel);
	}

	void CTitleObject::Release()
	{
		CGameObject::Release();
	}

}