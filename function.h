#ifndef FUNCTION2_H_INCLUDED
#define FUNCTION2_H_INCLUDED
#include <windows.h>
#include "resource.h"

class Func{
      ///local variables
      HDC hdc,hdcMem;
      HBITMAP hbm_old;
      BITMAP bm;
      PAINTSTRUCT ps;

      //for text
      long lfHeight;
      HFONT hf_font, old_font;

      RECT rcClient;
      RECT* prc;
      ///___________________________


      HWND hwnd;
      int ID;
      HBITMAP hbm;
public:
      Func(){}
      void setData(HWND, int, HBITMAP&);
      HWND getHW();
      int  getID();
      HBITMAP getBMP();
      void setData(HWND, int, HBITMAP);
      void AdjustControlSize(HWND, RECT, RECT*); ///Ajusteaza dimensiunea display-ului(ATM) la dimensiune ecranului
      void PaintMainWindow(HWND, HBITMAP);
      void PaintWindowDC(HWND, int, HBITMAP, int, int, int, int);
      void PaintWindow(HWND, int, HBITMAP, int x, int y, int, int);
      void DrawTextFonts(HWND, int , char[]);
};
#endif // FUNCTION2_H_INCLUDED
