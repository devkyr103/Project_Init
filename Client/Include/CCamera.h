#pragma once
#include "Engine.h"

namespace kyr
{
	class CImage;
	class CGameObject;
	class CCamera
	{
	public:
		enum class eCameraEffectType
		{
			None,
			FadeIn,
			FadeOut,
			End,
		};

		enum class eClipPathType
		{
			Full,
			Ellipse,
			End,
		};
	
	public:
		CCamera();
		~CCamera();

	public:
		static void Initialize();
		static void Update();
		static void Render(Gdiplus::Graphics* gp);
		static void Clear();

		
		static Vector2 CalcPos(Vector2 pos) { return pos - mDistance; }
		// Calculate Camera World Position
		static Vector2 CalcCameraPos(Vector2 pos);
		// Calculate Camera Focus Pos in Client Resolution.
		static Vector2 CalcFocusPos(Vector2 pos);

		static Gdiplus::GraphicsPath* GetPath() { return mPath; }

		static void SetTarget(CGameObject* target) { mTarget = target; }
		static void SetShake(bool b) { mShake = b; }
		static void SetPath(Vector2 pos);
		static void SetPathType(eClipPathType type) { mPathType = type; }

	private:
		static Vector2 mResolution;
		static Vector2 mTargetPosition;
		//static Vector2 mFocusPosition;
		static Vector2 mDistance;
		static CGameObject* mTarget;

		static eCameraEffectType mType;
		static CImage* mImage;
		static float mAlpha;
		static float mAlphaTime;
		static float mEndTime;
		static bool mShake;

		static Gdiplus::GraphicsPath* mPath;
		static eClipPathType mPathType;
	};

}

