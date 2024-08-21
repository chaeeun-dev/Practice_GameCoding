#pragma once

enum class KeyState
{ 
	None,
	Press,
	Down,
	Up,

	End
};

enum class KeyType
{
	LeftMouse = VK_LBUTTON,
	RightMouse = VK_RBUTTON,

	UP = VK_UP,
	DOWN = VK_DOWN,
	LEFT = VK_LEFT,
	RIGHT = VK_RIGHT,
	Spacebar = VK_SPACE,

	W = 'W',
	A = 'A',
	S = 'S',
	D = 'D'
};

enum
{
	KEY_TYPE_COUNT = static_cast<int32>(UINT8_MAX) + 1,
	KEY_STATE_COUNT = static_cast<int32>(KeyState::End),	// KeyType 개수는 4개
};

class InputManager
{
	DECLARE_SINGLE(InputManager);

public:
	void Init(HWND hwnd);	// 현재 커서가 게임을 가리키는지 확인
	void Update();			// 현재 키보드 상태

private:
	KeyState GetState(KeyType key) { return _states[static_cast<uint8>(key)]; }

private:
	HWND hwnd;
	vector <KeyState> _states;	// 키보드 상태를 Update 함수로 직접 관리
	POINT _mousePos;	// 마우스 위치
};

