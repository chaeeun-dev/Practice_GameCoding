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

	const FlipbookInfo& info = _flipbook->GetInfo();	// 현재 실행중인 플립북의 정보
	if (info.loop == false && _idx == info.end)		// 실행이 완료 됐다면 끝냄
		return;

	// 실행할 때
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	_sumTime += deltaTime;		// 진행 시간 
	int32 frameCount = (info.end - info.start + 1);
	float delta = info.duration / frameCount;

	if (_sumTime >= delta)	// 추적된 시간이 deltaTime보다 크면
	{
		_sumTime = 0.f;
		_idx = (_idx + 1) % frameCount;		// 다음에 실행해야 하는 인덱스 고름
	}
}

void FlipbookActor::Render(HDC hdc)
{
	Super::Render(hdc);

	if (_flipbook == nullptr)
		return;

	const FlipbookInfo& info = _flipbook->GetInfo();	// 현재 실행중인 플립북의 정보

	::TransparentBlt(hdc,
		(int32)_pos.x - info.size.x / 2,		// Actor의 중심
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
