#ifndef CURSOR_H_INCLUDED
#define CURSOR_H_INCLUDED

#include <windows.h>

class Cursor{
    HCURSOR _hcursor;

    public:
        Cursor(){}
        Cursor(HCURSOR hC)
        {
            _hcursor = hC;
        }

        void setCursor(HCURSOR hC)
        {
            _hcursor = hC;
        }

        HCURSOR getCursor()
        {
            return _hcursor;
        }

        void LoadCursor(HINSTANCE &hInst, int item_ID, int width, int height)
        {
            _hcursor = (HCURSOR) ::LoadImage( hInst, MAKEINTRESOURCE(item_ID),IMAGE_ICON, width, height, LR_LOADTRANSPARENT);

            if(_hcursor == NULL)
                 MessageBox(NULL,"Cursor Icon not loaded","Cursor not loaded", MB_ICONEXCLAMATION | MB_OK);
        }
};
#endif // CURSOR_H_INCLUDED
