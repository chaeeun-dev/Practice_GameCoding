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
	HWND _hwnd = {};	// ������ �ڵ� ��ȣ
	HDC _hdc = {};		// ��ȭ�� ��ȣ
};

