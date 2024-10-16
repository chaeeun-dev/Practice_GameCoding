#include "pch.h"
#include "ResourceManager.h"

ResourceManager::~ResourceManager()
{
	Clear();
}

void ResourceManager::Init(HWND hwnd, std::filesystem::path resourcePath)
{
	_hwnd = hwnd;
	_resourcePath = resourcePath;

	// 경로에 관련된 함수들... 이 함수 활용해서 상대 경로로 만들기!
	//std::filesystem::current_path();	// 현재 경로
	//_resourcePath.relative_path();		// 상대 경로
	//std::filesystem::absolute(_resourcePath);		// 절대 경로
}

void ResourceManager::Clear()
{
}
