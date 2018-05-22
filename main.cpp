#include "main.h"
#include "resource.h"

int   WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszArgument, int cmdShow)
{
        ///Create top window class
        WinClass winClass(ID_MAIN, hInst, MainWndProc);
        winClass.SetMenu(ID_MAIN);
        winClass.SetResIcons(ID_MAIN);
        //winClass.setCursor(ID_ICO_CLIENTCARD);

        ///Is there a running instance of this program?
        HWND hwndOther = winClass.GetRunningWindow();
        if( hwndOther != 0)
        {
            ::SetForegroundWindow(hwndOther); ///Brings the thread that created the specified window into the foreground and activates the window
            if (::IsIconic(hwndOther))        ///Determines whether the specified window is minimized (iconic).
                ::ShowWindow(hwndOther, SW_RESTORE);   ///Activates and displays the window. If the window is minimized or maximized, the system restores it to its original size and position. An application should specify this flag when restoring a minimized window
            return 0;
        }

        if(!winClass.Register())
            return 0;

        ///Create main window
        ResString caption (hInst, ID_CAPTION);
        WinMaker win(winClass.GetName(), winClass.GetInstance());
        win.AddCaption(caption.getString());
        win.AddStyle();
        win.Create();

        ///Create ChildWindows
       RECT rcDesktop;
       RECT rcDisplay;
       Func obj;

       GetClientRect(GetDesktopWindow(), &rcDesktop);
       obj.AdjustControlSize(win.getHWND(), rcDesktop, &rcDisplay);

        ///STATEMENT OUT
        WinMaker win1("STATIC", hInst);
        win1.AddStyle(WS_CHILD| WS_VISIBLE);
        win1.AddExStyle(WS_EX_APPWINDOW);
        win1.AddParent(win.getHWND());
        win1.SetPosition(rcDisplay.left + rcDisplay.right + 100,240,272,52);
        win1.SetWndID(ID_BOX_STATEMENT);
        win1.Create();

        ///STATIC BOX   ///don't forget the text left under the paper image!!
        WinMaker win2("STATIC", hInst);
        win2.AddStyle(WS_CHILD| WS_VISIBLE);
        win2.AddExStyle(WS_EX_APPWINDOW | WS_EX_RIGHTSCROLLBAR);
        win2.AddParent(win.getHWND());
        win2.SetPosition(rcDisplay.left + rcDisplay.right + 100 + 31,275,200,300);
        win2.SetWndID(ID_BOX_STATIC);
        win2.Create();

        ///CARDGETTER
        WinMaker win3("STATIC", hInst);
        win3.AddStyle(WS_CHILD| WS_VISIBLE);
        win3.AddExStyle(WS_EX_APPWINDOW);
        win3.AddParent(win.getHWND());
        win3.SetPosition(rcDisplay.left + rcDisplay.right + 100, rcDisplay.top + 100, 250, 26);
        win3.SetWndID(ID_BOX_CARD);
        win3.Create();

        ///CASH GETTER
        WinMaker win4("STATIC", hInst);
        win4.AddStyle(WS_CHILD| WS_VISIBLE);
        win4.AddExStyle(WS_EX_APPWINDOW);
        win4.AddParent(win.getHWND());
        win4.SetPosition(49, 290, 238, 44);
        win4.SetWndID(ID_BOX_CASHIN);
        win4.Create();

        ///CASHOUT
        WinMaker win5("STATIC", hInst);
        win5.AddStyle(WS_CHILD| WS_VISIBLE);
        win5.AddExStyle(WS_EX_APPWINDOW);
        win5.AddParent(win.getHWND());
        win5.SetPosition(rcDisplay.left + 100, rcDisplay.top + rcDisplay.bottom + 50, 332, 78);
        win5.SetWndID(ID_BOX_CASHOUT);
        win5.Create();

        ///CASH10
        WinMaker win6("STATIC", hInst);
        win6.AddStyle(WS_CHILD| WS_VISIBLE);
        win6.AddExStyle(WS_EX_APPWINDOW);
        win6.AddParent(win.getHWND());
        win6.SetPosition(20, rcDisplay.top + rcDisplay.bottom + 170, 53, 98);
        win6.SetWndID(ID_BOX_CASH10);
        win6.Create();

        ///CASH50
        WinMaker win7("STATIC", hInst);
        win7.AddStyle(WS_CHILD| WS_VISIBLE);
        win7.AddExStyle(WS_EX_APPWINDOW);
        win7.AddParent(win.getHWND());
        win7.SetPosition(90, rcDisplay.top + rcDisplay.bottom + 170, 52, 98);
        win7.SetWndID(ID_BOX_CASH50);
        win7.Create();

        ///CASH100
        WinMaker win8("STATIC", hInst);
        win8.AddStyle(WS_CHILD| WS_VISIBLE);
        win8.AddExStyle(WS_EX_APPWINDOW);
        win8.AddParent(win.getHWND());
        win8.SetPosition(160, rcDisplay.top + rcDisplay.bottom + 170, 54, 98);
        win8.SetWndID(ID_BOX_CASH100);
        win8.Create();

        ///CASH200
        WinMaker win9("STATIC", hInst);
        win9.AddStyle(WS_CHILD| WS_VISIBLE);
        win9.AddExStyle(WS_EX_APPWINDOW);
        win9.AddParent(win.getHWND());
        win9.SetPosition(230, rcDisplay.top + rcDisplay.bottom + 170, 53, 98);
        win9.SetWndID(ID_BOX_CASH200);
        win9.Create();

        ///CASH500
        WinMaker win10("STATIC", hInst);
        win10.AddStyle(WS_CHILD| WS_VISIBLE);
        win10.AddExStyle(WS_EX_APPWINDOW);
        win10.AddParent(win.getHWND());
        win10.SetPosition(300, rcDisplay.top + rcDisplay.bottom + 170, 51, 98);
        win10.SetWndID(ID_BOX_CASH500);
        win10.Create();

        ///LEFT SCREENFRAME
        WinMaker win11("STATIC", hInst);
        win11.AddStyle(WS_CHILD| WS_VISIBLE);
        win11.AddExStyle(WS_EX_APPWINDOW);
        win11.AddParent(win.getHWND());
        win11.SetPosition(rcDisplay.left - 20, rcDisplay.top , 20, 400);
        win11.SetWndID(ID_BOX_LSCREENFRAME);
        win11.Create();

        ///RIGHT SCREENFRAME
        WinMaker win12("STATIC", hInst);
        win12.AddStyle(WS_CHILD| WS_VISIBLE);
        win12.AddExStyle(WS_EX_APPWINDOW);
        win12.AddParent(win.getHWND());
        win12.SetPosition(rcDisplay.left + rcDisplay.right, rcDisplay.top, 20, 400);
        win12.SetWndID(ID_BOX_RSCREENFRAME);
        win12.Create();

        ///TOP SCREENFRAME
        WinMaker win13("STATIC", hInst);
        win13.AddStyle(WS_CHILD| WS_VISIBLE);
        win13.AddExStyle(WS_EX_APPWINDOW);
        win13.AddParent(win.getHWND());
        win13.SetPosition( rcDisplay.left-20, rcDisplay.top-8, 540, 8);
        win13.SetWndID(ID_BOX_TSCREENFRAME);
        win13.Create();

        ///BOTTOM SCREENFRAME
        WinMaker win14("STATIC", hInst);
        win14.AddStyle(WS_CHILD | WS_VISIBLE);
        win14.AddExStyle(WS_EX_APPWINDOW);
        win14.AddParent(win.getHWND());
        win14.SetPosition(rcDisplay.left-20, rcDisplay.top + rcDisplay.bottom, 540, 8);
        win14.SetWndID(ID_BOX_BSCREENFRAME);
        win14.Create();

        ///DISPLAY
        WinMaker win15("STATIC", hInst);
        win15.AddStyle(WS_CHILD| WS_VISIBLE);
        win15.AddExStyle(WS_EX_APPWINDOW);
        win15.AddParent(win.getHWND());
        win15.SetPosition(rcDisplay.left , rcDisplay.top ,rcDisplay.right, rcDisplay.bottom);
        win15.SetWndID(ID_BOX_DISPLAY);
        win15.Create();

        ///BUTTONS
        int x0=40,y0=50;

         ///BUTTON CANCEL
        WinMaker win16("BUTTON", hInst);
        win16.AddCaption("Cancel");
        win16.AddStyle(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
        win16.AddParent(win.getHWND());
        win16.SetPosition(x0+95,y0+180,70,20);
        win16.SetWndID(IDB_CANCEL);
        win16.Create();

        ///BUTTON OK
        WinMaker win17("BUTTON", hInst);
        win17.AddCaption("ok");
        win17.AddStyle(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
        win17.AddParent(win.getHWND());
        win17.SetPosition(x0+60,y0+60,40,20);
        win17.SetWndID(IDB_OK);
        win17.Create();

        ///BUTTON CLEAR
        WinMaker win18("BUTTON", hInst);
        win18.AddCaption("Clear");
        win18.AddStyle(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
        win18.AddParent(win.getHWND());
        win18.SetPosition( x0+105,y0+60,50,20);
        win18.SetWndID(IDB_CLEAR);
        win18.Create();

        ///BUTTON 0
        WinMaker win19("BUTTON", hInst);
        win19.AddCaption("0");
        win19.AddStyle(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
        win19.AddParent(win.getHWND());
        win19.SetPosition(x0+160,y0+60,40,20);
        win19.SetWndID(IDB_B0);
        win19.Create();

        ///BUTTON 1
        WinMaker win20("BUTTON", hInst);
        win20.AddCaption("1");
        win20.AddStyle(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
        win20.AddParent(win.getHWND());
        win20.SetPosition(x0+60,y0+90,40,20);
        win20.SetWndID(IDB_B1);
        win20.Create();

        ///BUTTON 2
        WinMaker win21("BUTTON", hInst);
        win21.AddCaption("2");
        win21.AddStyle(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
        win21.AddParent(win.getHWND());
        win21.SetPosition(x0+110,y0+90,40,20);
        win21.SetWndID(IDB_B2);
        win21.Create();

         ///BUTTON 3
        WinMaker win22("BUTTON", hInst);
        win22.AddCaption("3");
        win22.AddStyle(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
        win22.AddParent(win.getHWND());
        win22.SetPosition(x0+160,y0+90,40,20);
        win22.SetWndID(IDB_B3);
        win22.Create();

         ///BUTTON 4
        WinMaker win23("BUTTON", hInst);
        win23.AddCaption("4");
        win23.AddStyle(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
        win23.AddParent(win.getHWND());
        win23.SetPosition(x0+60,y0+120,40,20);
        win23.SetWndID(IDB_B4);
        win23.Create();

         ///BUTTON 5
        WinMaker win24("BUTTON", hInst);
        win24.AddCaption("5");
        win24.AddStyle(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
        win24.AddParent(win.getHWND());
        win24.SetPosition(x0+110,y0+120,40,20);
        win24.SetWndID(IDB_B5);
        win24.Create();

         ///BUTTON 6
        WinMaker win25("BUTTON", hInst);
        win25.AddCaption("6");
        win25.AddStyle(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
        win25.AddParent(win.getHWND());
        win25.SetPosition(x0+160,y0+120,40,20);
        win25.SetWndID(IDB_B6);
        win25.Create();

         ///BUTTON 7
        WinMaker win26("BUTTON", hInst);
        win26.AddCaption("7");
        win26.AddStyle(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
        win26.AddParent(win.getHWND());
        win26.SetPosition(x0+60,y0+150,40,20);
        win26.SetWndID(IDB_B7);
        win26.Create();

         ///BUTTON 8
        WinMaker win27("BUTTON", hInst);
        win27.AddCaption("8");
        win27.AddStyle(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
        win27.AddParent(win.getHWND());
        win27.SetPosition(x0+110,y0+150,40,20);
        win27.SetWndID(IDB_B8);
        win27.Create();

         ///BUTTON 9
        WinMaker win28("BUTTON", hInst);
        win28.AddCaption("9");
        win28.AddStyle(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
        win28.AddParent(win.getHWND());
        win28.SetPosition(x0+160,y0+150,40,20);
        win28.SetWndID(IDB_B9);
        win28.Create();

         ///BUTTON LEFT 1
        WinMaker win29("BUTTON", hInst);
        win29.AddStyle(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
        win29.AddParent(win.getHWND());
        win29.SetPosition(rcDisplay.left - 60, rcDisplay.top + 140,30,30);
        win29.SetWndID(IDB_LEFT1);
        win29.Create();

         ///BUTTON LEFT 2
        WinMaker win30("BUTTON", hInst);
        win30.AddStyle(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
        win30.AddParent(win.getHWND());
        win30.SetPosition(rcDisplay.left - 60, rcDisplay.top + 210,30,30);
        win30.SetWndID(IDB_LEFT2);
        win30.Create();

         ///BUTTON LEFT 3
        WinMaker win31("BUTTON", hInst);
        win31.AddStyle(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
        win31.AddParent(win.getHWND());
        win31.SetPosition(rcDisplay.left - 60, rcDisplay.top + 280,30,30);
        win31.SetWndID(IDB_LEFT3);
        win31.Create();

         ///BUTTON LEFT 4
        WinMaker win32("BUTTON", hInst);
        win32.AddStyle(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
        win32.AddParent(win.getHWND());
        win32.SetPosition(rcDisplay.left - 60, rcDisplay.top + 350,30,30);
        win32.SetWndID(IDB_LEFT4);
        win32.Create();

         ///BUTTON RIGHT 1
        WinMaker win33("BUTTON", hInst);
        win33.AddStyle(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
        win33.AddParent(win.getHWND());
        win33.SetPosition(rcDisplay.left + 540 + 30, rcDisplay.top + 140,30,30);
        win33.SetWndID(IDB_RIGHT1);
        win33.Create();

         ///BUTTON RIGHT 2
        WinMaker win34("BUTTON", hInst);
        win34.AddStyle(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
        win34.AddParent(win.getHWND());
        win34.SetPosition( rcDisplay.left + 540 + 30, rcDisplay.top + 210,30,30);
        win34.SetWndID(IDB_RIGHT2);
        win34.Create();

         ///BUTTON RIGHT 3
        WinMaker win35("BUTTON", hInst);
        win35.AddStyle(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
        win35.AddParent(win.getHWND());
        win35.SetPosition( rcDisplay.left + 540 + 30, rcDisplay.top + 280,30,30);
        win35.SetWndID(IDB_RIGHT3);
        win35.Create();

         ///BUTTON RIGHT 4
        WinMaker win36("BUTTON", hInst);
        win36.AddStyle(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
        win36.AddParent(win.getHWND());
        win36.SetPosition( rcDisplay.left + 540 + 30, rcDisplay.top + 350,30,30);
        win36.SetWndID(IDB_RIGHT4);
        win36.Create();

          ///  !!!!! DACA FOLOSESTI win.Show(cmdShow); dupa crearea ferestrei principale, se trimite WM_PAINT
          ///         si programul nu va stii nimic de copiii ferestrei principale   (so... headache :(    )


        win.Show(SW_MAXIMIZE);
        win1.Show(cmdShow);

        ///STATIC BOX  (STATEMENT OF ACCOUNT)
        win2.Show(SW_HIDE);

        win3.Show(cmdShow);
        win4.Show(cmdShow);
        win5.Show(cmdShow);

        win6.Show(SW_HIDE);
        win7.Show(SW_HIDE);
        win8.Show(SW_HIDE);
        win9.Show(SW_HIDE);
        win10.Show(SW_HIDE);

        win11.Show(cmdShow);
        win12.Show(cmdShow);
        win13.Show(cmdShow);
        win14.Show(cmdShow);
        win15.Show(cmdShow);
        win16.Show(cmdShow);
        win17.Show(cmdShow);
        win18.Show(cmdShow);
        win19.Show(cmdShow);
        win20.Show(cmdShow);
        win21.Show(cmdShow);
        win22.Show(cmdShow);
        win23.Show(cmdShow);
        win24.Show(cmdShow);
        win25.Show(cmdShow);
        win26.Show(cmdShow);
        win27.Show(cmdShow);
        win28.Show(cmdShow);
        win29.Show(cmdShow);
        win30.Show(cmdShow);
        win31.Show(cmdShow);
        win32.Show(cmdShow);
        win33.Show(cmdShow);
        win34.Show(cmdShow);
        win35.Show(cmdShow);
        win36.Show(cmdShow);

        ///The main message loop
        MSG messages;
        while(::GetMessage( &messages, NULL, 0, 0))
        {
            /* Translate virtual-key messages into character messages */
            ::TranslateMessage(&messages);
            /* Send message to WindowProcedure */
            ::DispatchMessage(&messages);
        }

        return messages.wParam;

    return 0;
}
