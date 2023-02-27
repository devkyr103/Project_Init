#include "CScene.h"

namespace kyr
{
	CScene::CScene()
	{
		mLayers.reserve(5);
		mLayers.resize((UINT)eLayerType::End);
	}

	CScene::~CScene()
	{
	}

	void CScene::Initialize()
	{
		for (CLayer& layer : mLayers)
		{
			layer.Initialize();
		}
	}

	void CScene::Update()
	{
		for (CLayer& layer : mLayers)
		{
			layer.Update();
		}
	}

	void CScene::Render(Gdiplus::Graphics* gp)
	{
		for (CLayer& layer : mLayers)
		{
			layer.Render(gp);
		}
	}

	void CScene::Release()
	{
	}

	void CScene::OnEnter()
	{
	}

	void CScene::OnExit()
	{
	}

	void CScene::AddGameObject(CGameObject* obj, eLayerType layer)
	{
		mLayers[(UINT)layer].AddGameObject(obj);
	}

}