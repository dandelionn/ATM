#ifndef CASH_DISPENSER_H_INCLUDED
#define CASH_DISPENSER_H_INCLUDED
#include <fstream>
#include "display.h"

using namespace std;

const int vb[5]={500,200,100,50,10};         ///valorile bancnotelor in ordine descrescatoare
const int nrmaxb[5]={10,25,50,20,10};        ///nr maxim de bancnote de un anumit tip pe care are voie sa le scoata bancomatul

class CashDispenser{
    Display display;
    int b[5];                                ///nr de bancnote de fiecare tip din automat;
    int sol[5];                              ///solutia generata de functia membra CheckForExistence
    int amountOfCash;                        ///atribuie valoarea 0 tuturor elementelor vectorului sol;
    void initsolution();                     ///atribuie tabloului solutie valoarea 0 pentru numarul fiecarui tip de bancnota

public:
    CashDispenser();                          ///se vor citi valorile din fisier(valori care reprezinta suma ramasa in bancomat)
    bool CheckForExistence(int);              ///Verifica daca exista suficienti bani in atm si genereaza solutia(numarul de bancnote de fiecare tip)
    int totalCashAmount();                    ///returneaza suma totala din bancomat
    void Withdraw(int);                       ///retrage suma de bani din bancomat
    void RefillCashAmount();                  ///introduce 200 de bancnote de fiecare tip
    bool AddCash(int,int);                    ///introduce un anumit numar de bancnote
    const int* getBanknotesValues();          ///returneaza adresa unui tablou care contine valorile bancnotelor
    int* getBanknotesNr();                    ///retunrneaza adresa unui tablou care contine numarul bancnotelor de fiecare tip din bancomat
    void saveValues();                        ///salveaza in fisier modificarile legate de numarul bancnotelor
    int NrBanknotes(int);                     ///returneaza numarul de bancnote extrase de un anumit tip(tipul 1-10, 2-50...);
    void RefillCashAmount(int, int);
    int getBanknotesNrATM(int);
};
#endif // CASH_DISPENSER_H_INCLUDED
