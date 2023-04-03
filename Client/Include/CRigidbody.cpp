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

		// �ӵ��� ���ӵ��� �����ش�.
		mVelocity += mAcceleration * CTime::GetDeltaTime();

		if (mbGround)
		{
			// ������ ������
			Vector2 gravity = mGravity;
			gravity.Normalize();

			float dot = math::Dot(mVelocity, gravity);
			mVelocity -= gravity * dot;
		}
		else
		{
			mVelocity += mGravity * CTime::GetDeltaTime();
		}

		// �߷°��ӵ� �ִ� �ӵ� ����
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

		// ������ ���� ( ����� ���� ����, �ӵ��� 0�� �ƴ�)
		if (!(mVelocity == Vector2::Zero))
		{
			//�ӵ��� �ݴ�������� �������� ����ȴ�.
			Vector2 friction = -mVelocity;
			friction = friction.Normalize() * mFriction * mMass * CTime::GetDeltaTime();

			//���������� ���� �ӵ� ���Ҵ� ���� �ӵ����� ū ���

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

		// �ӵ��� �°Բ� ��ü�� �̵���Ų��.
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