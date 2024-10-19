#pragma once

class Component
{
public:
	Component();
	virtual ~Component();

	virtual void Start() {}
	virtual void Update() {}
	virtual void Render(HDC hdc) {}
};

