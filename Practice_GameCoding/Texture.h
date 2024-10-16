#pragma once
#include "ResourceBase.h"

class Texture : public ResourceBase
{
public:
	Texture();
	virtual ~Texture();

public:
	Texture* LoadBmp(HWND hwnd, const wstring& path);	// 이미지 파일 로드 함수
	HDC GetDC();

	void SetSize(Vec2Int size) { _size = size; }
	Vec2Int GetSize() { return _size; }

	void SetTransparent(uint32 transparent) { _transparent = transparent; }
	uint32 GetTransparent() { return _transparent; }

private:
	HDC _hdc = {};
	HBITMAP _bitmap = {};	// 비트맵
	Vec2Int _size = {};	// texture 크기
	uint32 _transparent = RGB(255, 0, 255);	
	// 투명처리 할 색(옛날의 Sprite는 RGB만 사용해서 A값을 넣어줘야 함, 현재는 알파가 있어서 RGBA라 transparent 사용하지 않아도 됨.)
};

