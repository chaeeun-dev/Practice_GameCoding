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

	// ��ο� ���õ� �Լ���... �� �Լ� Ȱ���ؼ� ��� ��η� �����!
	//std::filesystem::current_path();	// ���� ���
	//_resourcePath.relative_path();		// ��� ���
	//std::filesystem::absolute(_resourcePath);		// ���� ���
}

void ResourceManager::Clear()
{
}
