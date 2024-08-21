#include "pch.h"
#include "InputManager.h"

void InputManager::Init(HWND hwnd)
{
	_hwnd = hwnd;	// 나중에 필요하면 이중체크
	_states.resize(KEY_TYPE_COUNT, KeyState::None);		// state의 수는 4개
}

void InputManager::Update()
{
	BYTE asciikeys[KEY_TYPE_COUNT] = {};	// 256개 만큼 받아줄 공간 
	if (::GetKeyboardState(asciikeys) == false)		// 모든 키보드의 상태를 한 번에 가져옴
		return;

	// 키보드 상태 설정
	for (uint32 key = 0; key < KEY_TYPE_COUNT; key++)
	{
		// 키 눌려 있으면 true
		if (asciikeys[key] & 0x80)
		{
			KeyState& state = _states[key];

			// 이전 프레임에 키를 누른 상태라면 Press
			if (state == KeyState::Press || state == KeyState::Down)
				state = KeyState::Press;
			else
				state = KeyState::Down;
		}
		else
		{
			KeyState& state = _states[key];

			// 이전 프레임에 키를 누른 상태라면 Up
			if (state == KeyState::Press || state == KeyState::Down)
				state = KeyState::Up;
			else
				state = KeyState::None;
		}
	}

	// 마우스
	::GetCursorPos(&_mousePos);		// 마우스 커서 좌표 알아옴
	::ScreenToClient(_hwnd, &_mousePos);
}
