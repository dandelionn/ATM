#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED


#include <fstream>
#include "model.h"
#include "resource.h"
#include "function.h"
#include "Cursor.h"
#include "Bitmap.h"

class View{
      protected:
               int _cx;
               int _cy;

               Bitmap *bmp[50];
               Bitmap *bmpCash[40];
               Cursor *cursor[10];
               HINSTANCE _hInstance;
               HWND _hwnd;
               Func obj;
      public:
               View(){}
               View(HWND hwnd, HINSTANCE hInst)
               {
                     _hwnd = hwnd;
                     _hInstance = hInst;
               }

               HINSTANCE GetHInstance()
               {
                   return _hInstance;
               }

               void SetInst(HINSTANCE hInst)
               {
                     _hInstance = hInst;
               }

               void SetHWND(HWND hwnd)
               {
                   _hwnd = hwnd;
               }

               void LoadBitmaps()
               {
                   if( _hInstance != 0 )
                    {
                        for(int ID=1200; ID<=1213;ID++)
                        {
                              bmp[ID-1200] = new Bitmap(ID, _hInstance);
                              if(!bmp[ID-1200]->LoadBitmap())
                                   ::MessageBox(NULL, "Bitmap not loaded" , "Notice", MB_OK | MB_ICONINFORMATION);
                        }
                        for(int ID=217; ID <= 231; ID++)
                        {
                              bmpCash[ID-217] = new Bitmap(ID, _hInstance);
                              if(!bmpCash[ID-217]->LoadBitmap())
                                   ::MessageBox(NULL, "Bitmap not loaded" , "Notice", MB_OK | MB_ICONINFORMATION);
                        }
                    }
               }

               void LoadCursors()
               {
                   int width, height;
                   std::ifstream f("cursordim.in");

                   if( _hInstance != 0 )
                        {
                              for(int ID = 800; ID <= 806; ID++)
                                   {
                                       f>> width >> height;
                                       cursor[ID-800] = new Cursor();
                                       cursor[ID-800]->LoadCursor(_hInstance, ID, width, height);
                                   }
                        }
                   f.close();
               }

               void setCursor(int ID)
               {
                   ::SetClassLong(_hwnd,  GCL_HCURSOR, (LONG) cursor[ID - 800]->getCursor());
               }

               void resetCursor()
               {
                   ::SetClassLong(_hwnd,  GCL_HCURSOR, (LONG) ::LoadCursor(NULL, IDC_HAND));
               }

               void SetSize(int cxNew, int cyNew)
               {
                   _cx = cxNew;
                   _cy = cyNew;
               }

               void Paint(Canvas &canvas, Model &model)
               {
                   canvas.Text(12, 1, model.GetText(), model.GetLen());
                   canvas.Line(10, 0, 10, _cy);
               }

