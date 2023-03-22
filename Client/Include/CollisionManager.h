#pragma once
#include "CommonInclude.h"
#include "Enums.h"
#include "Collider.h"

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
	class CollisionManager
	{
	public:
		static void Update();
		static void LayerCollision(CScene* scene, eLayerType left, eLayerType right);
		static void ColliderCollision(Collider* leftCol, Collider* rightCol, eLayerType left, eLayerType right);
		static bool Intersect(Collider* left, Collider* right);

		static void SetLayer(eLayerType left, eLayerType right, bool value);
		static void Clear();

	private:
		static WORD mMatrix[(UINT)eLayerType::End];
		static std::map<UINT64, bool> mCollisionMap;
	};

}

