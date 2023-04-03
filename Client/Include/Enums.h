#pragma once

enum class eComponentType
{
	Transform,
	SpriteRenderer,
	Animator,
	Collider,
	Rigidbody,
	Audio,
	End,
};

enum class eLayerType
{
	BG,
	Monster,
	Player,
	Test,
	Effect,
	UI,
	End = 16,
};

enum class eSceneType
{
	Title,
	Play,
	Ending,
	End,
};