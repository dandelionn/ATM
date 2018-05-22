#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include <string>
#include "account.h"

using namespace std;

class Person{
      string firstname;
      string lastname;
      Account account;
public:
      Person();
      Person(string, string, string, int, int);

      void setFN(string);
      void setLN(string);
      void setAccount(string,int,int);
      Account& getAccount();
      string getFN();
      string getLN();
};
#endif // PERSON_H_INCLUDED
