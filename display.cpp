#include "display.h"



void Display::printInfo(string a)
{
    strcpy(_displayText, "");
    const char * c = a.c_str();
    strcat(_displayText,c);
    strcat(_displayText, "\n");
}

void Display::clearDisplay()
{
        strcpy(_displayText, "");
}

void Display::printMenu()
{
        strcpy(_displayText, "Choose a task from the menu below:");
        strcat(_displayText,"\n\n\n\n\n\n\nDraw cash");
        strcat(_displayText,"                                                   Cancel, release the card");
        strcat(_displayText,"\n\n\n\nAdd cash");
        strcat(_displayText,"\n\n\n\nCheck the amount of cash in the account");
        strcat(_displayText,"\n\n\n\nPrint statement of account");
}

void Display::printTextLogInfo()
{
        strcpy(_displayText, "\nLog information:\n");
}

void Display::printAmOfCash(int x)
{
        itoa( x, _number, 10);
        strcpy(_displayText, "");
        strcat(_displayText, "\nAmount of cash in the account: ");
        strcat(_displayText, _number);
        strcat(_displayText, "\n\n\n\n\n\nReturn to the menu.");
        strcat(_displayText, "\n\n\n\nRelease the card.");
}

void Display::printSuccess()
{
        strcpy(_displayText, "\nWithDraw succeded!");
}

void Display::printFailureAtm()
{
        strcpy(_displayText, "\nSorry, not enough cash in the ATM.\n\n\n\n\n\n");
        strcat(_displayText, "\nRelease the card                                                  Another Transaction");
}

void Display::printFailureAcc()
{
        strcpy(_displayText, "\nSorry, not enough money in the account.\n\n\n");
        strcat(_displayText, "\nRelease the card                   Another Transaction");
}

void Display::printWithdrawValues()
{
        strcpy(_displayText, "\nSelect the sum you want to withdraw:\n\t10                    50\n\n\n\t100                   200\n\n\n\t500                   multiple of 10\n\n");
}

void Display::printBanknotesNotification()
{
        strcpy(_displayText, "\nNot enough banknotes. Please select another value or press 0 to cancel");
}

void Display::printTypeOfBanknote()
{
        strcpy(_displayText, "Type of banknote: ");
}

void Display::printNumberOfBanknotes()
{
        strcpy(_displayText, "Number of banknotes: ");
}

void Display::printAddMoreCash()
{
        strcpy(_displayText, "\nDo you wish to add more cash?\nPress 1 for yes\nPress 2 for no\n");
}

void Display::printTypesOfBanknotes()
{
        strcpy(_displayText, "Only the folowing types of banknotes are alowed: 500, 200, 100, 50, 10!\n");
}

void Display::printAnotherTransaction()
{
        strcpy(_displayText, "\n\n\nDo you wish to start another transaction?\n\nPress 1 for yes\nPress 2 for no\n");
}

void Display::printWrongBanknote()
{
        strcpy(_displayText, "\nDeposit failed. The type of banknote was wrong!\n");
}

void Display::printSetSum()
{
        strcpy(_displayText, "Select the amount of cash you want to withdraw:");
        strcat(_displayText,"\n\n\n\n\n\n\n 10                        ");
        strcat(_displayText,"                                                                         300");
        strcat(_displayText,"\n\n\n\n 50                        ");
        strcat(_displayText,"                                                                         500");
        strcat(_displayText,"\n\n\n\n 100                     ");
        strcat(_displayText,"                                                                        1000");
        strcat(_displayText,"\n\n\n\n 200                 ");
        strcat(_displayText,"                                                                 another sum");
        _sum = 0;
}

void Display::printSetSumEx(char ch)
{
       strcpy(_displayText, "\nIntroduce the sum(Multiple of 10): ");
       if(ch != ' ')
          {
              _sum = _sum * 10 +  (ch - '0');
              itoa(_sum, _number, 10);
              strcat(_displayText, _number);
           }
       else
            _sum=0;
}

void Display::printSetAccount()
{
        strcpy(_displayText, "\nIntroduce the number of the account: ");
}

void Display::printSetPIN(char ch)
{
    if(ch=='1')
        {strcpy(_displayText, "\nWrong PIN, try again!\n");
        strcat(_displayText, "\nIntroduce the PIN code: ");}
    else
        strcpy(_displayText, "\nIntroduce the PIN code: ");

    _pos = 0;
    _PIN = 0;
}

void Display::printSetPINEx(char ch)
{
        char b[] = "0"; b[0]=ch;
        strcat(_displayText, b);

        _PIN = _PIN * 10 + ch - '0';
        _pos++;
}

