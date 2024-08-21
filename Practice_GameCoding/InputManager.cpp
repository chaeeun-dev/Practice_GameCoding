#include "pch.h"
#include "InputManager.h"

void InputManager::Init(HWND hwnd)
{
	_hwnd = hwnd;	// ���߿� �ʿ��ϸ� ����üũ
	_states.resize(KEY_TYPE_COUNT, KeyState::None);		// state�� ���� 4��
}

void InputManager::Update()
{
	BYTE asciikeys[KEY_TYPE_COUNT] = {};	// 256�� ��ŭ �޾��� ���� 
	if (::GetKeyboardState(asciikeys) == false)		// ��� Ű������ ���¸� �� ���� ������
		return;

	// Ű���� ���� ����
	for (uint32 key = 0; key < KEY_TYPE_COUNT; key++)
	{
		// Ű ���� ������ true
		if (asciikeys[key] & 0x80)
		{
			KeyState& state = _states[key];

			// ���� �����ӿ� Ű�� ���� ���¶�� Press
			if (state == KeyState::Press || state == KeyState::Down)
				state = KeyState::Press;
			else
				state = KeyState::Down;
		}
		else
		{
			KeyState& state = _states[key];

			// ���� �����ӿ� Ű�� ���� ���¶�� Up
			if (state == KeyState::Press || state == KeyState::Down)
				state = KeyState::Up;
			else
				state = KeyState::None;
		}
	}

	// ���콺
	::GetCursorPos(&_mousePos);		// ���콺 Ŀ�� ��ǥ �˾ƿ�
	::ScreenToClient(_hwnd, &_mousePos);
}
