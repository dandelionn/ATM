#ifndef BANKDB_H_INCLUDED
#define BANKDB_H_INCLUDED

#include <map>
#include <fstream>
#include "person.h"
#include  "display.h"
///Un obiect de tipul bank contine datele tuturor persoanelor

class BankDB{
private:
    Display display;
    map<string,Person> m;

public:
    void initBank();
    void savePersonData(Person);
    void saveChanges();
    Person getPerson(string);
    pair< map<string,Person>::iterator, map<string,Person>::iterator > getIterators();
};
#endif // BANKDB_H_INCLUDED
