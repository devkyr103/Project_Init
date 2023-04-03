#include "CComponent.h"

namespace kyr
{
	CComponent::CComponent(eComponentType type)
		: mType(type)
	{
	}

	CComponent::~CComponent()
	{
	}

	void CComponent::Initialize()
	{
	}

	void CComponent::Update()
	{
	}

	void CComponent::Render(Gdiplus::Graphics* gp)
	{
	}

	void CComponent::Release()
	{
	}

}