#include "BankDB.h"

pair< map<string,Person>::iterator, map<string,Person>::iterator > BankDB::getIterators()
{
    map<string,Person>::iterator it1;
    map<string,Person>::iterator it2;
    it1 = m.begin();
    it2 = m.end();
    return pair< map<string,Person>::iterator, map<string,Person>::iterator >(it1, it2);
}

void BankDB::initBank()
{
    string fn,ln,accnr;
    int pin,s;
    Person ob;

    ifstream f("bank.txt");
    while(!f.eof())
        {
            f>>fn>>ln>>accnr>>pin>>s;
            ob.setFN(fn); ob.setLN(ln);
            ob.setAccount(accnr, pin, s);
            m.insert(make_pair(accnr,ob));
        }
    f.close();
}

void BankDB::saveChanges()
{
    ofstream g("bank.txt");
    map<string,Person>::iterator it;
    for(it=m.begin(); it!=m.end(); ++it)
        {g<<(*it).second.getFN()<<' '<<(*it).second.getLN()<<' ';
        Account account=(*it).second.getAccount();
        g<<account.getAccNr()<<' '<<account.getPIN()<<' '<<account.getSum()<<'\n';}

    g.close();
}

Person BankDB::getPerson(string acc)
{
    if(m.find(acc) != m.end())
         return m.find(acc)->second;
    else
         return Person();
}

void BankDB::savePersonData(Person p)
{
    m[p.getAccount().getAccNr()]=p;
}
