#pragma once

// 전방 선언
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
	Texture* LoadTexture(const wstring& key, const wstring& path, uint32 transparent = RGB(255, 0, 255));	// 실질적으로 이미지를 불러옴

private:
	HWND _hwnd;		// 도화지 번호
	std::filesystem::path _resourcePath;	// 리소스 경로

	// resource
	unordered_map<wstring, Texture*> _textures;
};

