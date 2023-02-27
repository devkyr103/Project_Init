#pragma once
#include "CEntity.h"

namespace kyr
{
	class CResource
	{
	public:
		CResource();
		virtual ~CResource();

		virtual HRESULT Load(const std::wstring& path) = 0;

		const std::wstring& GetKey() { return mkey; }
		const std::wstring& GetPath() { return mPath; }
		void SetKey(const std::wstring& key) { mkey = key; }
		void SetPath(const std::wstring& path) { mPath = path; }
		
	private:
		std::wstring mkey;
		std::wstring mPath;
	};
}


