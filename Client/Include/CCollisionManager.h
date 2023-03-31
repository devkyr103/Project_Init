#pragma once
#include "CommonInclude.h"
#include "Enums.h"
#include "CCollider.h"

namespace kyr
{
	union ColliderID
	{
		struct
		{
			UINT32 left;
			UINT32 right;
		};
		UINT64 id;
	};
	
	class CScene;
	class CCollisionManager
	{
	public:
		static void Update();
		static void LayerCollision(CScene* scene, eLayerType left, eLayerType right);
		static void ColliderCollision(CCollider* leftCol, CCollider* rightCol, eLayerType left, eLayerType right);
		static bool Intersect(CCollider* left, CCollider* right);

		static void SetLayer(eLayerType left, eLayerType right, bool value);
		static void Clear();

	private:
		static WORD mMatrix[(UINT)eLayerType::End];
		static std::map<UINT64, bool> mCollisionMap;
	};

}

