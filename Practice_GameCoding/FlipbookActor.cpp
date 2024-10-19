#include "pch.h"
#include "FlipbookActor.h"
#include "Flipbook.h"
#include "TimeManager.h"
#include "Texture.h"

FlipbookActor::FlipbookActor()
{
}

FlipbookActor::~FlipbookActor()
{
}

void FlipbookActor::BeginPlay()
{
	Super::BeginPlay();
}

void FlipbookActor::Tick()
{
	Super::Tick();

	if (_flipbook == nullptr)
		return;

	const FlipbookInfo& info = _flipbook->GetInfo();	// ���� �������� �ø����� ����
	if (info.loop == false && _idx == info.end)		// ������ �Ϸ� �ƴٸ� ����
		return;

	// ������ ��
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	_sumTime += deltaTime;		// ���� �ð� 
	int32 frameCount = (info.end - info.start + 1);
	float delta = info.duration / frameCount;

	if (_sumTime >= delta)	// ������ �ð��� deltaTime���� ũ��
	{
		_sumTime = 0.f;
		_idx = (_idx + 1) % frameCount;		// ������ �����ؾ� �ϴ� �ε��� ��
	}
}

void FlipbookActor::Render(HDC hdc)
{
	Super::Render(hdc);

	if (_flipbook == nullptr)
		return;

	const FlipbookInfo& info = _flipbook->GetInfo();	// ���� �������� �ø����� ����

	::TransparentBlt(hdc,
		(int32)_pos.x - info.size.x / 2,		// Actor�� �߽�
		(int32)_pos.y - info.size.y / 2,
		info.size.x,
		info.size.y,
		info.texture->GetDC(),
		(info.start + _idx) * info.size.x,
		info.line * info.size.y,
		info.size.x,
		info.size.y,
		info.texture->GetTransparent());

}

void FlipbookActor::SetFlipbook(Flipbook* flipbook)
{
	if (flipbook && _flipbook == flipbook)
		return;

	_flipbook = flipbook;
	Reset();
}

void FlipbookActor::Reset()
{
	_sumTime = 0.f;
	_idx = 0;
}
