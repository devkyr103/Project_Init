#include "CTitleObject.h"
#include "CTime.h"
#include "CSceneManager.h"
#include "CInput.h"
#include "CResources.h"
#include "CTransform.h"
#include "CAnimator.h"
#include "CCollider.h"

namespace kyr
{
	CTitleObject::CTitleObject()
	{
	}

	CTitleObject::~CTitleObject()
	{
	}

	void CTitleObject::Initialize()
	{
		//CTransform* tr = GetComponent<CTransform>();
		//tr->SetScale(Vector2(5.f, 5.f));

		mAnimator = AddComponent<CAnimator>();

		mAnimator->CreateAnimations(L"..\\Resources\\girl", Vector2::Zero, 0.08f);

		mAnimator->play(L"Resourcesgirl", true);
		
		CCollider* col = AddComponent<CCollider>();
		col->SetSize(Vector2(100.f, 100.f));

		CGameObject::Initialize();
	}

	void CTitleObject::Update()
	{
		CGameObject::Update();

		CTransform* tr = GetComponent<CTransform>();
		Vector2 pos = tr->GetPos();

		//if (CInput::GetKeyState(eKeyCode::A) == eKeyState::Pressed)
		//{
		//	pos.x -= 100.0f * CTime::GetDeltaTime();
		//}
		//
		//if (CInput::GetKeyState(eKeyCode::D) == eKeyState::Pressed)
		//{
		//	pos.x += 100.0f * CTime::GetDeltaTime();
		//}
		//
		//if (CInput::GetKeyState(eKeyCode::W) == eKeyState::Pressed)
		//{
		//	pos.y -= 100.0f * CTime::GetDeltaTime();
		//}
		//
		//if (CInput::GetKeyState(eKeyCode::S) == eKeyState::Pressed)
		//{
		//	pos.y += 100.0f * CTime::GetDeltaTime();
		//}
		tr->SetPos(pos);
	}

	void CTitleObject::Render(Gdiplus::Graphics* gp)
	{
		CGameObject::Render(gp);
		//CTransform* tr = GetComponent<CTransform>();
		//Vector2 pos = tr->GetPos();
		//gp->DrawImage(mBitmap->GetBitmap(), (int)pos.x, (int)pos.y, 0, 0, (int)mBitmap->GetWidth(), (int)mBitmap->GetHeight(), Gdiplus::UnitPixel);
	}

	void CTitleObject::Release()
	{
		CGameObject::Release();
	}

}