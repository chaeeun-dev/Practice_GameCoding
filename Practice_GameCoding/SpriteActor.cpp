#include "pch.h"
#include "SpriteActor.h"
#include "Sprite.h"

SpriteActor::SpriteActor()
{
}

SpriteActor::~SpriteActor()
{
}

void SpriteActor::BeginPlay()
{
	Super::BeginPlay();		// 부모 먼저 호출
}

void SpriteActor::Tick()
{
	Super::Tick();
}

void SpriteActor::Render(HDC hdc)
{
	Super::Render(hdc);

	if (_sprite == nullptr)
		return;

	Vec2Int size = _sprite->GetSize();	// Sprite size 얻어옴

	::BitBlt(hdc,
		(int32)_pos.x - size.x / 2, (int32)_pos.y - size.y / 2,
		size.x, size.y,
		_sprite->GetDC(),
		_sprite->GetPos().x, _sprite->GetPos().y,
		SRCCOPY);

}
