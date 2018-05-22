#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

#include <string>
using namespace std;

class Account{
    string AccNumber;      /// o persoana poate avea mai multe conturi
    int PIN;                /// o persoana poate avea mai multe conturi
    int sum;
public:
    Account();
    Account(string,int,int);
    void setAccount(string,int,int);
    void setAccNr(string);
    void setPIN(int);
    void setSum(int);           ///it could be float (la finisarea proiectului adauga float)
    void addCash(int);
    void withdraw(int);
    string getAccNr();
    int getPIN();
    int getSum();
};
#endif // ACCOUNT_H_INCLUDED
