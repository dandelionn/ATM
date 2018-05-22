#ifndef VALIDATEAMOUNT_H_INCLUDED
#define VALIDATEAMOUNT_H_INCLUDED

#include "Transaction.h"
#include "account.h"

class ValidateAmount: public Transaction{
public:
    ValidateAmount(){}                                     ///x suma
    bool ExecuteTransaction(int x, Account *account)     ///verifica daca exista destul cash in cont
    {
        if(account->getSum() >= x)
            return 1;
        else
            return 0;
    }
};

#endif // VALIDATEAMOUNT_H_INCLUDED
