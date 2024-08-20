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
	uint64 currentCount;
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));

	// ����� �ð� = ���� �ð� - ���� �ð� / ��
	_deltaTime = (currentCount - _prevCount) / static_cast<float>(_frequency);
	_prevCount = currentCount;

	_frameCount++;	// �� �� ȣ�� �ƴ��� ��� ����
	_frameTime += _deltaTime;	// ����� �ð� ����

	if (_frameTime >= 1.f)
	{
		// 1�ʵ��� �� ���� �Լ��� ȣ��?
		_fps = static_cast<uint32>(_frameCount / _frameTime);

		_frameTime = 0.f;
		_frameCount = 0;
	}

}
