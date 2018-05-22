#ifndef DEPOSIT_H_INCLUDED
#define DEPOSIT_H_INCLUDED

#include "Transaction.h"
#include "account.h"

class Deposit: public Transaction{
public:
    Deposit(){}
    bool ExecuteTransaction(int x, Account *account)
    {
        account->addCash(x);
        return 1;
    }
};
#endif // DEPOSIT_H_INCLUDED
