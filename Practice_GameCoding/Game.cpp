#include "pch.h"
#include "Game.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "SceneManager.h"

Game::Game()
{
	// int* p = new int();	// memory leak 확인하기 위해
}

Game::~Game()
{
	GET_SINGLE(SceneManager)->Clear();

	// 메모리 릭 알려줌
	_CrtDumpMemoryLeaks();
}

void Game::Init(HWND hwnd)
{
	_hwnd = hwnd;
	_hdc = ::GetDC(hwnd);		// hwnd 값으로 hdc값 알아내는 함수

	// 더블 버퍼링
	::GetClientRect(hwnd, &_rect);		// 윈도우에서 범위 얻어오기
	_hdcBack = ::CreateCompatibleDC(_hdc);	// _hdc와 호환되는 DC 만들기
	_bmpBack = ::CreateCompatibleBitmap(_hdc, _rect.right, _rect.bottom);	// _hdc와 호환되는 비트맵 만들기
	HBITMAP prev = (HBITMAP)::SelectObject(_hdcBack, _bmpBack);		// DC와 BMP연결
	::DeleteObject(prev);		// 이전 것 날려주기

	GET_SINGLE(TimeManager)->Init();
	GET_SINGLE(InputManager)->Init(hwnd);
	GET_SINGLE(SceneManager)->Init();

	GET_SINGLE(SceneManager)->ChangeScene(SceneType::GameScene);		// 첫 Scene 설정
}

void Game::Update()
{
	GET_SINGLE(TimeManager)->Update();
	GET_SINGLE(InputManager)->Update();
	GET_SINGLE(SceneManager)->Update();
}

void Game::Render()
{
	uint32 fps = GET_SINGLE(TimeManager)->GetFps();
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	
	{
		POINT mousePos = GET_SINGLE(InputManager)->GetMousePos();
		wstring str = std::format(L"Mouse x_pos({0}), y_pos({1})", mousePos.x, mousePos.y);
		::TextOut(_hdcBack, 20, 10, str.c_str(), static_cast<int32>(str.size()));
	}
	
	{
		wstring str = std::format(L"FPS({0}), DT({1}) ms", fps, static_cast<int32>(deltaTime * 1000));
		::TextOut(_hdcBack, 650, 10, str.c_str(), static_cast<int32>(str.size()));
	}

	GET_SINGLE(SceneManager)->Render(_hdcBack);

	// 더블 버퍼링
	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY);	// 비트블릿 - 고속 복사
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);		// 다시 백버퍼 리셋
}

// 더블 버퍼링 - _hdcBack에 먼저 그림을 다 그린 후, _hdc로 그림을 복사해준다. 잔상과 깜빡거리는 현상이 사라진다! 