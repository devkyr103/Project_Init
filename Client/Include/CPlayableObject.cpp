#include "CPlayableObject.h"
#include "CTime.h"
#include "CSceneManager.h"
#include "CInput.h"
#include "CResources.h"
#include "CTransform.h"
#include "CAnimator.h"
#include "CCollider.h"

namespace kyr
{
	CPlayableObject::CPlayableObject()
	{
	}

	CPlayableObject::~CPlayableObject()
	{
	}

	void CPlayableObject::Initialize()
	{
		////mImage = CResources::Load<CImage>(L"PlayableObject", L"..\\Resources\\spr_car_1.png");
		//CTransform* tr = GetComponent<CTransform>();
		////tr->SetScale(Vector2(2.f, 2.f));
		//tr->SetPivot(Vector2(0.5f, 0.5f));
		//tr->SetPos(Vector2(500.f, 500.f));

		CImage* image = CResources::Load<CImage>(L"test", L"..\\Resources\\spr_car_1.png");

		mAnimator = AddComponent<CAnimator>();
		mAnimator->CreateAnimation(L"idle", image, Vector2::Zero, 1, 1, 1, Vector2::Zero, 0.1f);

		mAnimator->play(L"idle", false);

		CCollider* col = AddComponent<CCollider>();
		col->SetSize(Vector2(100.f, 100.f));

		CGameObject::Initialize();
	}

	void CPlayableObject::Update()
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

	void CPlayableObject::Render(Gdiplus::Graphics* gp)
	{
		CGameObject::Render(gp);
		//CTransform* tr = GetComponent<CTransform>();
		//Vector2 pos = tr->GetPos();
		//gp->DrawImage(mImage->GetBitmap(), (int)pos.x, (int)pos.y, 0, 0, (int)mImage->GetWidth(), (int)mImage->GetHeight(), Gdiplus::UnitPixel);
	}

	void CPlayableObject::Release()
	{
		CGameObject::Release();
	}

}