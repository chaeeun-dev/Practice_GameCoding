#pragma once

class Scene
{
public:
	Scene();
	virtual ~Scene();		// 최상위 객체 - 소멸자 가상함수

	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;
};

