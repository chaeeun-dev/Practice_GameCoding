#include "pch.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "Sprite.h"

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

Sprite* ResourceManager::CreateSprite(const wstring& key, Texture* texture, int32 x, int32 y, int32 cx, int32 cy)
{
	// ���� Sprite�� ������ ��������
	if (_sprites.find(key) != _sprites.end())	// �� ã���� last ���� ��ȯ, �� _sprites.end()�� �ƴ϶�� ã�Ҵٴ� ��
		return _sprites[key];

	// ���� 0�̸� Default ������ ����
	if (cx == 0)
		cx = texture->GetSize().x;
	if (cy == 0)
		cy = texture->GetSize().y;

	Sprite* sprite = new Sprite(texture, x, y, cx, cy);
	_sprites[key] = sprite;

	return sprite;
}