               void Paint(HWND hwnd, Model &model)
               {
                   obj.PaintMainWindow(hwnd                   , bmp[0]->getBMP());//,  0, 0, 540 ,  400 );
                   obj.PaintWindow(hwnd, ID_BOX_DISPLAY       , bmp[1]->getBMP(),  0, 0, 540 ,  400 );  ///DISPLAY
                   obj.PaintWindow(hwnd, ID_BOX_CARD          , bmp[2]->getBMP(),  0, 0, 250 ,  26  );
                   obj.PaintWindow(hwnd, ID_BOX_STATEMENT     , bmp[3]->getBMP(),  0, 0, 272 ,  52  );
                   obj.PaintWindow(hwnd, ID_BOX_LSCREENFRAME  , bmp[4]->getBMP(),  0, 0, 20  ,  400 );
                   obj.PaintWindow(hwnd, ID_BOX_RSCREENFRAME  , bmp[4]->getBMP(),  0, 0, 20  ,  400 );
                   obj.PaintWindow(hwnd, ID_BOX_TSCREENFRAME  , bmp[5]->getBMP(),  0, 0, 580 ,  8   );
                   obj.PaintWindow(hwnd, ID_BOX_BSCREENFRAME  , bmp[5]->getBMP(),  0, 0, 580 ,  8   );
                   obj.PaintWindow(hwnd, ID_BOX_CASHOUT       , bmp[6]->getBMP(),  0, 0, 332 ,  78  );

                   obj.PaintWindow(hwnd, ID_BOX_CASH10        , bmp[7]->getBMP(),  0, 0, 53  ,  98  );
                   obj.PaintWindow(hwnd, ID_BOX_CASH50        , bmp[8]->getBMP(),  0, 0, 52  ,  98  );
                   obj.PaintWindow(hwnd, ID_BOX_CASH100       , bmp[9]->getBMP(),  0, 0, 54  ,  98  );
                   obj.PaintWindow(hwnd, ID_BOX_CASH200       , bmp[10]->getBMP(),  0, 0, 53  ,  98  );
                   obj.PaintWindow(hwnd, ID_BOX_CASH500       , bmp[11]->getBMP(), 0, 0, 51  ,  98  );

                   obj.PaintWindow(hwnd, ID_BOX_CASHIN        , bmp[12]->getBMP(), 0, 0, 238 ,  44  );
                   obj.PaintWindow(hwnd, ID_BOX_STATIC        , bmp[13]->getBMP(), 0, 0, 200 ,  300 );

                   ///Text and Fonts
                   obj.DrawTextFonts(hwnd, ID_BOX_DISPLAY, model.getDisplayText());
                   obj.DrawTextFonts(hwnd, ID_BOX_STATIC, model.getStatementText());
               }

               void PaintDC(HWND hwnd, Model &model, int ID)
               {
                   if(ID == ID_BOX_DISPLAY)
                            {
                                obj.PaintWindowDC(hwnd, ID_BOX_DISPLAY, bmp[1]->getBMP(),  0, 0, 540, 400);
                                obj.DrawTextFonts(hwnd, ID_BOX_DISPLAY, model.getDisplayText());
                            }
                   if( ID == ID_BOX_STATIC)
                            {
                                obj.PaintWindowDC(hwnd, ID_BOX_STATIC, bmp[13]->getBMP(), 0, 0, 200, 300);
                                obj.DrawTextFonts(hwnd, ID_BOX_STATIC, model.getStatementText());
                            }
                   if( ID == ID_BOX_CASHOUT)
                            {
                                obj.PaintWindowDC(hwnd, ID_BOX_CASHOUT, bmp[6]->getBMP(), 0, 0, 332, 78);
                            }
               }
               void PaintDC(HWND hwnd, Model &model, int ID, int number)
               {
                   if( ID == ID_BOX_CASHOUT)
                            {
                                switch(number/5)
                                {
                                     case 0:
                                         obj.PaintWindowDC(hwnd, ID_BOX_CASHOUT, bmpCash[0*3 - 1 + number % 5]->getBMP(), 0, 0, 332 ,  78);
                                     break;

                                     case 1:
                                         obj.PaintWindowDC(hwnd, ID_BOX_CASHOUT, bmpCash[1*3 - 1 + number % 5]->getBMP(), 0, 0, 332 ,  78);
                                     break;

                                     case 2:
                                         obj.PaintWindowDC(hwnd, ID_BOX_CASHOUT, bmpCash[2*3 - 1 + number % 5]->getBMP(), 0, 0, 332 ,  78);
                                     break;

                                     case 3:
                                         obj.PaintWindowDC(hwnd, ID_BOX_CASHOUT, bmpCash[3*3 - 1 + number % 5]->getBMP(), 0, 0, 332 ,  78);
                                     break;

                                     case 4:
                                         obj.PaintWindowDC(hwnd, ID_BOX_CASHOUT, bmpCash[4*3 - 1 + number % 5]->getBMP(), 0, 0, 332 ,  78);
                                     break;
                                }
                            }
               }
};
#endif // VIEW_H_INCLUDED
