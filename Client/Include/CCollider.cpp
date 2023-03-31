#include "CCollider.h"
#include "CTransform.h"
#include "CGameObject.h"
#include "CPaintTool.h"
#include "CCamera.h"

namespace kyr
{
	UINT CCollider::ColliderNumber = 0;

	CCollider::CCollider()
		: Component(eComponentType::Collider)
		, mID(ColliderNumber++)
	{
	}

	CCollider::~CCollider()
	{
	}

	void CCollider::Initialize()
	{
		CTransform* tr = GetOwner()->GetComponent<CTransform>();
		mPos = tr->GetPos();
	}

	void CCollider::Update()
	{
		CTransform* tr = GetOwner()->GetComponent<CTransform>();
		mPos = tr->GetPos();
	}

	void CCollider::Render(Gdiplus::Graphics* gp)
	{
		Vector2 pos = mPos;
		pos = CCamera::CalcPos(pos);

		Gdiplus::Pen* pen{};

		if (mCollisionCount == 0)
			pen = CPaintTool::mPen[(int)eColorType::Green];
		else
			pen = CPaintTool::mPen[(int)eColorType::Red];

		gp->DrawRectangle(pen, pos.x, pos.y, mSize.x, mSize.y);

	}

	void CCollider::Release()
	{
	}

	void CCollider::OnCollisionEnter(CCollider* other)
	{
		mCollisionCount = 1;
		GetOwner()->OnCollisionEnter(other);
	}

	void CCollider::OnCollisionStay(CCollider* other)
	{
		GetOwner()->OnCollisionStay(other);
	}

	void CCollider::OnCollisionExit(CCollider* other)
	{
		mCollisionCount = 0;
		GetOwner()->OnCollisionExit(other);
	}

}