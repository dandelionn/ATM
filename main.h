#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <windows.h>
#include "WinClass.h"
#include "WinMaker.h"
#include "function.h"

LRESULT CALLBACK MainWndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK AboutDlgProc(HWND, UINT, WPARAM, LPARAM);

#endif // MAIN_H_INCLUDED
