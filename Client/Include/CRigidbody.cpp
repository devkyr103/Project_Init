#include "CRigidbody.h"
#include "CTime.h"
#include "CGameObject.h"
#include "CTransform.h"

namespace kyr
{
	CRigidbody::CRigidbody()
		: CComponent(eComponentType::Rigidbody)
	{
	}

	CRigidbody::~CRigidbody()
	{
	}

	void CRigidbody::Initialize()
	{
	}

	void CRigidbody::Update()
	{
		// F = M * A
		// A = M / F
		mAcceleration = mForce / mMass;

		// 속도에 가속도를 더해준다.
		mVelocity += mAcceleration * CTime::GetDeltaTime();

		if (mbGround)
		{
			// 땅위에 있을때
			Vector2 gravity = mGravity;
			gravity.Normalize();

			float dot = math::Dot(mVelocity, gravity);
			mVelocity -= gravity * dot;
		}
		else
		{
			mVelocity += mGravity * CTime::GetDeltaTime();
		}

		// 중력가속도 최대 속도 제한
		Vector2 gravity = mGravity;
		gravity.Normalize();
		float dot = math::Dot(mVelocity, gravity);
		gravity = gravity * dot;

		Vector2 sideVelocity = mVelocity - gravity;
		if (mLimit.y < gravity.Length())
		{
			gravity.Normalize();
			gravity *= mLimit.y;
		}

		if (mLimit.x < sideVelocity.Length())
		{
			sideVelocity.Normalize();
			sideVelocity *= mLimit.x;
		}

		// 마찰력 조건 ( 적용된 힘이 없고, 속도가 0이 아님)
		if (!(mVelocity == Vector2::Zero))
		{
			//속도에 반대방향으로 마찰력이 적용된다.
			Vector2 friction = -mVelocity;
			friction = friction.Normalize() * mFriction * mMass * CTime::GetDeltaTime();

			//마찰력으로 인한 속도 감소는 현재 속도보다 큰 경우

			if (mVelocity.Length() < friction.Length())
			{
				mVelocity = Vector2::Zero;
			}
			else
			{
				mVelocity += friction;
			}
		}
		//

		// 속도에 맞게끔 물체를 이동시킨다.
		CTransform* tr = GetOwner()->GetComponent<CTransform>();
		Vector2 pos = tr->GetPos();
		pos = pos + mVelocity * CTime::GetDeltaTime();
		tr->SetPos(pos);
		mForce.Clear();
	}

	void CRigidbody::Render(Gdiplus::Graphics* gp)
	{
	}

	void CRigidbody::Release()
	{
	}

	void CRigidbody::AddForce(Vector2 force)
	{
	}

}