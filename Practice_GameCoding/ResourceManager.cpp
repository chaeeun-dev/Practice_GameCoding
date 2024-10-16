#include "pch.h"
#include "ResourceManager.h"
#include "Texture.h"

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
	// 지울 땐 스마트 포인터 사용
	for (auto& item : _textures)
		SAFE_DELETE(item.second);

	_textures.clear();
}

Texture* ResourceManager::LoadTexture(const wstring& key, const wstring& path, uint32 transparent)
{
	if (_textures.find(key) != _textures.end())
		return _textures[key];

	fs::path fullPath = _resourcePath / path;

	Texture* texture = new Texture();
	texture->LoadBmp(_hwnd, fullPath.c_str());
	texture->SetTransparent(transparent);
	_textures[key] = texture;

	return texture;
}
