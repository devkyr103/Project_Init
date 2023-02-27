#pragma once

enum class eColorType
{
	Red,
	Green,
	Black,
	Blue,
	Yellow,
	Max
};

enum class eComponentType
{
	Transform,
	Collider,
	SpriteRenderer,
	Animator,
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
	End,
};

enum class eSceneType
{
	Title,
	Play,
	Ending,
	End,
};