#include "pch.h"
#include "TimeManager.h"

void TimeManager::Init()
{
	// �ð� �ʸ� �������� �Լ�
	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&_frequency));
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&_prevCount));	// CPU ��
}

void TimeManager::Update()
{
}