void Display::printStar()
{
        strcpy(_displayText, "*");
}

void Display::printNewLine()
{
        strcat(_displayText, "\n");
}

void Display::printTryAgain(int x)
{
        if(x == 1)
                {
                strcpy(_displayText, "");
                strcat(_displayText,"\nBe carefull! You have ");
                _displayText[24]='0'+x;
                _displayText[25]='\0';
                strcat(_displayText," more try until your card will be blocked!\n");
                strcat(_displayText,"\n\nPress 1 to reintroduce the account number and the PIN code.");
                strcat(_displayText,"\nPress 2 to release the card.\n");
                }
        else
                {
                strcpy(_displayText, "");
                strcat(_displayText,"\nBe carefull! You have ");
                _displayText[24]='0'+x;
                _displayText[25]='\0';
                strcat(_displayText," more tries until your card will be blocked!\n");
                strcat(_displayText,"\n\nPress 1 to reintroduce the account number and the PIN code.");
                strcat(_displayText,"\nPress 2 to release the card.\n");
                }
}

void Display::printWrongPIN()
{
        strcpy(_displayText, "\nWrong PIN!");
}

void Display::printWrongAccount()
{
        strcpy(_displayText, "\nAccount number not found!");
}

void Display::printCardBlocked()
{
        strcpy(_displayText, "\nYour card has been blocked in the ATM.\nPlease go to the bank in order to unlock it.\n");
}

void Display::printDeposit()
{
        _banknote10  = 0;
        _banknote50  = 0;
        _banknote100 = 0;
        _banknote200 = 0;
        _banknote500 = 0;
        strcpy(_displayText, "\nClick the images to select the type of bancknote to add. Then introduce the banknote into the cash getter.\n\n");
}

void Display::printCashAdded(char ch, int x)
{
    ///1-10  ;   2-50;   3-100 ;   4-200;    5-500
        if( (ch - '0') == 1)
             _banknote10++;
        if( (ch - '0') == 2)
            _banknote50++;
        if( (ch - '0') == 3)
            _banknote100++;
        if( (ch - '0') == 4)
            _banknote200++;
        if( (ch - '0') == 5)
            _banknote500++;
        _sum = _banknote10 * 10 + _banknote50 * 50 + _banknote100 * 100 + _banknote200 * 200 + _banknote500 * 500;

        itoa( _sum, _number, 10);

        strcpy(_displayText, "");
        strcat(_displayText,"\nThe sum of ");
        strcat(_displayText, _number);
        strcat(_displayText," has been added to your account.\n");

        itoa( x, _number, 10);
        strcat(_displayText, "\nThe total cash amount in your account is now: ");
        strcat(_displayText, _number);

        strcat(_displayText,"\nYou have introduced:\n ");
        itoa( _banknote10, _number, 10);
        strcat(_displayText, _number);
        strcat(_displayText, " banknotes of 10 lei.\n");

        itoa( _banknote50, _number, 10);
        strcat(_displayText, _number);
        strcat(_displayText, " banknotes of 50 lei.\n");

        itoa( _banknote100, _number, 10);
        strcat(_displayText, _number);
        strcat(_displayText, " banknotes of 100 lei.\n");

        itoa( _banknote200, _number, 10);
        strcat(_displayText, _number);
        strcat(_displayText, " banknotes of 200 lei.\n");

        itoa( _banknote500, _number, 10);
        strcat(_displayText, _number);
        strcat(_displayText, " banknotes of 500 lei.\n");

        strcat(_displayText, "\nPress OK to go back to the menu, or continue to add banknotes");
}

void Display::printShowClients()
{
    strcpy(_displayText, " Press CANCEL for returning to the menu!\n\nClients:\n\n");
}

void Display::printShowClientsEx(string fn, string ln, string acc, int PIN, int sum)
{
    if(fn != "")
        {
        const char * c1 = fn.c_str();
        const char * c2 = ln.c_str();
        const char * c3 = acc.c_str();
        strcat(_displayText,"     ");
        strcat(_displayText, c1);
        strcat(_displayText," ");
        strcat(_displayText, c2);
        strcat(_displayText," ");
        strcat(_displayText, c3);
        strcat(_displayText," ");

        char b[10];

        itoa(PIN,b,10);
        strcat(_displayText, b);
        strcat(_displayText," ");

        itoa(sum,b,10);
        strcat(_displayText, b);
        strcat(_displayText,"\n");
        }
}

void Display::printWelcome()
{
        strcpy(_displayText, "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tWelcome!");
}

void Display::printGoodBye()
{
        strcpy(_displayText, "\n\n\n\n\n\n\n\n\n\n \t\t\t\t\tGood Bye!");
}

