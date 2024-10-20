#pragma once

class Component;

class Actor
{
public:
	Actor();
	virtual ~Actor();

	virtual void BeginPlay();
	virtual void Tick();
	virtual void Render(HDC hdc);

	void SetPos(Vec2 pos) { _pos = pos; }
	Vec2 GetPos() { return _pos; }

	// Camera Component
	void AddComponent(Component* component);
	void RemoveComponent(Component* component);

	// Layer
	void SetLayer(LAYER_TYPE layer) { _layer = layer; }
	LAYER_TYPE GetLayer() { return _layer; }

protected:
	// Sprite는 따로 SpriteActor를 생성해서 관리함!
	Vec2 _pos = { 0, 0 };
	vector<Component*> _components;		// Camera Component
	LAYER_TYPE _layer = LAYER_OBJECT;	// Layer
};

