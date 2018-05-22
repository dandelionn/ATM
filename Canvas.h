#ifndef CANVAS_H_INCLUDED
#define CANVAS_H_INCLUDED

#include <windows.h>

class Canvas
{
     protected:
         Canvas(){}
         ///Protected constructor: You can't construct
         ///a Canvas object, but you may be able
         ///to construct objects derived from it.
         Canvas(HDC hdc)
         {
             _hdc = hdc;
         }
         HDC _hdc;

     public:
         operator HDC(){return _hdc;}

         void Line(int x1, int y1, int x2, int y2)
         {
              ::MoveToEx(_hdc, x1, y1, 0);
              ::LineTo(_hdc, x2, y2);
         }

         void Text(int x, int y, char const* buf, int cBuf)
         {
              ::TextOut (_hdc, x, y, buf, cBuf);
         }

         void Char(int x, int y, char c)
         {
             ::TextOut(_hdc, x, y, &c, 1);
         }

         void SetPixel( int x, int y, COLORREF color)
         {
             ::SetPixel(_hdc, x, y, color);
         }

         int TabbedText(int x, int y, char const* buf, int cBuf, int tabSize)
         {
             DWORD dim=::TabbedTextOut(_hdc, x, y, buf, cBuf, 1, &tabSize, 0);
             return LOWORD(dim);
         }

         void GetTextSize( int &cxChar, int &cyChar)
         {
             TEXTMETRIC tm;
             ::GetTextMetrics(_hdc, &tm);
             cxChar = tm.tmAveCharWidth;
             cyChar = tm.tmHeight + tm.tmExternalLeading;
         }

         void SelectObject(void *pObj)
         {
             ::SelectObject(_hdc, pObj);
         }
};
#endif // CANVAS_H_INCLUDED
