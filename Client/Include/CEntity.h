#pragma once
#include "Engine.h"

namespace kyr
{
	class CEntity
	{
	public:
		CEntity();
		virtual ~CEntity();

		void SetName(const std::wstring& name) { mName = name; }
		std::wstring& GetName() { return mName; }
	private:
		std::wstring mName;
	};
}


