#pragma once

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

protected:
	Vec2 _pos = { 0, 0 };
	// Sprite는 따로 SpriteActor를 생성해서 관리함!
};

