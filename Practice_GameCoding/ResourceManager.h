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
	HWND _hwnd;		// ��ȭ�� ��ȣ
	std::filesystem::path _resourcePath;	// ���ҽ� ���
};

