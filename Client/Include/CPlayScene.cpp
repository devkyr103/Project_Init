#include "CPlayScene.h"
#include "CPlayableObject.h"
#include "CTitleObject.h"
#include "CInput.h"
#include "CSceneManager.h"
#include "CollisionManager.h"

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

		CTitleObject* obj = new CTitleObject();
		AddGameObject(obj, eLayerType::Monster);

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
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
	}

	void CPlayeScene::OnExit()
	{
		
	}
}
