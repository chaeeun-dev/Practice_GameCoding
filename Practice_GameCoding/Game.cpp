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
	_hdc = ::GetDC(hwnd);		// hwnd ������ hdc�� �˾Ƴ��� �Լ�
}

void Game::Update()
{

}

void Game::Render()
{

}
