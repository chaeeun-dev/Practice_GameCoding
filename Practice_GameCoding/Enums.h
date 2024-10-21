#pragma once

enum class SceneType
{
	None,
	DevScene,
	GameScene,
};

enum LAYER_TYPE
{
	LAYER_BACKGROUND,
	LAYER_OBJECT,
	LAYER_UI,

	LAYER_MAXCOUNT
};

enum ColliderType
{
	Box, 
	Sphere,
};