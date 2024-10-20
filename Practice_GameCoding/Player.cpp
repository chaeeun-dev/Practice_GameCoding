#include "pch.h"
#include "Player.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "CameraComponent.h"


Player::Player()
{
	_flipbookUp = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_MoveUp");
	_flipbookDown = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_MoveDown");
	_flipbookLeft = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_MoveLeft");
	_flipbookRight = GET_SINGLE(ResourceManager)->GetFlipbook(L"FB_MoveRight");

	// Camera 붙이기
	CameraComponent* camera = new CameraComponent();
	AddComponent(camera);
}

Player::~Player()
{
}

void Player::BeginPlay()
{
	Super::BeginPlay();

	SetFlipbook(_flipbookRight);	// 처음 세팅
}

void Player::Tick()
{
	Super::Tick();

	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	if (GET_SINGLE(InputManager)->GetButton(KeyType::A))
	{
		_pos.x -= 200 * deltaTime;
		SetFlipbook(_flipbookLeft);
	}
	if (GET_SINGLE(InputManager)->GetButton(KeyType::D))
	{
		_pos.x += 200 * deltaTime;
		SetFlipbook(_flipbookRight);
	}
	if (GET_SINGLE(InputManager)->GetButton(KeyType::W))
	{
		_pos.y -= 200 * deltaTime;
		SetFlipbook(_flipbookUp);
	}
	if (GET_SINGLE(InputManager)->GetButton(KeyType::S))
	{
		_pos.y += 200 * deltaTime;
		SetFlipbook(_flipbookDown);
	}
}

void Player::Render(HDC hdc)
{
	Super::Render(hdc);
}
