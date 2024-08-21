#include "pch.h"
#include "Game.h"
#include "TimeManager.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init(HWND hwnd)
{
	_hwnd = hwnd;
	_hdc = ::GetDC(hwnd);		// hwnd ������ hdc�� �˾Ƴ��� �Լ�

	GET_SINGLE(TimeManager)->Init();
}

void Game::Update()
{
	GET_SINGLE(TimeManager)->Update();
}

void Game::Render()
{

}
