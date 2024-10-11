#include "pch.h"
#include "TimeManager.h"

void TimeManager::Init()
{
	// 시간 초를 가져오는 함수
	
	// _frequency는 CPU 클럭의 빈도(주파수)를 나타내며, 이를 이용해 경과된 시간을 계산할 수 있음
	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&_frequency));
	
	// _prevCount는 코드가 마지막으로 시간 측정을 한 시점을 기억하는 변수로 사용
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&_prevCount));	// CPU 쿨럭
}

void TimeManager::Update()
{
	uint64 currentCount = {};
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));

	// 경과된 시간 = (현재 시간 - 이전 시간) / 빈도
	_deltaTime = (currentCount - _prevCount) / static_cast<float>(_frequency);
	_prevCount = currentCount;

	_frameCount++;	// 몇 번 호출 됐는지 계속 추적
	_frameTime += _deltaTime;	// 경과된 시간 추적

	if (_frameTime >= 1.f)
	{
		// 1초동안 몇 번의 함수가 호출?
		_fps = static_cast<uint32>(_frameCount / _frameTime);	// 목적은 fps를 구하기 위한 것

		_frameTime = 0.f;
		_frameCount = 0;
	}
}
