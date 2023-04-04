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
#include <functional>
#include <filesystem>

//#include "FMOD/fmod.hpp"

// GDI+
#pragma comment(lib, "gdiplus.lib")
// GDI
//#pragma comment(lib, "Msimg32.lib")

// FMOD
//#pragma comment(lib, "../Lib/fmod64_vc.lib")

#include <mmsystem.h>
#include <dsound.h>
#include <dinput.h>

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "dsound.lib")

#define SAFE_DELETE(p)	if(p)	{ delete p;	p = nullptr; }
#define SAFE_DELETE_ARRAY(p)	if(p)	{ delete[] p;	p = nullptr; }