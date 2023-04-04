#include "CGreedScene.h"
#include "CBackGroundObj.h"
#include "CPaintingObj.h"
#include "Object.h"
#include "CResourceManager.h"
#include "CInput.h"
#include "CCollisionManager.h"
#include "CTitleObject.h"

namespace kyr
{
	CGreedScene::CGreedScene()
	{
	}

	CGreedScene::~CGreedScene()
	{
	}

	void CGreedScene::Initialize()
	{
		CScene::Initialize();

		CImage* image = CResourceManager::Load<CImage>(L"GreedBack", L"..\\Resources\\BackGround\\BlankWall_003.png");
		CBackGroundObj* back = Instantiate<CBackGroundObj>(Vector2::Zero, image, eLayerType::BG);

		back->GetComponent<CBackImage>()->SetCache(true);

		image = CResourceManager::Load<CImage>(L"GreedPainting", L"..\\Resources\\Painting\\GreedPainting.png");

		CPaintingObj* painting = Instantiate<CPaintingObj>(Vector2(800.f, 450.f), image, eLayerType::BackObj);

		painting->GetComponent<CTransform>()->SetPivot(Vector2(0.5f, 0.5f));
		painting->GetComponent<CBackImage>()->SetCache(false);
		painting->GetComponent<CBackImage>()->SetSize(Vector2(800.f, 450.f));

		Instantiate<CTitleObject>(Vector2(1300, 600), eLayerType::Monster);
	}

	void CGreedScene::Update()
	{
		if (CInput::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			CSceneManager::LoadScene(eSceneType::Pride);
		}

		CScene::Update();
	}

	void CGreedScene::Render(Gdiplus::Graphics* gp)
	{
		CScene::Render(gp);

	}

	void CGreedScene::Release()
	{
		CScene::Release();

	}

	void CGreedScene::OnEnter()
	{
		CCollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);

	}

	void CGreedScene::OnExit()
	{
	}

}