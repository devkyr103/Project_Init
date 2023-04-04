#include "CAngerScene.h"
#include "CBackGroundObj.h"
#include "CPaintingObj.h"
#include "Object.h"
#include "CResourceManager.h"
#include "CInput.h"
#include "CCollisionManager.h"

namespace kyr
{
	CAngerScene::CAngerScene()
	{
	}

	CAngerScene::~CAngerScene()
	{
	}

	void CAngerScene::Initialize()
	{
		CScene::Initialize();

		CImage* image = CResourceManager::Load<CImage>(L"AngerBack", L"..\\Resources\\BackGround\\BlankWall_002.png");
		CBackGroundObj* back = Instantiate<CBackGroundObj>(Vector2::Zero, image, eLayerType::BG);

		back->GetComponent<CBackImage>()->SetCache(true);

		image = CResourceManager::Load<CImage>(L"AngerPainting", L"..\\Resources\\Painting\\AngerPainting.png");

		CPaintingObj* painting = Instantiate<CPaintingObj>(Vector2(800.f, 450.f), image, eLayerType::BackObj);

		painting->GetComponent<CTransform>()->SetPivot(Vector2(0.5f, 0.5f));
		painting->GetComponent<CBackImage>()->SetCache(false);
		painting->GetComponent<CBackImage>()->SetSize(Vector2(800.f, 450.f));
	}

	void CAngerScene::Update()
	{
		if (CInput::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			CSceneManager::LoadScene(eSceneType::Greed);
		}

		CScene::Update();
	}

	void CAngerScene::Render(Gdiplus::Graphics* gp)
	{
		CScene::Render(gp);
	}

	void CAngerScene::Release()
	{
		CScene::Release();

	}

	void CAngerScene::OnEnter()
	{
		CCollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);

	}

	void CAngerScene::OnExit()
	{
	}

}