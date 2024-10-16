#pragma once
#include "ResourceBase.h"

class Texture : public ResourceBase
{
public:
	Texture();
	virtual ~Texture();

public:
	Texture* LoadBmp(HWND hwnd, const wstring& path);	// �̹��� ���� �ε� �Լ�
	HDC GetDC();

	void SetTransparent(uint32 transparent) { _transparent = transparent; }
	uint32 GetTransparent() { return _transparent; }

private:
	HDC _hdc = {};
	HBITMAP _bitmap = {};	// ��Ʈ��
	Vec2Int _size = {};	// texture ũ��
	uint32 _transparent = RGB(255, 0, 255);	
	// ����ó�� �� ��(������ Sprite�� RGB�� ����ؼ� A���� �־���� ��, ����� ���İ� �־ RGBA�� transparent ������� �ʾƵ� ��.)
};