void Display::printInsertCard()
{
        strcpy(_displayText, "\n\n\n\n\n\n\n\n \t\t\t\t\t Insert the card!");
}

void Display::printWrongValue()
{
        strcpy(_displayText, "\nSorry, you have to introduce another value, multiple of 10.\n\n\n\n\n");
        strcat(_displayText, "\nRelease the card                                                  Another Transaction");
}

void Display::printAdminOrCard()
{
        strcpy(_displayText, "\nSelect how are you going to use this ATM:");
        strcat(_displayText,"\n\n\n\n\n\n\n As a Client");
        strcat(_displayText,"\n\n\n\n As an Administrator");
}

void Display::printAdminMenu()
{
        strcpy(_displayText, "\nSelect an option:");
        strcat(_displayText,"\n\n\n\n\n\n Print all the clients registered in the bank");
        strcat(_displayText,"\n\n\n Introduce the number of banknotes of each type which have been introduced");
        strcat(_displayText,"\n\n\n\n Print log information");
        strcat(_displayText,"\n\n\n\n Show banknotes status and total cash amount in the ATM");
}

void Display::printSelectTypeOfBanknote()
{
        _sum = 0;
        strcpy(_displayText, "\n\nSelect the type of banknote:");
        strcat(_displayText,"\n\n\n\n\n 10                        ");
        strcat(_displayText,"                                                                         500");
        strcat(_displayText,"\n\n\n\n 50");
        strcat(_displayText,"\n\n\n\n 100");
        strcat(_displayText,"\n\n\n\n 200                 ");
        strcat(_displayText,"                                                                        Menu");
}

void Display::printIntroduceNrOfBanknotes(char ch)
{
        strcpy(_displayText, "\n\nIntroduce the number of this type of banknote:");
        if(ch != ' ')
          {
              _sum = _sum * 10 +  (ch - '0');
              itoa(_sum, _number, 10);
              strcat(_displayText, _number);
           }
        else
            _sum=0;
}

void Display::printNextPrevious()
{
    strcat(_displayText,"next                                           ");
    strcat(_displayText,"                                            previous");
}

void Display::printBanknotesStatusATM(char ch, int x)
{
    if(ch != ' ')
       {
           if(ch=='0')
               {itoa( x, _number, 10);
                strcpy(_displayText, "\nThe total cash amount in the ATM: ");
                strcat(_displayText, _number);}

           if(ch=='1')
               {strcat(_displayText, "\n\nThere are: ");
               itoa(x, _number, 10);
               strcat(_displayText, _number);
               strcat(_displayText, " banknotes of 10 lei.\n");}

           if(ch=='2')
               {strcat(_displayText, "There are: ");
               itoa(x, _number, 10);
               strcat(_displayText, _number);
               strcat(_displayText, " banknotes of 50 lei.\n");}

           if(ch=='3')
               {strcat(_displayText, "There are: ");
               itoa(x, _number, 10);
               strcat(_displayText, _number);
               strcat(_displayText, " banknotes of 100 lei.\n");}

           if(ch=='4')
               {strcat(_displayText, "There are: ");
               itoa(x, _number, 10);
               strcat(_displayText, _number);
               strcat(_displayText, " banknotes of 200 lei.\n");}

           if(ch=='5')
               {strcat(_displayText, "There are: ");
               itoa(x, _number, 10);
               strcat(_displayText, _number);
               strcat(_displayText, " banknotes of 500 lei.\n");
               strcat(_displayText, "\n\n\n\n\n\n\n\n\n");
               strcat(_displayText,"\n\n Back to the menu");}
       }
}

void Display::printShowLoggerFile()
{
    strcpy(_displayText, " Press CANCEL for returning to the menu!\n\nTransactions:\n\n");
}

void Display::printShowLoggerFileEx(string s)
{
    const char * c = s.c_str();
    strcat(_displayText,"     ");
    strcat(_displayText, c);
    strcat(_displayText,"\n");
}

void Display::printSetPINAdmin(char ch)
{
        if(ch=='1')
            {strcpy(_displayText, "\nWrong PIN, try again!\n");
            strcat(_displayText, "\nIntroduce the PIN code: ");}
        else
            strcpy(_displayText, "\nIntroduce the PIN code: ");

        _pos = 0;
        _PIN = 0;
}

void Display::printSetPINAdminEx(char ch)
{

        char b[] = "0"; b[0]=ch;
        strcat(_displayText, b);

        _PIN = _PIN * 10 + ch - '0';
        _pos++;
}

void Display::printPleaseWait()
{
    strcpy(_displayText, "\n\n\n\n\n\n\n\n\nPlease wait a few moments...");
}
