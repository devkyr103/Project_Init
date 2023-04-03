#pragma once
#include "CComponent.h"

namespace kyr
{
	class CRigidbody :
		public CComponent
	{
	public:
		CRigidbody();
		~CRigidbody();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(Gdiplus::Graphics* gp);
		virtual void Release();

		void SetMass(float mass) { mMass = mass; }
		void AddForce(Vector2 force);
		void SetGround(bool ground) { mbGround = ground; }
		void SetGravity(Vector2 gravity) { mGravity = gravity; }
		
		Vector2 GetVelocity() { return mVelocity; }


	private:
		float mMass{};
		float mFriction = 100.f;
		float mGravityAccel{};

		Vector2 mForce{};
		Vector2 mAcceleration{};
		Vector2 mVelocity{};
		Vector2 mLimit{};
		Vector2 mGravity{};

		bool mbGround{};

		
	};


}
