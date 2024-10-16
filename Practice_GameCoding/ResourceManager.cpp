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

	// ��ο� ���õ� �Լ���... �� �Լ� Ȱ���ؼ� ��� ��η� �����!
	//std::filesystem::current_path();	// ���� ���
	//_resourcePath.relative_path();		// ��� ���
	//std::filesystem::absolute(_resourcePath);		// ���� ���
}

void ResourceManager::Clear()
{
	// ���� �� ����Ʈ ������ ���
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
