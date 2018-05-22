#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED

#include <time.h>
#include <string.h>
#include <fstream>

using namespace std;

class Logger{
     string a;            ///string care memoreaza data, ora, ...
     string b[2000];       ///sir de string-uri care memoreaza tranzactiile
     char _text[1000000];    ///memoreaza datele din chitanta
     int counter;

public:
    Logger();
    void initTimeDate(string&);                     ///initiaza data,ziua,ora,minutul,secunda...
    void itotalCashAmount(int x);                   ///suma initiala din automat
    void ftotalCashAmount(int x);                   ///suma finala din automat
    void printBanknotesStatus(const int[],int[]);   ///scrie in fisier statusul bancnotelor
    void printLackOfFunds(const int[],int[]);       ///scrie in fisier mesajul lipsa de bancnote si statusul bancnotelor
    void prepareForTransactions(string);            ///pregateste o noua tranzactie(adauga separatorul, afiseaza numarul de cont)
    void printTransaction(int,string);              ///scrie in fisier datele tranzactiei
    const char* showTransInfo(string);                           ///afiseaza pe ecran cu ajutorul unui obiect Display, toate tranzactiile
                                                    ///din fisier;
    void loadTransInfoATM();
    string getTransATM(int);
    int getLimitTransATM();
};
#endif // LOGGER_H_INCLUDED
