#include "Component.h"

namespace kyr
{
	Component::Component(eComponentType type)
		: mType(type)
	{
	}

	Component::~Component()
	{
	}

	void Component::Initialize()
	{
	}

	void Component::Update()
	{
	}

	void Component::Render(Gdiplus::Graphics* gp)
	{
	}

	void Component::Release()
	{
	}

}