#pragma once
#include "CommonInclude.h"

enum class eColorType
{
	White,
	Black,
	Red,
	Green,
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

