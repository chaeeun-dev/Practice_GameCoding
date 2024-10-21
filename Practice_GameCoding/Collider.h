#pragma once
#include "Component.h"

class Collider : public Component
{
public:
	Collider();
	virtual ~Collider() override;

	virtual void BeginPlay() override;
	virtual void TickComponent() override;
	virtual void Render(HDC hdc) override;

	virtual bool CheckCollision(Collider* other);

protected:
	ColliderType _colliderType;
	bool _showDebug = true;
};

