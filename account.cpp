#include "account.h"

Account::Account()
{
    AccNumber="nonumber";
    PIN=0;
    sum=0;
}
Account::Account(string acc, int pin, int sum)
{
    AccNumber=acc;
    PIN=pin;
    sum=sum;
}

void Account::setAccount(string acc, int pin, int s)
{
    AccNumber=acc;
    PIN=pin;
    sum=s;
}

void Account::setAccNr(string accnr)
{
     AccNumber=accnr;
}

void Account::setPIN(int pin)
{
     PIN=pin;
}

void Account::setSum(int s)
{
     sum=s;
}

string Account::getAccNr()
{
     return AccNumber;
}

int Account::getPIN()
{
    return PIN;
}

int Account::getSum()
{
    return sum;
}

void Account::addCash(int x)
{
    sum+=x;
}

void Account::withdraw(int x)
{
    sum-=x;
}
