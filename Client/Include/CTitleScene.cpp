#include "CTitleScene.h"
#include "CInput.h"
#include "CSceneManager.h"
#include "CTitleObject.h"
#include "CSound.h"
#include "CResourceManager.h"

namespace kyr
{
	CTitleScene::CTitleScene()
	{
	}

	CTitleScene::~CTitleScene()
	{
	}

	void CTitleScene::Initialize()
	{
		CSound* bgm = CResourceManager::Load<CSound>(L"BGM", L"..\\Resources\\Sound\\BGM.wav");
		bgm->Play(true);

		CScene::Initialize();
	}

	void CTitleScene::Update()
	{
		if (CInput::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			CSceneManager::LoadScene(eSceneType::Pride);
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
