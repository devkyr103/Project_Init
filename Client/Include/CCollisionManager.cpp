#include "CCollisionManager.h"
#include "CScene.h"
#include "CSceneManager.h"

namespace kyr
{
	WORD CCollisionManager::mMatrix[(UINT)eLayerType::End] = {};
	std::map<UINT64, bool> CCollisionManager::mCollisionMap;

	void CCollisionManager::Update()
	{
		CScene* scene = CSceneManager::GetActiveScene();

		for (UINT row = 0; row < (UINT)eLayerType::End; row++)
		{
			for (UINT col = 0; col < (UINT)eLayerType::End; col++)
			{
				if (mMatrix[row] & (1 << col))
				{
					LayerCollision(scene, (eLayerType)row, (eLayerType)col);
				}
			}
		}
	}

	void CCollisionManager::LayerCollision(CScene* scene, eLayerType left, eLayerType right)
	{
		std::vector<CGameObject*>& lefts = scene->GetGameObjects(left);
		std::vector<CGameObject*>& rights = scene->GetGameObjects(right);

		for (auto leftObject : lefts)
		{
			CCollider* leftCollider = leftObject->GetComponent<CCollider>();
			if (leftCollider == nullptr)
				continue;

			for (auto rightObject : rights)
			{
				CCollider* rightCollider = rightObject->GetComponent<CCollider>();
				if (rightCollider == nullptr)
					continue;

				if (leftObject == rightObject)
					continue;

				ColliderCollision(leftCollider, rightCollider, left, right);
			}
		}
	}

	void CCollisionManager::ColliderCollision(CCollider* leftCol, CCollider* rightCol, eLayerType left, eLayerType right)
	{
		ColliderID colliderID = {};
		colliderID.left = (UINT)leftCol->GetID();
		colliderID.right = (UINT)rightCol->GetID();

		//static std::map<UINT64, bool> mCollisionMap;
		std::map<UINT64, bool>::iterator iter
			= mCollisionMap.find(colliderID.id);

		if (iter == mCollisionMap.end())
		{
			mCollisionMap.insert(std::make_pair(colliderID.id, false));
			iter = mCollisionMap.find(colliderID.id);
		}

		if (Intersect(leftCol, rightCol))
		{
			// ���� �浹 ���������� enter
			if (iter->second == false)
			{
				leftCol->OnCollisionEnter(rightCol);
				rightCol->OnCollisionEnter(leftCol);

				iter->second = true;
			}
			else // �浹 ���λ��� stay
			{
				leftCol->OnCollisionStay(rightCol);
				rightCol->OnCollisionStay(leftCol);
			}
		}
		else
		{
			// Exit
			// ���������� �浹 O
			// ����� �浹 X 
			if (iter->second == true)
			{
				leftCol->OnCollisionExit(rightCol);
				rightCol->OnCollisionExit(leftCol);

				iter->second = false;
			}
		}
	}

	bool CCollisionManager::Intersect(CCollider* left, CCollider* right)
	{
		Vector2 leftPos = left->GetPos();
		Vector2 rightPos = right->GetPos();

		// �� �浹ü ���� �Ÿ���, �������� ���ݳ����� ���� ���ؼ�
		// �Ÿ��� �� ��ٸ� �浹 X, �Ÿ��� �� ª�ٸ� �浹 O
		Vector2 leftSize = left->GetSize();
		Vector2 rightSize = right->GetSize();

		leftPos.x = leftPos.x + leftSize.x / 2.0f;
		leftPos.y = leftPos.y + leftSize.y / 2.0f;

		rightPos.x = rightPos.x + rightSize.x / 2.0f;
		rightPos.y = rightPos.y + rightSize.y / 2.0f;

		if (fabs(leftPos.x - rightPos.x) < (leftSize.x / 2.0f) + (rightSize.x / 2.0f)
			&& fabs(leftPos.y - rightPos.y) < (leftSize.y / 2.0f) + (rightSize.y / 2.0f))
		{
			return true;
		}

		return false;
	}

	void CCollisionManager::SetLayer(eLayerType left, eLayerType right, bool value)
	{
		UINT row = 0;
		UINT col = 0;

		UINT ileft = (UINT)left;
		UINT iright = (UINT)right;

		if (left <= right)
		{
			row = ileft;
			col = iright;
		}
		else
		{
			row = iright;
			col = ileft;
		}

		if (value == true)
			mMatrix[row] |= (1 << col);
		else
			mMatrix[row] &= ~(1 << col);
	}

	void CCollisionManager::Clear()
	{
		memset(mMatrix, 0, sizeof(WORD) * (UINT)eLayerType::End);
		mCollisionMap.clear();
	}

}