#include "person.h"

Person::Person()
{
    firstname="Anonim";
    lastname="Anonim";
}

Person::Person(string fn, string ln, string accnr, int pin, int s): account(accnr, pin, s)
{
    firstname=fn;
    lastname=ln;
}

void Person::setFN(string fn)
{
     firstname=fn;
}

void Person::setLN(string ln)
{
     lastname=ln;
}

string Person::getFN()
{
     return firstname;
}

string Person::getLN()
{
     return lastname;
}

void Person::setAccount(string accnr,int pin,int s)
{
    account.setAccount(accnr, pin, s);
}

Account& Person::getAccount()
{
    return account;
}
