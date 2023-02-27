#include "CTitleScene.h"
#include "CInput.h"
#include "CSceneManager.h"
#include "CTitleObject.h"

namespace kyr
{
	CTitleScene::CTitleScene()
		: mTitleObject{}
	{
	}
	CTitleScene::~CTitleScene()
	{
	}
	void CTitleScene::Initialize()
	{
		mTitleObject = new CTitleObject();
		AddGameObject(mTitleObject, eLayerType::Player);

		CScene::Initialize();
	}
	void CTitleScene::Update()
	{
		if (CInput::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			CSceneManager::LoadScene(eSceneType::Play);
		}

		CScene::Update();
	}
	void CTitleScene::Render(Gdiplus::Graphics* gp)
	{
		CScene::Render(gp);
	}
	void CTitleScene::Release()
	{
		CScene::Release();
	}
	void CTitleScene::OnEnter()
	{
	}
	void CTitleScene::OnExit()
	{
	}
}
