#pragma once

#include <Windows.h>
#include <list>
#include <vector>
#include <unordered_map>
// 디버그용
#include <crtdbg.h>
#include <gdiplus.h>

// GDI+
#pragma comment(lib, "gdiplus.lib")

#define SAFE_DELETE(p)	if(p)	{ delete p;	p = nullptr; }
#define SAFE_DELETE_ARRAY(p)	if(p)	{ delete[] p;	p = nullptr; }