#pragma once

class ResourceManager
{
public:
	DECLARE_SINGLE(ResourceManager);
	
	~ResourceManager();

public:
	void Init(HWND hwnd, std::filesystem::path resourcePath);
	void Clear();

	const std::filesystem::path& GetResourcePath() { return _resourcePath; }

private:
	HWND _hwnd;		// 도화지 번호
	std::filesystem::path _resourcePath;	// 리소스 경로
};

