#include "Controller.h"

#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <mmsystem.h>

template <class T>   ///Retrieves information about the specified window. The function also retrieves the value at a specified offset into the extra window memory.
inline T WinGetLong(HWND hwnd, int which = GWL_USERDATA)
{
    return reinterpret_cast<T>(::GetWindowLong(hwnd, which));
}

template <class T>   ///Changes an attribute of the specified window. The function also sets a value at the specified offset in the extra window memory.
inline void WinSetLong(HWND hwnd, T value, int which = GWL_USERDATA)
{
    ::SetWindowLong(hwnd, which, reinterpret_cast<long>(value));
}

Controller::Controller(HWND hwnd, CREATESTRUCT *pCreate): _hwnd(hwnd),_model("Generic")
{
     _cursorState = 0;
     _statementActive = 0;
     _trayActive = 0;
     _anotherSum = 0;
     _nrTries = 0;
}
Controller::~Controller()
{
    ::PostQuitMessage(0);
}

void Controller::Size(int cx, int cy)
{
    _view.SetSize(cx, cy);
}
void Controller::PaintDC(int ID, int number=0)
{
    if(number == 0)
        _view.PaintDC(_hwnd, _model, ID);
    else
        _view.PaintDC(_hwnd, _model, ID, number);
}
void Controller::Paint()
{
    _view.Paint(_hwnd, _model);
}

void Controller::LoadImages(HINSTANCE hInst)
{
    _view.SetInst(hInst);
    _view.LoadBitmaps();
    _view.LoadCursors();
}
void Controller::TextExD(const char* DText, int i, int x)
{
    switch(_banknote)
    {
        case 10:
            i=1;
        break;
        case 50:
            i=2;
        break;
        case 100:
            i=3;
        break;
        case 200:
            i=4;
        break;
        case 500:
            i=5;
        break;
    }
    if(strlen(DText)>0)
         {
             _step = _model.getKey(DText);
             _model.SetDisplayText(DText, '0' + i, x);
         }
}

void Controller::TextExD(const char* DText, char ch)
{
    if(strlen(DText)>0)
         {
             _step = _model.getKey(DText);
             _model.SetDisplayText(DText, ch);
         }
}

void Controller::TextExD(const char* DText, string s)
{
    if(strlen(DText)>0)
         {
             _step = _model.getKey(DText);
             _model.SetDisplayText(DText, 0, 0, s);
         }
}

void Controller::TextExD(const char* DText,string fn, string ln, string acc, int PIN, int sum)
{
    if(strlen(DText)>0)
         {
             _step = _model.getKey(DText);
             _model.SetDisplayText(DText, 0, 0, fn, ln, acc, PIN, sum);
         }
}

void Controller::TextExD(const char* DText, int number)
{
    if(strlen(DText)>0)
         {
             _step = _model.getKey(DText);
             _model.SetDisplayText(DText, '0', number);
         }
}

void Controller::Text(const char* DText, const char* SText)
{
    if(strlen(DText)>0)
         {
             _step = _model.getKey(DText);
             _model.SetDisplayText(DText);
         }
    if(strlen(SText)>0)
         {
             _model.SetStatementText(SText, log.showTransInfo(account->getAccNr()));
         }
}

void Controller::ChangeCursorIcon()
{
                /*RECT rc;
                POINT pos;*/

                ::GetCursorPos(&pos);
                rc  = GetLocalCoordinates(ID_BOX_CARD);

                if( ( (pos.x <= (rc.right - 105)) && (pos.x >= (rc.left + 105)))   &&    (pos.y == (rc.bottom - (rc.bottom - rc.top)/2 + 193)) )
                            {
                               ::PlaySound("sounds\\card1.wav", NULL, SND_FILENAME | SND_ASYNC );
                                if( getCursorState() == 1)
                                       ::SetTimer(_hwnd, ID_TIMER2, 2000, (TIMERPROC) NULL);
                                if( getCursorState() == 2)
                                       ::SetTimer(_hwnd, ID_TIMER3, 2000, (TIMERPROC) NULL);
                                _cursorState = 0;
                                HCURSOR hcursor = ::LoadCursor(NULL, IDC_HAND);
                                ::SetClassLong(_hwnd,  GCL_HCURSOR,(LONG) hcursor);
                            }
}

///Menu command processing
void Controller::InitiateBank()
{
    string acc = "4675675655675655";                   ///Contul corespunzator cardului( prestabilit de mine )
    bank.initBank();                                   ///Se introduc toate datele din fisierul bank.txt in obiectul bank;
    person = bank.getPerson(acc);                      ///se preiau datele persoanei de la banca
    account = &person.getAccount();                    ///se seteaza un pointer care preia datele contului persoanei
    ///!!!Nu am verificat daca exista numarul de cont; Am presupus ca exista
}

