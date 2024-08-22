#pragma once
#include "Object.h"

class Missile : public Object
{
public:
	Missile();
	virtual ~Missile();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

protected:

};

