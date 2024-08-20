#include "pch.h"
#include "TimeManager.h"

void TimeManager::Init()
{
	// 시간 초를 가져오는 함수
	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&_frequency));
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&_prevCount));	// CPU 쿨럭
}

void TimeManager::Update()
{
}
