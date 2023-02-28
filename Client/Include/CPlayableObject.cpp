#include "CPlayableObject.h"
#include "CTime.h"
#include "CSceneManager.h"
#include "CInput.h"
#include "CResources.h"
#include "CTransform.h"
#include "CAnimator.h"

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
		CImage* mImage = CResources::Load<CImage>(L"PlayableObject", L"..\\Resources\\spr_car_1.png");
		CAnimator* animator = AddComponent<CAnimator>();

		CGameObject::Initialize();
	}

	void CPlayableObject::Update()
	{
		CGameObject::Update();

		CTransform* tr = GetComponent<CTransform>();
		Vector2 pos = tr->GetPos();

		CAnimator* animator = GetComponent<CAnimator>();

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

		// 키 입력 따른 애니메이션 출력 설정
		if (CInput::GetKeyState(eKeyCode::W) == eKeyState::Down)
		{
			//animator->Play(L"FowardRun", true);
		}
		if (CInput::GetKeyState(eKeyCode::W) == eKeyState::Up)
		{
			//animator->Play(L"Idle", true);
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
		//gp->DrawImage(mImage->GetImage(), (int)pos.x, (int)pos.y, 0, 0, (int)mImage->GetWidth(), (int)mImage->GetHeight(), Gdiplus::UnitPixel);
	}

	void CPlayableObject::Release()
	{
		CGameObject::Release();
	}

}