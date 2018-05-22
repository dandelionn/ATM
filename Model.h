#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include <string>
#include <map>

#include "display.h"
#include "Statement.h"

class Model: public Display,Statement{
    private:
          char _text[21];
          int _imgDim[100][4];
          map<string, int>  m;

    public:
         Model( char const* str)
         {
             SetText(str);
             saveKeyCase();
         }

         void saveKeyCase()
         {
             m["Info"]=                   1;
             m["Clear"]=                  2;
             m["Menu"]=                   3;
             m["TextLogInfo"]=            4;
             m["AmOfCash"]=               5;
             m["Success"]=                6;
             m["FailureAtm"]=             7;
             m["FailureAcc"]=             8;
             m["WithdrawValues"]=         9;
             m["BanknotesNotification"]=  10;
             m["TypeOfBanknote"]=         11;
             m["NumberOfBanknotes"]=      12;
             m["AddMoreCash"]=            13;
             m["TypesOfBanknotes"]=       14;
             m["AnotherTransaction"]=     15;
             m["WrongBanknote"]=          16;
             m["SetSum"]=                 17;
             m["SetAccount"]=             18;
             m["SetPIN"]=                 19;
             m["Star"]=                   20;
             m["NewLine"]=                21;
             m["TryAgain"]=               22;
             m["WrongPIN"]=               23;
             m["WrongAccount"]=           24;
             m["CardBlocked"]=            25;
             m["CashAdded"]=              26;
             m["NrAndValue"]=             27;
             m["PersonData"]=             28;
             m["Welcome"]=                29;
             m["GoodBye"]=                30;
             m["InsertCard"]=             31;
             m["SetPINEx"]=               32;
             m["SetSumEx"]=               33;
             m["Deposit"]=                34;
             m["Statement"]=              35;
             m["WrongValue"]=             36;
             m["AdminOrCard"]=            37;
             m["AdminMenu"]=              38;
             m["SelectTypeOfBanknote"]=   39;
             m["IntroduceNrOfBanknotes"]= 40;
             m["ShowClients"]=            41;
             m["ShowClientsEx"]=          42;
             m["BanknotesStatusATM"]=     43;
             m["ShowLoggerFile"]=         44;
             m["ShowLoggerFileEx"]=       45;
             m["SetPINAdmin"]=            46;
             m["SetPINAdminEx"]=          47;
             m["PleaseWait"]=             48;
         }

         void SetText( char const* str )
         {
             strncpy(_text, str, 20);
             _text[21] = '\0';
         }

         void SetExDText(string textc)
         {
             switch(m[textc])
             {
                 case 21:
                     printNewLine();
                 break;

                 case 42:
                     printNextPrevious();
                 break;

                 case 45:
                     printNextPrevious();
                 break;
             }
         }

         void SetDisplayText(string textc, char ch=0, int x=0, string fn="", string ln="", string acc="", int PIN=0, int sum=0)
         {
             switch(m[textc])
             {
                 case 1:
                     //printInfo();
                 break;

                 case 2:
                     clearDisplay();
                 break;

                 case 3:
                     printMenu();
                 break;

                 case 4:
                     printTextLogInfo();
                 break;

                 case 5:
                     printAmOfCash(x);
                 break;

                 case 6:
                     printSuccess();
                 break;

                 case 7:
                     printFailureAtm();
                 break;

                 case 8:
                     printFailureAcc();
                 break;

                 case 9:
                     printWithdrawValues();
                 break;

                 case 10:
                     printBanknotesNotification();
                 break;

                 case 11:
                     printTypeOfBanknote();
                 break;

                 case 12:
                     printNumberOfBanknotes();
                 break;

                 case 13:
                     printAddMoreCash();
                 break;

                 case 14:
                     printTypesOfBanknotes();
                 break;

                 case 15:
                     printAnotherTransaction();
                 break;

                 case 16:
                     printWrongBanknote();
                 break;

                 case 17:
                     printSetSum();
                 break;

                 case 18:
                     printSetAccount();
                 break;

                 case 19:
                     printSetPIN(ch);
                 break;

                 case 20:
                     printStar();
                 break;

                 case 21:
                     printNewLine();
                 break;

                 case 22:
                     //printTryAgain(int);
                 break;

                 case 23:
                     printWrongPIN();
                 break;

                 case 24:
                     printWrongAccount();
                 break;

                 case 25:
                     printCardBlocked();
                 break;

                 case 26:
                     printCashAdded(ch,x);
                 break;

                 case 27:
                     //printNrAndValue(int,int);
                 break;

                 case 28:
                     //printPersonData(string,string,string,int,int);
                 break;

                 case 29:
                     printWelcome();
                 break;

                 case 30:
                     printGoodBye();
                 break;

                 case 31:
                     printInsertCard();
                 break;

                 case 32:
                     printSetPINEx(ch);
                 break;

                 case 33:
                     printSetSumEx(ch);
                 break;

                 case 34:
                     printDeposit();
                 break;

                 case 36:
                     printWrongValue();
                 break;

                 case 37:
                     printAdminOrCard();
                 break;

                 case 38:
                     printAdminMenu();
                 break;

                 case 39:
                     printSelectTypeOfBanknote();
                 break;

                 case 40:
                     printIntroduceNrOfBanknotes(ch);
                 break;

                 case 41:
                     printShowClients();
                 break;

                 case 42:
                     printShowClientsEx(fn, ln, acc, PIN, sum);
                 break;

                 case 43:
                     printBanknotesStatusATM(ch,x);
                 break;

                 case 44:
                     printShowLoggerFile();
                 break;

                 case 45:
                     printShowLoggerFileEx(fn);
                 break;

                 case 46:
                     printSetPINAdmin(ch);
                 break;

                 case 47:
                     printSetPINAdminEx(ch);
                 break;

                 case 48:
                     printPleaseWait();
                 break;

                 default:
                       strcpy(_displayText, "Wrong text command for the Display");
             }
         }

         void SetStatementText(string textc, char const* str)
         {
             switch(m[textc])
             {
                 case 35:
                   printStatement(str);
                 break;

                 default:
                    strcpy(_statementText, "Wrong text command for the Statement");
             }
         }

         int getKey(const char* dtext)
         {
             return m[dtext];
         }

         int getPIN()
         {
             return _PIN;
         }

         int getSum()
         {
             return _sum;
         }

         int getPos()
         {
             return _pos;
         }

         int getX(int i)
         {
             return _imgDim[i][0];
         }

         int getY(int i)
         {
             return _imgDim[i][1];
         }

         int getWidth(int i)
         {
             return _imgDim[i][2];
         }

         int getHeight(int i)
         {
             return _imgDim[i][3];
         }

         char const* GetText() const {return _text;}
         char * getDisplayText() {return _displayText;}
         char * getStatementText()  {return _statementText;}
         int GetLen() const { return strlen(_text);}
};
#endif // MODEL_H_INCLUDED
