#include "logger.h"

Logger::Logger()
{
    initTimeDate(a);
}

void Logger::initTimeDate(string &a)
{
    time_t rawtime;
    struct tm *info;
    time( &rawtime );
    info = localtime( &rawtime );
    a= asctime(info);
}

void Logger::printTransaction(int x, string s)
{
    initTimeDate(a);

    ofstream g;
    g.open("logger.txt",ios::ate | ios::app);
    if( s == "InquireBalance" )
          g<< s <<": "<< a;
    else
        if( s == "Withdraw" )
             g<< s <<": "<< x <<" "<< a;
        else
            if(s == "Deposit" )
                 g<< s <<": "<< x <<" "<< a;
    g.close();
}

void Logger::prepareForTransactions(string acc)
{
    ofstream g("logger.txt",ios::ate | ios::app);
    g<<"---------------------------------------------------------------\n";
    g<<"Account Number:"<<acc<<'\n';
    g.close();
}

void Logger::itotalCashAmount(int x)
{
    ofstream g("logger.txt",ios::ate | ios::app);
    g<<"Suma initiala din automat: "<< x <<'\n';
    g.close();
}

void Logger::ftotalCashAmount(int x)
{
    ofstream g("logger.txt",ios::ate | ios::app);
    g<<"Suma finala din automat: "<< x <<'\n';
    g.close();
}

void Logger::printBanknotesStatus(const int vb[],int b[])
{
    ofstream g("logger.txt",ios::ate | ios::app);
    g<<"Statusul bancnotelor din bancomat:\n";
    for(int i=0;i<5;i++)
         g<< b[i] <<" bancnote de "<< vb[i] <<" lei \n";
    g.close();
}

void Logger::printLackOfFunds(const int vb[], int b[])
{
    ofstream g("logger.txt",ios::ate | ios::app);
    g<<"Fonduri insuficiente in automat!\n";
    g<<"Statusul bancnotelor din bancomat:\n";
    for(int i=0;i<5;i++)
         g<< b[i] <<" bancnote de "<< vb[i] <<" lei \n";
    g.close();
}

///ACEASTA SECTIUNE A FOST MODIFICATA, FOLOSESTE LA CHITANTA
const char* Logger::showTransInfo(string accNr)
{
       ///ATENTIE LA DEPASIREA LIMITELOR TABLOULUI DE CARACTERE _text;
     strcpy(_text,"");
     ifstream f("logger.txt");

     string s1;
     string s2;
     string s3;

     while(!f.eof())
         {
             getline(f,a);
             if(   a.find("Account Number:")!=string::npos    &&   a.find(accNr)!=string::npos  )
                 {
                     while(getline(f,a))
                     {
                           if(a.find("Account Number:")== string::npos)
                              {
                                  if(a.find("InquireBalance") != string::npos)
                                     {
                                         s1 = s2;
                                         s2 = s3;
                                         s3 = a;
                                     }
                                  if(a.find("Withdraw") != string::npos)
                                     {
                                         s1 = s2;
                                         s2 = s3;
                                         s3 = a;
                                     }
                                  if(a.find("Deposit") != string::npos)
                                     {
                                         s1 = s2;
                                         s2 = s3;
                                         s3 = a;
                                     }
                             }}
               }
          }
          initTimeDate(a);
          strcat(_text, ("Statement of account\n\n" + a + "\n").c_str());
          strcat(_text, ("Account Number: " + accNr + "\n\n" + s1 + "\n" + s2 + "\n" + s3 + "\n\n" + "Thank you, Z Bank").c_str());

    f.close();

    return  (const char*) _text;
}

void Logger::loadTransInfoATM()
{
    ifstream f("logger.txt");
    counter=0;
    while(!f.eof())
         {
             getline(f,b[counter]);
             if(b[counter].find("InquireBalance") != string::npos)
                    counter++;
             else
                 if(b[counter].find("Withdraw") != string::npos)
                        counter++;
                 else
                    if(b[counter].find("Deposit") != string::npos)
                           counter++;
          }
    f.close();
}

string Logger::getTransATM(int i)
{
    if( i < counter)
    {
        return b[i];
    }
    else
        return "";
}

int Logger::getLimitTransATM()
{
    return counter;
}
