#include "function.h"
#include <windows.h>


void Func::setData(HWND hwnd1, int ID1, HBITMAP &hbm1)
{
    hwnd=hwnd1;
    ID=ID1;
    hbm=hbm1;
}

HWND Func::getHW()
{
    return hwnd;
}

int Func::getID()
{
    return ID;
}

HBITMAP Func::getBMP()
{
    return hbm;
}

void Func::AdjustControlSize(HWND hwnd, RECT rcDesktop, RECT* rcDisplay) ///Ajusteaza dimensiunea display-ului(ATM) la dimensiune ecranului
{
    //if(rcDesktop.right == 1366 && rcDesktop.bottom == 768 )
                //{
                rcDisplay->bottom = 400;
                rcDisplay->right = 540;
                rcDisplay->left = 400;
                rcDisplay->top = 5;
                //}
    //else   //pentru 1920,1080
      /*     {rcDisplay->bottom = 562;
           rcDisplay->right = 759;
           rcDisplay->left = 581;
           rcDisplay->top = 7;}*/
}

void Func::PaintMainWindow(HWND hwnd, HBITMAP hbm_image)
{
        /*HDC hdc,hdcMem;
        HBITMAP hbm_old;
        BITMAP bm;
        PAINTSTRUCT ps;*/

        hdc = BeginPaint(hwnd, &ps);
        hdcMem = CreateCompatibleDC(hdc);
        hbm_old = (HBITMAP) SelectObject(hdcMem, hbm_image);

        GetObject( hbm_image, sizeof(bm), &bm);

        BitBlt(hdc, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);
                    //BitBlt(hdc, 0, 0, 500, 500, hdcMem, 0, 0, SRCCOPY);

        SelectObject(hdcMem, hbm_old);
        DeleteDC(hdcMem);

        EndPaint(hwnd, &ps);
}

void Func::PaintWindowDC(HWND hwnd, int item_id, HBITMAP hbm_image, int x, int y, int width, int height)
{
        /*HDC hdc, hdcMem;
        HBITMAP hbm_old;*/

        hdc = GetDC(GetDlgItem(hwnd,item_id));
        hdcMem = CreateCompatibleDC(hdc);

        hbm_old = (HBITMAP) SelectObject(hdcMem, hbm_image);
        BitBlt(hdc, 0, 0, width, height, hdcMem, 0, 0, SRCCOPY);

        SelectObject(hdcMem, hbm_old);
        DeleteDC(hdcMem);
        ReleaseDC(GetDlgItem(hwnd, item_id), hdc);

        DeleteObject(hbm_old);
}

void Func::PaintWindow(HWND hwnd, int item_id, HBITMAP hbm_image, int x, int y, int width, int height)
{
     /*BITMAP bm;
     PAINTSTRUCT ps;
     HDC hdc, hdcMem;
     HBITMAP hbm_old;*/

     hdc = BeginPaint(GetDlgItem(hwnd,item_id), &ps);
     hdcMem = CreateCompatibleDC(hdc);
     hbm_old = (HBITMAP) SelectObject(hdcMem, hbm_image);

     GetObject( hbm_image, sizeof(bm), &bm);

     BitBlt(hdc, x, y, width, height, hdcMem, 0, 0, SRCCOPY);

     SelectObject(hdcMem, hbm_old);
     DeleteDC(hdcMem);
     DeleteDC(hdc);

     EndPaint(GetDlgItem(hwnd,item_id), &ps);
     DeleteObject(hbm_old);
}

void Func::DrawTextFonts(HWND hwnd, int item_id, char szTitle[])
{
                    //HDC hdc;
                    /*long lfHeight;
                    HFONT hf_font, old_font;*/

                    hdc = GetDC(NULL);
                    lfHeight = -MulDiv(12, GetDeviceCaps(hdc, LOGPIXELSY), 72);
                    ReleaseDC(NULL, hdc);

			        hdc = GetDC(GetDlgItem(hwnd, item_id));

                    hf_font = CreateFont(lfHeight*1.1, 0, 0, 0, FW_THIN, FALSE, 0, 0 , 0, 0, 0, 0, 0, "Batang");

                    if(!hf_font)
                        MessageBox(hwnd, "Font creation failed!", "Error", MB_OK | MB_ICONEXCLAMATION);

                    old_font = (HFONT) SelectObject(hdc, hf_font);

                    SetTextColor(hdc, RGB(255,255,255));
                    SetBkMode(hdc, TRANSPARENT);


                    //RECT rcClient;
                    GetClientRect(GetDlgItem(hwnd, item_id), &rcClient);
                    //RECT* prc = &rcClient;
                    prc = &rcClient;

                    DrawText(hdc, szTitle, -1, prc, DT_WORDBREAK);

                    ///Memory leaks can cause the program to behave in a strange way;
                    /// Drawing process can be affected by memory leaks;
                    SelectObject(hdc, old_font);
                    DeleteObject(hf_font);
                    DeleteObject(old_font);
}
