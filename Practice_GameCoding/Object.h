#pragma once

enum class ObjectType
{
	None,
	Player,
	Monster,
	Projectile,
};

// 최상위 객체
class Object
{
public:
	Object(ObjectType type);
	virtual ~Object();		// 최상위 객체는 무조건 가상함수

	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

public:
	ObjectType GetObjectType() { return _type; }

	Pos GetPos() { return _pos; }
	void SetPod(Pos pos) { _pos = pos; }

protected:
	ObjectType _type = ObjectType::None;
	Stat _stat = {};
	Pos _pos = {};

};

