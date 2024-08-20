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
};

