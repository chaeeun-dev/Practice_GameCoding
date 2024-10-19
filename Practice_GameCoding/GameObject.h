#pragma once

class Component;	// Component 붙여주기 위해

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Start();
	virtual void Update();
	virtual void Render(HDC hdc);

	void SetPos(Vec2 pos) { _pos = pos; }
	Vec2 GetPos() { return _pos; }

	void AddComponent(Component* component);

protected:
	Vec2 _pos = { 0, 0 };
	vector<Component*> _components;
};

