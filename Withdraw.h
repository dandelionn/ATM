#ifndef WITHDRAW_H_INCLUDED
#define WITHDRAW_H_INCLUDED

#include "Transaction.h"
#include "account.h"

class Withdraw: public Transaction{
public:
    Withdraw(){}
    bool ExecuteTransaction(int x, Account *account)         ///x suma
    {
        account->withdraw(x);
        return 1;
    }
};
#endif // WITHDRAW_H_INCLUDED
