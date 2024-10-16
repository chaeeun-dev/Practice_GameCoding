#pragma once

// ���� ����
class ResourceBase;
class Texture;

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

private:
	HWND _hwnd;		// ��ȭ�� ��ȣ
	std::filesystem::path _resourcePath;	// ���ҽ� ���

	// resource
	unordered_map<wstring, Texture*> _textures;
};

