#pragma once
#include "CEntity.h"

namespace kyr
{
	class Component
		: public CEntity
	{
	public:
		Component(eComponentType type);
		~Component();
		
		virtual void Initialize();
		virtual void Update();
		virtual void Render(Gdiplus::Graphics* gp);
		virtual void Release();

		eComponentType GetType() { return mType; }

	private:
		const eComponentType mType;
	};
}


