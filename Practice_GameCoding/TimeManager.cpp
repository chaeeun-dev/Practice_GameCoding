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
	uint64 currentCount;
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));

	// 경과된 시간 = 현재 시간 - 이전 시간 / 빈도
	_deltaTime = (currentCount - _prevCount) / static_cast<float>(_frequency);
	_prevCount = currentCount;

	_frameCount++;	// 몇 번 호출 됐는지 계속 추적
	_frameTime += _deltaTime;	// 경과된 시간 추적

	if (_frameTime >= 1.f)
	{
		// 1초동안 몇 번의 함수가 호출?
		_fps = static_cast<uint32>(_frameCount / _frameTime);

		_frameTime = 0.f;
		_frameCount = 0;
	}

}
