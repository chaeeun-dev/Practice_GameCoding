#pragma once
#include "ResourceBase.h"

class Texture : public ResourceBase
{
public:
	Texture();
	virtual ~Texture();

public:
	Texture* LoadBmp(HWND hwnd, const wstring& path);
	HDC GetDC();

private:
	HDC _hdc = {};
	HBITMAP _bitmap = {};	// ��Ʈ��
	Vec2Int _size = {};	// texture ũ��
	uint32 _transparent = RGB(255, 0, 255);	
	// ����ó�� �� ��(������ Sprite�� RGB�� ����ؼ� A���� �־���� ��, ����� ���İ� �־ RGBA�� transparent ������� �ʾƵ� ��.)
};

