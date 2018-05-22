#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED

#include "account.h"

class Transaction{
public:
    Transaction(){}
    virtual bool ExecuteTransaction(int, Account*) = 0;
    virtual ~Transaction(){}
};
#endif // TRANSACTION_H_INCLUDED
