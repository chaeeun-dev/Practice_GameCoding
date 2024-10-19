#pragma once

// ���� ����
class ResourceBase;
class Texture;
class Sprite;
class Flipbook;

class ResourceManager
{
public:
	DECLARE_SINGLE(ResourceManager);
	
	~ResourceManager();

public:
	void Init(HWND hwnd, std::filesystem::path resourcePath);
	void Clear();

	const std::filesystem::path& GetResourcePath() { return _resourcePath; }

	// Texture
	Texture* GetTexture(const wstring& key) { return _textures[key]; }
	Texture* LoadTexture(const wstring& key, const wstring& path, uint32 transparent = RGB(255, 0, 255));	// ���������� �̹����� �ҷ���

	// Sprite
	Sprite* GetSprite(const wstring& key) { return _sprites[key]; }
	Sprite* CreateSprite(const wstring& key, Texture* texture, int32 x = 0, int32 y = 0, int32 cx = 0, int32 cy = 0);
	// Load�� Texure�� ������ ����ϱ� ������ Load�� �ƴ� Create

	// Flipbook
	Flipbook* GetFlipbook(const wstring& key) { return _flipbooks[key]; }
	Flipbook* CreateFlipbook(const wstring& key);

private:
	HWND _hwnd;		// ��ȭ�� ��ȣ
	std::filesystem::path _resourcePath;	// ���ҽ� ���

	// resource
	unordered_map<wstring, Texture*> _textures;
	unordered_map<wstring, Sprite*> _sprites;
	unordered_map<wstring, Flipbook*> _flipbooks;
};

