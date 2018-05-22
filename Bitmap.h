#ifndef BITMAP_H_INCLUDED
#define BITMAP_H_INCLUDED
#include <windows.h>
#include   "Canvas.h"

class Bitmap{
    private:
          HBITMAP     _hBitmap;
          int         _bmpID;
          HINSTANCE   _hInstance;
          void Free()
          {
              if(_hBitmap)
                 ::DeleteObject(_hBitmap);
          }

    public:
        Bitmap()
        {
             _hBitmap = 0;
        }

        Bitmap(int bmpID, HINSTANCE hInst)
        {
              _bmpID         = bmpID;
              _hInstance     = hInst;
        }

        bool LoadBitmap()
        {
            Free();
            _hBitmap  = ::LoadBitmap(_hInstance, MAKEINTRESOURCE(_bmpID));
            if( _hBitmap == NULL )
                return 0;
            else
                return 1;
        }

        void CreateCompatible(Canvas &canvas, int width, int height)
        {
            Free();
            _hBitmap = ::CreateCompatibleBitmap(canvas, width, height);
        }

        void GetSize(int &width, int &height)
        {
            BITMAP  bm;
            ::GetObject(_hBitmap, sizeof(bm), &bm);
            width  = bm.bmWidth;
            height = bm.bmHeight;
        }

        HBITMAP getBMP()
        {
                 return _hBitmap;
        }

        ~Bitmap()
        {
             ::DeleteObject(_hBitmap);
        }
};
#endif // BITMAP_H_INCLUDED
