#include "CCamera.h"
#include "CGameObject.h"
#include "CImage.h"
#include "CApplication.h"
#include "CInput.h"
#include "CTime.h"
#include "CTransform.h"
#include "CSceneManager.h"

namespace kyr
{
	Vector2 CCamera::mResolution{};
	Vector2 CCamera::mTargetPosition{};
	//Vector2 CCamera::mFocusPosition{};
	Vector2 CCamera::mDistance{};
	CGameObject* CCamera::mTarget{};

	CCamera::eCameraEffectType CCamera::mType = CCamera::eCameraEffectType::None;
	CImage* CCamera::mImage{};
	float CCamera::mAlpha = 1.f;
	float CCamera::mAlphaTime = 0.f;
	float CCamera::mEndTime = 10.f;
	bool CCamera::mShake = false;

	// Clip
	Gdiplus::GraphicsPath* CCamera::mPath{};
	CCamera::eClipPathType CCamera::mPathType{};

	CCamera::CCamera()
	{
	}

	CCamera::~CCamera()
	{
		SAFE_DELETE(mPath);
	}

	void CCamera::Initialize()
	{
		srand((unsigned int)(time(NULL)));

		mResolution.x = (float)CApplication::GetClientWidth();
		mResolution.y = (float)CApplication::GetClientHeight();
		mTargetPosition = mResolution * 0.5f;

		mPath = new Gdiplus::GraphicsPath();

		SetPathType(eClipPathType::Ellipse);
		SetPath(mTargetPosition);
	}

	void CCamera::Update()
	{
		if (mTarget)
		{
			mTargetPosition = mTarget->GetComponent<CTransform>()->GetPos();
		}
		else
		{
			if (CInput::GetKey(eKeyCode::UP))
				mTargetPosition.y -= 100.f * CTime::GetDeltaTime();

			if (CInput::GetKey(eKeyCode::DOWN))
				mTargetPosition.y += 100.f * CTime::GetDeltaTime();

			if (CInput::GetKey(eKeyCode::LEFT))
				mTargetPosition.x -= 100.f * CTime::GetDeltaTime();

			if (CInput::GetKey(eKeyCode::RIGHT))
				mTargetPosition.x += 100.f * CTime::GetDeltaTime();
		}

		// Update CameraPos
		SetPath(CalcFocusPos(mTargetPosition));
		
		/*if (mAlphaTime < mEndTime)
		{
			mAlphaTime += CTime::GetDeltaTime();

			float ratio = (mAlpha / mEndTime);

			if (mType == eCameraEffectType::FadeIn)
			{
				mAlpha = 1.f - ratio;
			}
			else if (mType == eCameraEffectType::FadeOut)
			{
				mAlpha = ratio;
			}
			else
			{

			}

			mImage->SetAlpha(mAlpha);
		}*/

		Vector2 worldSize = CSceneManager::GetWorldSize();

		Vector2 halfSize = mResolution * 0.5f;

		if (mTargetPosition.x - halfSize.x >= 0 && mTargetPosition.x + halfSize.x <= worldSize.x)
		{
			mDistance.x = mTargetPosition.x - halfSize.x;
		}

		if(mTargetPosition.y - halfSize.y >= 0 && mTargetPosition.y + halfSize.y <= worldSize.y)
		{
			mDistance.y = mTargetPosition.y - halfSize.y;
		}

		if (mShake)
		{
			// +- 5
			mDistance.x += ((rand() % 11) - 5);
			mDistance.y += ((rand() % 11) - 5);
		}
		else
		{

		}
	}

	void CCamera::Render(Gdiplus::Graphics* gp)
	{
		Gdiplus::PathGradientBrush br(mPath);
		br.SetCenterColor(Gdiplus::Color(0, 255, 255, 255));

		Gdiplus::Color c(255, 0, 0, 0);
		int cnt = 1;

		br.SetSurroundColors(&c, &cnt);

		gp->FillPath(&br, mPath);
	}

	void CCamera::Clear()
	{
		mTargetPosition = (mResolution / 2.0f);
		mDistance = Vector2::Zero;
	}

	Vector2 CCamera::CalcCameraPos(Vector2 pos)
	{
		Vector2 size = mResolution * 0.5f;
		Vector2 worldSize = CSceneManager::GetWorldSize();
		Vector2 cameraPos = pos;

		if (pos.x - size.x < 0)
			cameraPos.x = size.x;
		else if(pos.x + size.x > worldSize.x)
			cameraPos.x = worldSize.x - size.x;

		if (pos.y - size.y < 0)
			cameraPos.y = size.y;
		else if (pos.y + size.y > worldSize.y)
			cameraPos.y = worldSize.y - size.y;

		return cameraPos;
	}

	Vector2 CCamera::CalcFocusPos(Vector2 pos)
	{
		Vector2 targetPos = pos;
		Vector2 cameraPos = CalcCameraPos(pos);

		return mResolution * 0.5f + (targetPos - cameraPos);
	}

	void CCamera::SetPath(Vector2 pos)
	{
		mPath->Reset();

		if (mPathType == CCamera::eClipPathType::Full)
		{
			Vector2 size = mResolution;

			Gdiplus::RectF rect{ 0, 0, size.x, size.y };

			mPath->AddRectangle(rect);
		}
		else if (mPathType == CCamera::eClipPathType::Ellipse)
		{
			Vector2 size(400, 400);

			Gdiplus::RectF rect{ pos.x - size.x * 0.5f , pos.y - size.y * 0.5f
								, size.x , size.y };

			mPath->AddEllipse(rect);
		}
		else
		{
		}
	}
	
}