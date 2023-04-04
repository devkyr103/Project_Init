#pragma once

enum class eComponentType
{
	Transform,
	BackImage,
	//SpriteRenderer,
	Animator,
	Collider,
	Rigidbody,
	Audio,
	End,
};

enum class eLayerType
{
	BG,
	BackObj,
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
	Pride,
	Anger,
	Greed,
	Gluttony,
	Lust,
	Envy,
	Sloth,
	End,
};