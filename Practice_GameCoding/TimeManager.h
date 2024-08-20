#pragma once

// Manager는 singleton 방식으로 - 객체에 종속X
class TimeManager
{
	DECLARE_SINGLE(TimeManager);

public:
	void Init();
	void Update();

	uint32 GetFps() { return _fps; }
	float GetDeltaTime() { return deltaTime; }

private:
	uint64 _frequency = 0;
	uint64 _prevCount = 0;
	float deltaTime = 0.f;

private:
	uint32 _frameCount = 0;
	float _frameTime = 0.0f;
	uint32 _fps = 0;
};

