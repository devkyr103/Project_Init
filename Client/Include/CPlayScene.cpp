#include "CPlayScene.h"
#include "CPlayableObject.h"
#include "CTitleObject.h"
#include "CBackGroundObj.h"
#include "CInput.h"
#include "CSceneManager.h"
#include "CCollisionManager.h"
#include "Object.h"
#include "CCamera.h"

namespace kyr
{
	CPlayeScene::CPlayeScene()
	{
	}

	CPlayeScene::~CPlayeScene()
	{
	}

	void CPlayeScene::Initialize()
	{
		CScene::Initialize();

		Instantiate<CBackGroundObj>(Vector2::Zero, eLayerType::BG);

		CGameObject* obj = Instantiate<CPlayableObject>(Vector2::Zero, eLayerType::Player);
		Instantiate<CTitleObject>(Vector2(0, 0), eLayerType::Monster);
		
		SetWorldSize(Vector2(1600, 900));
		CCamera::SetTarget(obj);
	}

	void CPlayeScene::Update()
	{
		if (CInput::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			CSceneManager::LoadScene(eSceneType::Title);
		}

		CScene::Update();
	}

	void CPlayeScene::Render(Gdiplus::Graphics* gp)
	{
		//Super::Tick();
		CScene::Render(gp);
	}

	void CPlayeScene::Release()
	{
		CScene::Release();
	}

	void CPlayeScene::OnEnter()
	{
		CCollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
	}

	void CPlayeScene::OnExit()
	{
		
	}
}
