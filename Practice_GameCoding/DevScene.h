#pragma once
#include "Scene.h"		// ��� ������ ���� ���� �ǹ� ����. include�� ��� �޴� ��ü�� �޾ƾ� ��

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

