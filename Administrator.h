#ifndef ADMINISTRATOR_H_INCLUDED
#define ADMINISTRATOR_H_INCLUDED

#include <string>
#include <fstream>

class Administrator{

    string firstname;
    string lastname;
    string cardNumber;
    int PIN;

    public:
        Administrator(){
            std::ifstream f("admin.txt");
            f >> firstname >> lastname >> cardNumber >> PIN;
            f.close();
        }
        string getFN(){return firstname;}
        string getLN(){return lastname;}
        string getcardNr(){return cardNumber;}
        int getPIN(){return PIN;}
};
#endif // ADMINISTRATOR_H_INCLUDED
