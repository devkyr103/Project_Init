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

		template<typename T>
		void SetTypeID()
		{
			mTypeName = typeid(T).name();

			mTypeID = typeid(T).hash_code();
		}

		std::wstring& GetName() { return mName; }
		std::string& GetTypeName() { return mTypeName; }
		size_t& GetTypeID() { return mTypeID; }

		template<typename T>
		bool CheckTypeID() const
		{
			return mTypeID == typeid(T).hash_code();
		}

	private:
		std::wstring	mName{};
		std::string		mTypeName{};
		size_t			mTypeID{};
	};
}


