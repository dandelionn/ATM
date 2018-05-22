#ifndef STATEMENT_H_INCLUDED
#define STATEMENT_H_INCLUDED

class Statement{
protected:
    char _statementText[1000000];
public:
    void printStatement(const char* x)
    {
        strcpy(_statementText, "\n");
        strcat(_statementText, x);
    }
};
#endif // STATEMENT_H_INCLUDED
