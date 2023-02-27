#pragma once

#include <Windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <assert.h>
#include <crtdbg.h>
#include <gdiplus.h>

#include <string>
#include <list>
#include <vector>
#include <map>

// GDI+
#pragma comment(lib, "gdiplus.lib")
// GDI
//#pragma comment(lib, "Msimg32.lib")

#define SAFE_DELETE(p)	if(p)	{ delete p;	p = nullptr; }
#define SAFE_DELETE_ARRAY(p)	if(p)	{ delete[] p;	p = nullptr; }