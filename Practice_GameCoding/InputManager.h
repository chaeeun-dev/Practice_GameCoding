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
	KEY_STATE_COUNT = static_cast<int32>(KeyState::End),	// KeyType ������ 4��
};

class InputManager
{
	DECLARE_SINGLE(InputManager);

public:
	void Init(HWND hwnd);	// ���� Ŀ���� ������ ����Ű���� Ȯ��
	void Update();			// ���� Ű���� ����

private:
	KeyState GetState(KeyType key) { return _states[static_cast<uint8>(key)]; }

private:
	HWND hwnd;
	vector <KeyState> _states;	// Ű���� ���¸� Update �Լ��� ���� ����
	POINT _mousePos;	// ���콺 ��ġ
};

