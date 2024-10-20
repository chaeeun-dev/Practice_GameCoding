#include "pch.h"
#include "CameraComponent.h"
#include "Actor.h"
#include "SceneManager.h"

CameraComponent::CameraComponent()
{
}

CameraComponent::~CameraComponent()
{
}

void CameraComponent::BeginPlay()
{
}

void CameraComponent::TickComponent()	// Camera의 pos를 owner의 위치로 계속 업데이트 해줌
{
	if (_owner == nullptr)
		return;

	Vec2 pos = _owner->GetPos();

	// 배경 제한
	pos.x = ::clamp(pos.x, 400.f, 3024.f - 400.f);
	pos.y = ::clamp(pos.y, 300.f, 2064.f - 300.f);

	GET_SINGLE(SceneManager)->SetCameraPos(pos);
}

void CameraComponent::Render(HDC hdc)
{
}
