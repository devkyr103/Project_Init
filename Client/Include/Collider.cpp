#include "Collider.h"
#include "CTransform.h"
#include "CGameObject.h"
#include "CPaintTool.h"

namespace kyr
{
	UINT Collider::ColliderNumber = 0;

	Collider::Collider()
		: Component(eComponentType::Collider)
		, mID(ColliderNumber++)
	{
	}

	Collider::~Collider()
	{
	}

	void Collider::Initialize()
	{
		CTransform* tr = GetOwner()->GetComponent<CTransform>();
		mPos = tr->GetPos();
	}

	void Collider::Update()
	{
		CTransform* tr = GetOwner()->GetComponent<CTransform>();
		mPos = tr->GetPos();
	}

	void Collider::Render(Gdiplus::Graphics* gp)
	{
		Gdiplus::Pen* pen{};

		if (mCollisionCount == 0)
			pen = CPaintTool::mPen[(int)eColorType::Green];
		else
			pen = CPaintTool::mPen[(int)eColorType::Red];

		gp->DrawRectangle(pen, mPos.x, mPos.y, mSize.x, mSize.y);

	}

	void Collider::Release()
	{
	}

	void Collider::OnCollisionEnter(Collider* other)
	{
		mCollisionCount = 1;
		GetOwner()->OnCollisionEnter(other);
	}

	void Collider::OnCollisionStay(Collider* other)
	{
		GetOwner()->OnCollisionStay(other);
	}

	void Collider::OnCollisionExit(Collider* other)
	{
		mCollisionCount = 0;
		GetOwner()->OnCollisionExit(other);
	}

}