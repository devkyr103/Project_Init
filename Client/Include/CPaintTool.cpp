#include "CPaintTool.h"

Gdiplus::SolidBrush* CPaintTool::mBrush[(int)eColorType::Max]{};
Gdiplus::Pen* CPaintTool::mPen[(int)eColorType::Max]{};