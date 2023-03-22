#pragma once
#include "CommonInclude.h"

enum class eColorType
{
	Red,
	Green,
	Black,
	Blue,
	Yellow,
	Max
};

class CPaintTool
{
public:
	static Gdiplus::SolidBrush* mBrush[(int)eColorType::Max];
	static Gdiplus::Pen* mPen[(int)eColorType::Max];
};

