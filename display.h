#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED
#include <windows.h>
#include <string>

using namespace std;

class Display{
protected:
    char _displayText[5000];
    int  _pos;
    int  _PIN;
    int  _sum;
    int  _banknote10;
    int  _banknote50;
    int  _banknote100;
    int  _banknote200;
    int  _banknote500;
    char _number[20];
public:
    void printInfo(string);
    void clearDisplay();
    void printMenu();
    void printTextLogInfo();
    void printAmOfCash(int);
    void printSuccess();
    void printFailureAtm();
    void printFailureAcc();
    void printWithdrawValues();
    void printBanknotesNotification();
    void printTypeOfBanknote();
    void printNumberOfBanknotes();
    void printAddMoreCash();
    void printTypesOfBanknotes();
    void printAnotherTransaction();
    void printWrongBanknote();
    void printSetSum();
    void printSetAccount();

    void printStar();
    void printNewLine();
    void printTryAgain(int);
    void printWrongPIN();
    void printWrongAccount();
    void printCardBlocked();

    void printCashAdded(char, int);
    void printDeposit();
    void printWelcome();
    void printGoodBye();
    void printInsertCard();

    void printSetPIN(char);
    void printSetPINEx(char);
    void printSetSumEx(char);

    void printWrongValue();
    void printAdminOrCard();
    void printAdminMenu();
    void printSelectTypeOfBanknote();
    void printIntroduceNrOfBanknotes(char ch);

    void printShowClients();
    void printShowClientsEx(string,string,string,int,int);
    void printNextPrevious();
    void printBanknotesStatusATM(char, int);
    void printShowLoggerFile();
    void printShowLoggerFileEx(string);

    void printSetPINAdmin(char);
    void printSetPINAdminEx(char);
    void printPleaseWait();
};
#endif // DISPLAY_H_INCLUDED
