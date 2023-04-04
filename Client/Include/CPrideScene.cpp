#include "CPrideScene.h"
#include "CBackGroundObj.h"
#include "CPaintingObj.h"
#include "Object.h"
#include "CResourceManager.h"
#include "CInput.h"
#include "CCollisionManager.h"

namespace kyr
{
	CPrideScene::CPrideScene()
	{
	}

	CPrideScene::~CPrideScene()
	{
	}

	void CPrideScene::Initialize()
	{
		CScene::Initialize();

		CImage* image = CResourceManager::Load<CImage>(L"PrideBack", L"..\\Resources\\BackGround\\BlankWall_001.png");
		CBackGroundObj* back = Instantiate<CBackGroundObj>(Vector2::Zero, image, eLayerType::BG);

		back->GetComponent<CBackImage>()->SetCache(true);

		image = CResourceManager::Load<CImage>(L"PridePainting", L"..\\Resources\\Painting\\PridePainting.png");

		CPaintingObj* painting = Instantiate<CPaintingObj>(Vector2(800.f, 450.f), image, eLayerType::BackObj);

		painting->GetComponent<CTransform>()->SetPivot(Vector2(0.5f, 0.5f));
		painting->GetComponent<CBackImage>()->SetCache(false);
		painting->GetComponent<CBackImage>()->SetSize(Vector2(800.f, 450.f));
	}

	void CPrideScene::Update()
	{
		if (CInput::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			CSceneManager::LoadScene(eSceneType::Anger);
		}

		CScene::Update();
	}

	void CPrideScene::Render(Gdiplus::Graphics* gp)
	{
		CScene::Render(gp);
	}

	void CPrideScene::Release()
	{
		CScene::Release();

	}

	void CPrideScene::OnEnter()
	{
		CCollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
	}

	void CPrideScene::OnExit()
	{
	}

}