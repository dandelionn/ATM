#include "cash_dispenser.h"
#include <iostream>


CashDispenser::CashDispenser()
{
    int x; amountOfCash=0;
    std::ifstream f("cash_dispenser.txt");
    for(int i=0;i<=4;i++)   ///se citeste numarul de bancnote de fiecare tip( de la 500 la 10)
      {

          f>>x;
          b[i]=x;
          amountOfCash+=b[i]*vb[i];
      }
    f.close();
}

void CashDispenser::initsolution()
{
    for(int i=0;i<5;i++)
        sol[i]=0;
}

bool CashDispenser::CheckForExistence(int x)      ///Checks if the ATM has enough money for a withdraw and generates solution
{
    initsolution();
    if(x>5000)        ///nu se pot scoate mai mult de 5000 lei din bancomat
        return 0;

    if(x%100/10<=b[4])     ///verifica daca sunt suficiente bancnote de 10;
         {if(b[0] && b[1] && !b[2] && !b[3])
                {if(x/100%10==6)
                     {if(((x-600) / 500)<=b[0] && b[1]>=3)      /// verifica daca sunt sufieciente bancnote de 500 si de 200
                           {
                                  sol[1]=3; sol[0]= (x-600)/500;
                                  x=x%200 ;
                                  sol[4]=x/10;
                                  x=x%10;
                                  return 1;
                           }
                     }
        else
            if(x/100%10==8)
                if(((x-800) / 500<=b[0]) && b[1]>=4)    /// verifica daca sunt sufieciente bancnote de 500 si de 200
                       {
                             sol[1]=4; sol[0]= (x-800)/500;
                             x=x%200 ;
                             sol[4]=x/10;
                             x=x%10;
                             return 1;
                       }
              }
          }
    else
        return 0;

     ///cazul general
    int test=0; int i=0;
    if(x>0)
        for(i=0; i<=4 && test!=1; i++)
              {if(x/vb[i]<=b[i] && x/vb[i]<=nrmaxb[i])  ///daca sunt destule bancnote cu valoarea vb[i];
                {
                       sol[i]=x/vb[i];
                       x=x%vb[i];
                }
              else
                   if(x/vb[i]>nrmaxb[i] && x/vb[i]<=b[i])      ///daca se depaseste valoarea maxima de bancnote de un anumit tip si daca avem destule bancnote de tipul b[i]in bancomat
                        {
                             sol[i]=nrmaxb[i];
                             x=x- b[i]*nrmaxb[i];
                        }
                   else
                        {
                             sol[i]=b[i];                 /// pentru cazul in care sunt mai putine bancnote de un anumit tip decat necesare
                             x=x- b[i]*vb[i];
                        }
              if( x == 0 )
                 test=1;}
    if(test==1)
         return 1;
    else
         return 0;
}

void CashDispenser::Withdraw(int x)
{
             amountOfCash -= x;
             for(int i=0;i<=4;i++)
                 b[i]-=sol[i];
}

void CashDispenser::RefillCashAmount()
{
      for(int i=0;i<=4;i++)
           b[i]=200;
}

int CashDispenser::NrBanknotes(int i)
{
    return sol[5-(i+1)];
}

bool CashDispenser::AddCash(int type,int number)  /// Adauga bani in ATM, daca tipul bancnotei este corect returneaza 1, altfel returneaza 0
{
    bool v=1;
    amountOfCash+= type * number;
    switch(type)
    {
        case 500:
            b[0]+=number;
            break;
        case 200:
            b[1]+=number;
            break;
        case 100:
            b[2]+=number;
            break;
        case 50:
            b[3]+=number;
            break;
        case 10:
            b[4]+=number;
            break;
        default:
            v=0;
    }
    return v;
}

int CashDispenser::totalCashAmount()                  ///returneaza suma totala de bani din bancomat
{
    return amountOfCash;
}

void CashDispenser::saveValues()                      ///salveza in fisier numarul de bancnote de fiecare tip
{
    std::ofstream out("cash_dispenser.txt");
    for(int i=0;i<5;i++)
        out<<b[i]<<' ';
    out.close();
}

const int* CashDispenser::getBanknotesValues()        ///returneaza adresa tabloului care retine tipul bancnotelor
{
    return vb;
}

int* CashDispenser::getBanknotesNr()                 ///returneaza adresa tabloului care retine numarul bancnotelor
{
    return b;
}

int CashDispenser::getBanknotesNrATM(int i)
{
    return b[i];
}

