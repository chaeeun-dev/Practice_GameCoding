#include "pch.h"
#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init(HWND hwnd)
{
	_hwnd = hwnd;
	_hdc = ::GetDC(hwnd);		// hwnd 값으로 hdc값 알아내는 함수
}

void Game::Update()
{

}

void Game::Render()
{

}
