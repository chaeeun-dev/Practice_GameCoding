#pragma once

class Game
{
public:
	Game();
	~Game();

public:
	void Init(HWND hwnd);
	void Update();
	void Render();

private:
	HWND _hwnd = {};	// 윈도우 핸들 번호
	HDC _hdc = {};		// 도화지 번호

private:
	// 더블 버퍼링
	RECT _rect;		// 현재 그리고 있는 영역
	HDC _hdcBack = {};
	HBITMAP _bmpBack = {};
};

