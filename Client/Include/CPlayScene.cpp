#include "CPlayScene.h"
#include "CPlayableObject.h"
#include "CInput.h"
#include "CSceneManager.h"

namespace kyr
{
	CPlayeScene::CPlayeScene()
		: mPlayableObject{}
	{
	}

	CPlayeScene::~CPlayeScene()
	{
	}

	void CPlayeScene::Initialize()
	{

		mPlayableObject = new CPlayableObject();
		AddGameObject(mPlayableObject, eLayerType::Player);

		CScene::Initialize();
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
	}
	void CPlayeScene::OnExit()
	{
		//mCuphead->SetPos(Vector2{ 0.0f, 0.0f });
	}
}
