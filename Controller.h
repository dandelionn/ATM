#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "main.h"
#include "View.h"
#include "Model.h"
#include "resource.h"
#include "Bitmap.h"

#include "display.h"
#include "cash_dispenser.h"
#include "logger.h"
#include "BankDB.h"
#include "person.h"
#include "account.h"
#include "Transaction.h"
#include "ValidateAmount.h"
#include "Withdraw.h"
#include "Deposit.h"
#include "Administrator.h"

class Controller{
    private:
         ///local variables
         RECT rc10;
         RECT rc50;
         RECT rc100;
         RECT rc200;
         RECT rc500;

         RECT rc;
         POINT pos;
        ///------------------

         HWND _hwnd;

         Model  _model;
         View   _view;

         int _cursorState;
         int _step;
         int _banknote;
         int _statementActive;
         int _trayActive;
         int _anotherSum;
         int _counter;
         int _nrTries;

         pair< map<string,Person>::iterator, map<string,Person>::iterator > _pairIt;
         map<string,Person>::iterator it[20];

         CashDispenser    cashd;
         BankDB           bank;
         Logger           log;
         Transaction*     trans;
         Person           person;
         Account          *account;
         Administrator    admin;

    public:
         Controller(HWND hwnd, CREATESTRUCT *pCreate);
         ~Controller();
         void Size(int x, int y);
         void InitiateBank();
         void ChangeCursorIcon();
         void Paint();
         void PaintDC(int, int);
         int getCursorState()
         {
             return _cursorState;
         }
         void Text(const char*, const char*);
         void TextExD(const char*, char);
         void TextExD(const char*, int, int);
         void TextExD(const char*, int);
         void TextExD(const char*, string);
         void TextExD(const char*, string, string, string, int, int);

         void LoadImages(HINSTANCE hInst);
         void Command(int cmd);
         void SettingPIN(int cmd);
         void SettingWithdrawSum(int cmd);
         void Menu(int cmd);
         void MouseMove();
         void SettingAddSum(int cmd);
         RECT GetLocalCoordinates(int);
         void ChooseCashIcon();
         void MakeSettings(HWND, HINSTANCE);
         void ResetCursor();
         void Interrogate(int cmd);
         void Statement();
         void LButtonDOWN();
         void HideStatement();
         void CloseTray();
         void ExecuteWithdraw(int);
         void SetNumberOfBanknotes(int);
         void PrintClients(int);
         void PrintLoggerFile(int);
         void Start();
         void SettingPINAdmin(int);
};
#endif // CONTROLLER_H_INCLUDED