void Controller::SettingPIN(int cmd)
{
    switch(cmd)
        {
            case IDB_CANCEL:
            {
                 Text("GoodBye", "");
                 PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_CLEAR:
            {
                Text("SetPIN", "");
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_OK:
            {

            }
            break;

            case IDB_B0:
            {
                TextExD("SetPINEx", '0');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B1:
            {
                TextExD("SetPINEx", '1');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B2:
            {
                TextExD("SetPINEx", '2');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B3:
            {
                TextExD("SetPINEx", '3');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B4:
            {
                TextExD("SetPINEx", '4');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B5:
            {
                TextExD("SetPINEx", '5');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B6:
            {
                TextExD("SetPINEx", '6');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B7:
            {
                TextExD("SetPINEx", '7');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B8:
            {
                TextExD("SetPINEx", '8');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B9:
            {
                TextExD("SetPINEx", '9');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;
        }
    if(_model.getPos() == 4)
        {
         if(_model.getPIN() == account->getPIN())
            {
                log.prepareForTransactions(account->getAccNr()); ///Scrie in logger.txt linia de separatie si numarul de cont
                log.itotalCashAmount(cashd.totalCashAmount());    ///Scrie in logger.txt suma initiala din bancomat

                Text("Menu", "");
                PaintDC(ID_BOX_DISPLAY);
            }
            else
                {_nrTries++;
                if( _nrTries == 3 )
                    {Text("CardBlocked", "");
                    PaintDC(ID_BOX_DISPLAY);}
                else
                    {TextExD("SetPIN", '1');      ///'1' for Wrong PIN warning
                    PaintDC(ID_BOX_DISPLAY);}}
        }
}

void Controller::ExecuteWithdraw( int _sum_ )
{
                trans = new ValidateAmount();
                if( trans->ExecuteTransaction( _sum_, account))
                   if(cashd.CheckForExistence( _sum_ ))          ///daca exista suficienti bani in cont si sufiecienti bani in bancomat
                        {
                                ::PlaySound("sounds\\cash_drawer_receipt.wav", NULL, SND_FILENAME | SND_SYNC );

                                trans = new Withdraw();
                                trans->ExecuteTransaction( _sum_, account);

                                cashd.Withdraw(_sum_);
                                bank.savePersonData(person);                          ///modifica datele persoanei in baza de date a bancii

                                log.printTransaction( _sum_, "Withdraw" );
                                log.printBanknotesStatus( cashd.getBanknotesValues(), cashd.getBanknotesNr());

                                for(int i=0; i<5; i++)
                                {
                                    switch(cashd.NrBanknotes(i))   ///returneaza sol[i] din cash dispenser
                                        {
                                        case 0:

                                        break;

                                        case 1:
                                             {
                                                 PaintDC(ID_BOX_CASHOUT, i*5 + 1);     ///*5 pentru a sti ce tip de bancnota am in view
                                                 i=5;
                                             }
                                        break;

                                        case 2:
                                             {
                                                 PaintDC(ID_BOX_CASHOUT, i*5 + 2);
                                                 i=5;
                                             }
                                        break;

                                        default:
                                             {
                                                 PaintDC(ID_BOX_CASHOUT, i*5 + 3);
                                                 i=5;
                                             }
                                        }
                                }

                                bank.saveChanges();                                   ///salveaza in fisier datele din baza de date a bancii

                                cashd.saveValues();                                    ///se actualizeaza numarul fiecarui tip de bancnota
                                log.ftotalCashAmount(cashd.totalCashAmount());


                                Text("Success", "");
                                PaintDC(ID_BOX_DISPLAY);
                        }
                        else
                        {
                            ::PlaySound("sounds\\fins_failure.wav", NULL, SND_FILENAME | SND_ASYNC );
                            if( _sum_%10 != 0 )
                                {
                                    Text("WrongValue","");
                                    PaintDC(ID_BOX_DISPLAY);
                                }
                            else
                                {
                                    Text("FailureAtm", "");
                                    PaintDC(ID_BOX_DISPLAY);
                                    log.printLackOfFunds(cashd.getBanknotesValues(), cashd.getBanknotesNr());
                                }
                        }
                    else
                        {
                                ::PlaySound("sounds\\fins_failure.wav", NULL, SND_FILENAME | SND_ASYNC );
                                Text("FailureAcc", "");
                                PaintDC(ID_BOX_DISPLAY);
                        }
                _trayActive = 1;
}

void Controller::SettingWithdrawSum(int cmd)
{
    if(_anotherSum == 0)
    {
        switch(cmd)
        {
               case IDB_LEFT1:   ///10
                       ExecuteWithdraw(10);
               break;

               case IDB_LEFT2:    ///50
                       ExecuteWithdraw(50);
               break;

               case IDB_LEFT3:    ///100
                       ExecuteWithdraw(100);
               break;

               case IDB_LEFT4:    ///200
                       ExecuteWithdraw(200);
               break;

               case IDB_RIGHT1:   ///300
                       ExecuteWithdraw(300);
               break;

               case IDB_RIGHT2:   ///500
                       ExecuteWithdraw(500);
               break;

               case IDB_RIGHT3:   ///1000
                       ExecuteWithdraw(1000);
               break;

               case IDB_RIGHT4:   ///another sum
                       _anotherSum = 1;
                       TextExD("SetSumEx", ' ');
                       PaintDC(ID_BOX_DISPLAY);
               break;
        }
    }
    if(_anotherSum == 1)
    {
        switch(cmd)
        {
            case IDB_CANCEL:
            {
                 _anotherSum = 0;
                 Text("Menu", "");
                 PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_CLEAR:
            {
                 TextExD("SetSumEx", ' ');
                 PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_OK:
            {
                 ExecuteWithdraw(_model.getSum());
            }
            break;

            case IDB_B0:
            {
                TextExD("SetSumEx", '0');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B1:
            {
                TextExD("SetSumEx", '1');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B2:
            {
                TextExD("SetSumEx", '2');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B3:
            {
                TextExD("SetSumEx", '3');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B4:
            {
                TextExD("SetSumEx", '4');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B5:
            {
                TextExD("SetSumEx", '5');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B6:
            {
                TextExD("SetSumEx", '6');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B7:
            {
                TextExD("SetSumEx", '7');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B8:
            {
                TextExD("SetSumEx", '8');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B9:
            {
                TextExD("SetSumEx", '9');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;
        }
    }
}

void Controller::MouseMove()
{
    if(getCursorState())
        {
         ChangeCursorIcon();
         if(getCursorState()==0)
             {
                  Text("PleaseWait", "");
                  PaintDC(ID_BOX_DISPLAY);
             }
        }
     else
            if( _step == _model.getKey("Deposit") || _step == _model.getKey("CashAdded") )
            {
                 if((LONG)::GetCursor() != (LONG) ::LoadCursor(NULL, IDC_HAND))
                    {
                    /*RECT rc;
                    POINT pos;*/

                    ::GetCursorPos(&pos);
                    rc  = GetLocalCoordinates(ID_BOX_CASHIN);

                    if( ( (pos.x <= (rc.right - 100)) && (pos.x >= (rc.left + 100)))   &&    (pos.y == (rc.bottom - (rc.bottom - rc.top)/2 + 115)) )
                         {
                         ::PlaySound("sounds\\cash_in.wav", NULL, SND_FILENAME | SND_ASYNC );
                         ResetCursor();
                         cashd.AddCash(_banknote, 1);

                         trans = new Deposit();
                         trans->ExecuteTransaction(_banknote * 1, account);

                         bank.savePersonData(person);
                         bank.saveChanges();

                         log.printTransaction( _banknote * 1, "Deposit" );

                         TextExD("CashAdded", _banknote, account->getSum());
                         PaintDC(ID_BOX_DISPLAY);
                         }
                    }
            }
}

void Controller::SettingAddSum(int cmd)
{
    /// no need of this or not entirely maybe, we need images and the text on the screen showing how much and type has been added
    switch(cmd)
        {
            case IDB_CANCEL:
            case IDB_CLEAR:
            case IDB_OK:
            {
                Text("Menu", "");
                PaintDC(ID_BOX_DISPLAY);
                cashd.saveValues();
                log.ftotalCashAmount(cashd.totalCashAmount());
                log.printBanknotesStatus( cashd.getBanknotesValues(), cashd.getBanknotesNr());

                ShowWindow(GetDlgItem(_hwnd, ID_BOX_CASH10  ),  SW_HIDE);
                ShowWindow(GetDlgItem(_hwnd, ID_BOX_CASH50  ),  SW_HIDE);
                ShowWindow(GetDlgItem(_hwnd, ID_BOX_CASH100 ),  SW_HIDE);
                ShowWindow(GetDlgItem(_hwnd, ID_BOX_CASH200 ),  SW_HIDE);
                ShowWindow(GetDlgItem(_hwnd, ID_BOX_CASH500 ),  SW_HIDE);
            }
            break;
        }
}

void Controller::Menu(int cmd)
{
    switch(cmd)
        {
            case IDB_LEFT1:
                Text("SetSum","");
                PaintDC(ID_BOX_DISPLAY);
            break;
            case IDB_LEFT2:
                Text("Deposit", "");
                PaintDC(ID_BOX_DISPLAY);
                ShowWindow(GetDlgItem(_hwnd, ID_BOX_CASH10  ),  SW_SHOW);
                ShowWindow(GetDlgItem(_hwnd, ID_BOX_CASH50  ),  SW_SHOW);
                ShowWindow(GetDlgItem(_hwnd, ID_BOX_CASH100 ),  SW_SHOW);
                ShowWindow(GetDlgItem(_hwnd, ID_BOX_CASH200 ),  SW_SHOW);
                ShowWindow(GetDlgItem(_hwnd, ID_BOX_CASH500 ),  SW_SHOW);
            break;
            case IDB_LEFT3:
                TextExD("AmOfCash", account->getSum());
                PaintDC(ID_BOX_DISPLAY);
            break;

            case IDB_LEFT4:
                if( _statementActive == 0 )
                    {::PlaySound("sounds\\button.wav", NULL, SND_FILENAME | SND_SYNC );
                     ::PlaySound("sounds\\receipt.wav", NULL, SND_FILENAME | SND_ASYNC );
                     Text("","Statement");
                     PaintDC(ID_BOX_STATIC);
                     _statementActive = 1;
                     ShowWindow(GetDlgItem(_hwnd, ID_BOX_STATIC),  SW_SHOW);}
            break;
            case IDB_RIGHT1:
                Text("GoodBye", "");
                PaintDC(ID_BOX_DISPLAY);
            break;
            case IDB_RIGHT2:
            break;
            case IDB_RIGHT3:
            break;
            case IDB_RIGHT4:
            break;
        }
}

void Controller::Interrogate(int cmd)
{
    switch(cmd)
    {
        case IDB_LEFT1:
        {

             log.printTransaction( 0, "InquireBalance" );
             log.printBanknotesStatus( cashd.getBanknotesValues(), cashd.getBanknotesNr());

             Text("Menu","");
             PaintDC(ID_BOX_DISPLAY);

        }
        break;

        case IDB_LEFT2:
        {
             log.printTransaction( 0, "InquireBalance" );
             log.printBanknotesStatus( cashd.getBanknotesValues(), cashd.getBanknotesNr());

             Text("GoodBye", "");
             PaintDC(ID_BOX_DISPLAY);

        }
        break;
    }
}

void Controller::HideStatement()
{
    _statementActive = 0;
    ShowWindow(GetDlgItem(_hwnd, ID_BOX_STATIC), SW_HIDE);
}

void Controller::SetNumberOfBanknotes(int cmd)
{
    switch(cmd)
        {
            case IDB_CANCEL:
            {
                 TextExD("SelectTypeOfBanknote", ' ');
                 PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_CLEAR:
            {
                 TextExD("IntroduceNrOfBanknotes",' ');
                 PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_OK:
            {
                if(!cashd.AddCash(_banknote, _model.getSum()))
                     ::MessageBox(NULL, "Failed to add cash", "Error", MB_ICONERROR | MB_OK);
                else
                    {
                        cashd.saveValues();
                        log.ftotalCashAmount(cashd.totalCashAmount());
                    }

                TextExD("SelectTypeOfBanknote", ' ');
                PaintDC(ID_BOX_DISPLAY);

            }
            break;

            case IDB_B0:
            {
                TextExD("IntroduceNrOfBanknotes",'0');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B1:
            {
                TextExD("IntroduceNrOfBanknotes",'1');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B2:
            {
                TextExD("IntroduceNrOfBanknotes", '2');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B3:
            {
                TextExD("IntroduceNrOfBanknotes", '3');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B4:
            {
                TextExD("IntroduceNrOfBanknotes", '4');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B5:
            {
                TextExD("IntroduceNrOfBanknotes", '5');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B6:
            {
                TextExD("IntroduceNrOfBanknotes", '6');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B7:
            {
                TextExD("IntroduceNrOfBanknotes", '7');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B8:
            {
                TextExD("IntroduceNrOfBanknotes", '8');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B9:
            {
                TextExD("IntroduceNrOfBanknotes", '9');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;
        }
}

void Controller::PrintClients(int z)
{
             int i=0;

             switch(z)
             {
                   case 1:
                   {
                       if( _pairIt.first != _pairIt.second )
                         {
                             if( _counter == -1)
                                 {_pairIt = bank.getIterators();}

                             it[ ++_counter ] = _pairIt.first;
                             for(i=0 ; _pairIt.first != _pairIt.second  && i < 15; ++(_pairIt.first), ++i)
                             {
                                   Account _account=(*(_pairIt.first)).second.getAccount();

                                   TextExD("ShowClientsEx",(*(_pairIt.first)).second.getFN(), (*(_pairIt.first)).second.getLN(),
                                         _account.getAccNr(), _account.getPIN(), _account.getSum());
                              }

                              if(i<15)
                                  {for(;i < 15; ++i)
                                  _model.SetExDText("NewLine");}


                              _model.SetExDText("ShowClientsEx");  ///text pentru next si previous

                              PaintDC(ID_BOX_DISPLAY);
                         }
                         else
                             Text("ShowClientsEx","");
                    }
                    break;

                    case -1:
                    {
                        if( _counter >= 1)
                        {

                              _pairIt.first = it[ --_counter ];

                             for(i=0 ; _pairIt.first != _pairIt.second  && i < 15; ++(_pairIt.first), ++i)
                             {
                                  Account _account=(*(_pairIt.first)).second.getAccount();

                                  TextExD("ShowClientsEx",(*(_pairIt.first)).second.getFN(), (*(_pairIt.first)).second.getLN(),
                                         _account.getAccNr(), _account.getPIN(), _account.getSum());
                             }

                             if(i<15)
                                    {for(;i < 15; ++i)
                                    _model.SetExDText("NewLine");}

                             _model.SetExDText("ShowClientsEx");  ///text pentru next si previous

                             PaintDC(ID_BOX_DISPLAY);
                         }
                         else
                             Text("ShowClientsEx","");
                    }
                     break;
             }
}

void Controller::PrintLoggerFile(int z)
{
             int i=0;

             switch(z)
             {
                   case 1:
                   {
                          if(_counter < log.getLimitTransATM())
                             {
                                 _counter += 15;
                                 for(i=_counter - 15;  i < _counter && i < log.getLimitTransATM() ;  ++i)
                                 {
                                      TextExD("ShowLoggerFileEx",log.getTransATM(i));
                                 }

                                 for(; i%15 != 0 || i==0; ++i)
                                 {
                                     _model.SetExDText("NewLine");
                                 }

                                 _model.SetExDText("ShowLoggerFileEx");  ///text pentru next si previous

                                 PaintDC(ID_BOX_DISPLAY);
                             }
                           else
                                TextExD("ShowLoggerFileEx",' ');


                   }
                   break;

                    case -1:
                    {

                        if( _counter - 15 > 0)
                        {
                            _counter -= 15;

                             for(i=_counter - 15;  i < _counter && i < log.getLimitTransATM();  ++i)
                             {
                                   TextExD("ShowLoggerFileEx",log.getTransATM(i));
                             }

                             for(; i%15 != 0 || i==0; ++i)
                             {
                                 _model.SetExDText("NewLine");
                             }

                             _model.SetExDText("ShowLoggerFileEx");  ///text pentru next si previous

                             PaintDC(ID_BOX_DISPLAY);
                        }
                        else
                             TextExD("ShowLoggerFileEx",' ');


                    }
                     break;
             }


}

void Controller::SettingPINAdmin(int cmd)
{
    switch(cmd)
        {
            case IDB_CANCEL:
            {
                 Text("GoodBye", "");
                 PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_CLEAR:
            {
                Text("SetPINAdmin", "");
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B0:
            {
                TextExD("SetPINAdminEx", '0');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B1:
            {
                TextExD("SetPINAdminEx", '1');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B2:
            {
                TextExD("SetPINAdminEx", '2');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B3:
            {
                TextExD("SetPINAdminEx", '3');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B4:
            {
                TextExD("SetPINAdminEx", '4');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B5:
            {
                TextExD("SetPINAdminEx", '5');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B6:
            {
                TextExD("SetPINAdminEx", '6');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B7:
            {
                TextExD("SetPINAdminEx", '7');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B8:
            {
                TextExD("SetPINAdminEx", '8');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;

            case IDB_B9:
            {
                TextExD("SetPINAdminEx", '9');
                PaintDC(ID_BOX_DISPLAY);
            }
            break;
        }
    if(_model.getPos() == 4)
        {
         if(_model.getPIN() == admin.getPIN())
            {
                Text("AdminMenu", "");
                PaintDC(ID_BOX_DISPLAY);
            }
          else
                {_nrTries++;
                if( _nrTries == 3 )
                    {Text("CardBlocked", "");
                    PaintDC(ID_BOX_DISPLAY);}
                else
                    {TextExD("SetPINAdmin", '1'); ///'1' for Wrong PIN warning
                    PaintDC(ID_BOX_DISPLAY);}}
        }
}

void Controller::Command(int cmd)
{
    switch(cmd)
                {
                      case IDM_EXIT:
                              ::PlaySound("sounds\\button2.wav", NULL, SND_FILENAME | SND_ASYNC );
                              ::PostQuitMessage(0);
                      break;

                      case IDM_HELP:
                              ::PlaySound("sounds\\button2.wav", NULL, SND_FILENAME | SND_ASYNC );
                              ::MessageBox(_hwnd, "Yeah, sure: go figure!", "Helper", MB_ICONINFORMATION | MB_OK);
                      break;

                      case IDM_ABOUT:
                      {
                              ///Instance handle is available through HWND
                              ::PlaySound("sounds\\button2.wav", NULL, SND_FILENAME | SND_ASYNC );
                              HINSTANCE hInst = WinGetLong<HINSTANCE>(_hwnd, GWL_HINSTANCE);
                              ::DialogBox(hInst,
                                          MAKEINTRESOURCE(IDD_ABOUT),
                                          _hwnd,
                                          AboutDlgProc);
                      }
                      break;
                      case IDM_PIN:
                      {
                              ::PlaySound("sounds\\button2.wav", NULL, SND_FILENAME | SND_ASYNC );
                              ::MessageBox(_hwnd, "Client PIN: 6799\nAdminitstrator PIN: 0000", "PINs", MB_ICONINFORMATION | MB_OK);
                      }
                      default:
                          ::PlaySound("sounds\\button.wav", NULL, SND_FILENAME | SND_ASYNC );
                }

    switch( _step )
    {
         case 19:    ///SetPIN
         case 32:    ///SetPINEx
              SettingPIN(cmd);
         break;

         case 3:      ///Menu
              Menu(cmd);
         break;

         case 17:     ///SetSum
         case 33:     ///SetSumEx
              SettingWithdrawSum(cmd);
         break;

         case 7:     ///FailureAtm
              switch(cmd)
                    {
                    case IDB_LEFT1:
                            Text("GoodBye", "");
                            PaintDC(ID_BOX_DISPLAY);
                    break;
                    case IDB_RIGHT1:
                            Text("Menu", "");
                            PaintDC(ID_BOX_DISPLAY);
                    break;
                    }
         break;

         case 8:     ///FailureAcc
         case 36:    ///WrongValue
              switch(cmd)
              {
                    case IDB_LEFT1:
                            Text("GoodBye", "");
                            PaintDC(ID_BOX_DISPLAY);
                    break;

                    case IDB_RIGHT1:
                            Text("Menu", "");
                            PaintDC(ID_BOX_DISPLAY);
                    break;
              }
         break;

         case 34:      ///Deposit
         case 26:      ///CashAdded
              SettingAddSum(cmd);
         break;

         case 5:       ///AmountOfCash
              Interrogate(cmd);
         break;

         case 37:    ///Select Client or Admin
              switch(cmd)
              {
                    case IDB_LEFT1:
                        Text("InsertCard", "");
                        PaintDC(ID_BOX_DISPLAY);
                        _view.setCursor(ID_ICO_CLIENTCARD);
                        _cursorState = 1;
                    break;

                    case IDB_LEFT2:
                        Text("InsertCard", "");
                        PaintDC(ID_BOX_DISPLAY);
                        _view.setCursor(ID_ICO_ADMINCARD);
                        _cursorState = 2;
                    break;
              }
         break;

         case 38:      ///Admin Menu
             switch(cmd)
              {
                    case IDB_LEFT1:
                        Text("ShowClients","");
                        _counter = -1;
                        _pairIt = bank.getIterators();   ///setting the pair of iterators use to iterate through the bank data
                        PrintClients(1);

                    break;

                    case IDB_LEFT2:
                        TextExD("SelectTypeOfBanknote", ' ');
                        PaintDC(ID_BOX_DISPLAY);
                    break;

                    case IDB_LEFT3:
                        Text("ShowLoggerFile","");
                        _counter = 0;
                        log.loadTransInfoATM();
                        PrintLoggerFile(1);

                    break;

                    case IDB_LEFT4:
                         TextExD("BanknotesStatusATM", 0, cashd.totalCashAmount());
                         TextExD("BanknotesStatusATM", 1, cashd.getBanknotesNrATM(4));
                         TextExD("BanknotesStatusATM", 2, cashd.getBanknotesNrATM(3));
                         TextExD("BanknotesStatusATM", 3, cashd.getBanknotesNrATM(2));
                         TextExD("BanknotesStatusATM", 4, cashd.getBanknotesNrATM(1));
                         TextExD("BanknotesStatusATM", 5, cashd.getBanknotesNrATM(0));

                         PaintDC(ID_BOX_DISPLAY);
                    break;
              }
         break;

         case 39:          ///"SelectTypeOfBanknote"
                switch(cmd)
                {
                    case IDB_LEFT1:
                        TextExD("IntroduceNrOfBanknotes",' ');
                        PaintDC(ID_BOX_DISPLAY);
                        _banknote = 10;
                    break;

                    case IDB_LEFT2:
                        TextExD("IntroduceNrOfBanknotes",' ');
                        PaintDC(ID_BOX_DISPLAY);
                        _banknote = 50;
                    break;

                    case IDB_LEFT3:
                        TextExD("IntroduceNrOfBanknotes",' ');
                        PaintDC(ID_BOX_DISPLAY);
                        _banknote = 100;
                    break;

                    case IDB_LEFT4:
                        TextExD("IntroduceNrOfBanknotes",' ');
                        PaintDC(ID_BOX_DISPLAY);
                        _banknote = 200;
                    break;

                    case IDB_RIGHT1:
                        TextExD("IntroduceNrOfBanknotes",' ');
                        PaintDC(ID_BOX_DISPLAY);
                        _banknote = 500;
                    break;

                    case IDB_RIGHT4:
                        Text("AdminMenu", "");
                        PaintDC(ID_BOX_DISPLAY);
                    break;
                }
         break;

         case 40:   ///Selecting the number of banknotes(comes after SelectBanknotes)
                SetNumberOfBanknotes(cmd);
         break;

         case 42:     ///ShowClientsEx
             switch(cmd)
             {
                   case IDB_CANCEL:
                   {
                        Text("AdminMenu", "");
                        PaintDC(ID_BOX_DISPLAY);
                   }
                   break;
                   case IDB_LEFT4:   ///NEXT
                       Text("ShowClients","");
                       PrintClients(1);
                   break;

                   case IDB_RIGHT4:   ///PREVIOUS
                       Text("ShowClients","");
                       PrintClients(-1);
                   break;
             }
         break;
         case 43:    ///Number of Banknotes of each type in the ATM, and the total cash amount in the ATM
              Text("AdminMenu", "");
              PaintDC(ID_BOX_DISPLAY);
         break;

          case 45:     ///ShowLoggerFileEx
             switch(cmd)
             {
                   case IDB_CANCEL:
                   {
                        Text("AdminMenu", "");
                        PaintDC(ID_BOX_DISPLAY);
                   }
                   break;
                   case IDB_LEFT4:   ///NEXT
                       Text("ShowLoggerFile","");
                       PrintLoggerFile(1);
                   break;

                   case IDB_RIGHT4:   ///PREVIOUS
                       Text("ShowLoggerFile","");
                       PrintLoggerFile(-1);
                   break;
             }
         break;

         case 46:   //"SetPINAdmin"
         case 47:   //"SetPINAdminEx"
              SettingPINAdmin(cmd);
         break;
    }
}

RECT Controller::GetLocalCoordinates(int item_id)
{
    //RECT rc;
    ::GetClientRect(::GetDlgItem(_hwnd, item_id), &rc);
    ::MapWindowPoints(::GetDlgItem(_hwnd, item_id),_hwnd ,(LPPOINT)&rc,2);

    ///rc contine coordonatele ferestrei( 2 puncte: sus,stanga; jos,dreapta )
    return rc;
}

void Controller::ChooseCashIcon()
{
       /*RECT rc10;
       RECT rc50;
       RECT rc100;
       RECT rc200;
       RECT rc500;

       POINT pos;*/
       ::GetCursorPos(&pos);

       rc10  = GetLocalCoordinates(ID_BOX_CASH10);
       rc50  = GetLocalCoordinates(ID_BOX_CASH50);
       rc100 = GetLocalCoordinates(ID_BOX_CASH100);
       rc200 = GetLocalCoordinates(ID_BOX_CASH200);
       rc500 = GetLocalCoordinates(ID_BOX_CASH500);

       if( (pos.x < rc10.right && pos.x > rc10.left)   &&    (pos.y < rc10.bottom && pos.y > rc10.top) )
            {
                _view.setCursor(ID_ICO_P10);
                _banknote = 10;
            }
        else
        if( (pos.x < rc50.right && pos.x > rc50.left)   &&    (pos.y < rc50.bottom && pos.y > rc50.top) )
             {
                 _view.setCursor(ID_ICO_P50);
                 _banknote = 50;
             }
         else
         if( (pos.x < rc100.right && pos.x > rc100.left)   &&    (pos.y < rc100.bottom && pos.y > rc100.top) )
              {
                  _view.setCursor(ID_ICO_P100);
                  _banknote = 100;
              }
          else
          if( (pos.x < rc200.right && pos.x > rc200.left)   &&    (pos.y < rc200.bottom && pos.y > rc200.top) )
              {
                  _view.setCursor(ID_ICO_P200);
                  _banknote = 200;
              }
           else
           if( (pos.x < rc500.right && pos.x > rc500.left)   &&    (pos.y < rc500.bottom && pos.y > rc500.top) )
               {
                   _view.setCursor(ID_ICO_P500);
                   _banknote = 500;
               }
}

void Controller::CloseTray()
{
   /* RECT rc;
    POINT pos;*/

    ::GetCursorPos(&pos);
    rc  = GetLocalCoordinates(ID_BOX_CASHOUT);

    if( ((pos.x < rc.right - 30) && (pos.x > rc.left + 35))   &&    ((pos.y < rc.bottom + 30) && (pos.y > rc.top + 80)))
            {
               PaintDC(ID_BOX_CASHOUT);
               _trayActive = 0;
            }
}

void Controller::LButtonDOWN()
{
    if(_step == _model.getKey("Deposit") || _step == _model.getKey("CashAdded"))
          ChooseCashIcon();
    else
            if( _trayActive == 1 )
                 CloseTray();
            else
                  if(_statementActive == 1)
                      HideStatement();
}

void Controller::MakeSettings(HWND hwnd, HINSTANCE hInst)
{
    _view.SetHWND(hwnd);
    _view.SetInst(hInst);
}

void Controller::ResetCursor()
{
    _view.resetCursor();
}

void Controller::Start()
{
    Text("Welcome", "");
    PaintDC(ID_BOX_DISPLAY);
    ::SetTimer(_hwnd, ID_TIMER1, 2000, (TIMERPROC) NULL);
}

LRESULT CALLBACK MainWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    Controller *pCtrl = WinGetLong<Controller *>(hwnd);

    switch(message)
    {
    case WM_CREATE:
           {

            pCtrl = new Controller(hwnd, reinterpret_cast<CREATESTRUCT *> (lParam));
            WinSetLong<Controller *> (hwnd, pCtrl);

            HINSTANCE hInst = WinGetLong<HINSTANCE>(hwnd, GWL_HINSTANCE);

            pCtrl->MakeSettings(hwnd, hInst);
            pCtrl->InitiateBank();
            pCtrl->LoadImages(hInst);
            pCtrl->Start();

            return 0;
        }
    case WM_MOUSEMOVE:
          {
            pCtrl->MouseMove();
            return 0;
          }
    case WM_LBUTTONDOWN:
          {
            pCtrl->LButtonDOWN();
            return 0;
          }
    case WM_RBUTTONDOWN:
        {
            pCtrl->ResetCursor();
            return 0;
        }

    case WM_TIMER:
        {
            switch(wParam)
            {
                case ID_TIMER1:
                     pCtrl->Text("AdminOrCard", "");
                     pCtrl->PaintDC(ID_BOX_DISPLAY);
                     KillTimer(hwnd, ID_TIMER1);
                break;

                case ID_TIMER2:
                     pCtrl->Text("SetPIN", "");
                     pCtrl->PaintDC(ID_BOX_DISPLAY);
                     KillTimer(hwnd, ID_TIMER2);
                break;

                case ID_TIMER3:
                     pCtrl->Text("SetPINAdmin","");
                     pCtrl->PaintDC(ID_BOX_DISPLAY);
                     KillTimer(hwnd, ID_TIMER3);
                break;
            }
        }
    break;

    case WM_SIZE:
        pCtrl->Size( LOWORD(lParam), HIWORD(lParam));
        return 0;

    case WM_PAINT:
        { pCtrl->Paint();
        return 0;}

    case WM_COMMAND:
        pCtrl->Command(LOWORD(wParam));
        return 0;

    case WM_DESTROY:
        WinSetLong<Controller *>(hwnd, 0);
        delete pCtrl;
        return 0;
    }
    return ::DefWindowProc(hwnd, message, wParam, lParam);
}

///"About" dialog box procedure
///Process messages from dialog box
///Caution: use Windows BOOL, not C++ bool
BOOL CALLBACK AboutDlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
    {
    case WM_INITDIALOG:
        return TRUE;
     break;

    case WM_COMMAND:
        switch (LOWORD((wParam)))
        {
             case IDOK:
             case IDCANCEL:
                  ::PlaySound("sounds\\smart.wav", NULL, SND_FILENAME | SND_ASYNC );
                  ::EndDialog(hwnd, 0);
              return TRUE;
              break;
        }

     break;
    }
    return FALSE;
}
