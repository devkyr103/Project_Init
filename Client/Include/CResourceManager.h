#pragma once
#include "CResource.h"

namespace kyr
{
	class CResourceManager
	{
	public:
		template<typename T>
		static T* Find(const std::wstring& key)
		{
			std::map<std::wstring, CResource*>::iterator iter = mResources.find(key);

			if (iter != mResources.end())
			{
				return dynamic_cast<T*>(iter->second);
			}

			return nullptr;
		}

		template<typename T>
		static T* Load(const std::wstring& key, const std::wstring& path)
		{
			T* resource = CResourceManager::Find<T>(key);

			if (resource != nullptr)
			{
				return resource;
			}

			// 해당 리소스가 없다면
			resource = new T();
			if (FAILED(resource->Load(path)))
			{
				assert(false);
				return nullptr;
			}

			resource->SetKey(key);
			resource->SetPath(path);
			mResources.insert(std::make_pair(key, resource));

			return dynamic_cast<T*>(resource);
		}

		template <typename T>
		static void Insert(const std::wstring& key, T* resource)
		{
			mResources.insert(std::make_pair(key, resource));
		}

		static void Release()
		{
			for (std::pair<const std::wstring, CResource*> pair : mResources)
			{
				delete pair.second;
				pair.second = nullptr;
			}
		}


	private:
		static std::map<std::wstring, CResource*> mResources;
	};
}


