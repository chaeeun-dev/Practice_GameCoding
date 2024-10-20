#pragma once
#include "Scene.h"		// 상속 받으면 전방 선언 의미 없음. include로 상속 받는 객체를 받아야 함

class Actor;

class DevScene : public Scene
{
public:
	DevScene();
	virtual ~DevScene() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

public:
	vector<Actor*> _actors;
};

