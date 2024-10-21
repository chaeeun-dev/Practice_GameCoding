#include "pch.h"
#include "SphereCollider.h"
#include "SceneManager.h"
#include "Actor.h"

SphereCollider::SphereCollider()
{
}

SphereCollider::~SphereCollider()
{
}

void SphereCollider::BeginPlay()
{
	Super::BeginPlay();
}

void SphereCollider::TickComponent()
{
	Super::TickComponent();
}

void SphereCollider::Render(HDC hdc)
{
	Super::Render(hdc);

	if (_showDebug == false)
		return;

	Vec2 cameraPos = GET_SINGLE(SceneManager)->GetCameraPos();
	Vec2 pos = GetOwner()->GetPos();
	
	// 카메라 중앙점 보정
	pos.x -= (cameraPos.x - GWinSizeX / 2);	// cameraPos.x - GWinSizeX / 2 => 카메라의 중앙 위치 구하는 작업, pos.x -= (cameraPos.x - GWinSizeX / 2) => 화면 중앙을 기준으로 객체의 위치를 조정. 즉, 카메라의 움직임에 따라 객체가 화면에 그렬질 위치를 결정함
	pos.y -= (cameraPos.y - GWinSizeY / 2);

	HBRUSH myBrush = (HBRUSH)::GetStockObject(NULL_BRUSH);
	HBRUSH oldBrush = (HBRUSH)::SelectObject(hdc, myBrush);
	Utils::DrawCircle(hdc, pos, _radius);
	::SelectObject(hdc, oldBrush);
	::DeleteObject(myBrush);
}

bool SphereCollider::CheckCollision(Collider* other)
{
	return false;
}
