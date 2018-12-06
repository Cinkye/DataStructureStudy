#include <iostream>
#include "hashDictionary.h"
#include "hashDictionary2.h"
using namespace std;

int main()
{
    hashdict<int,char*>* ha = new hashdict<int,char*>(17,-1,-2,"EMPTY");
    ha->insert(5,"Cinkye");
    ha->insert(1,"Cinkye");
    ha->insert(357,"Cinkye");
    ha->insert(2,"Cinkye");
    ha->insert(654,"Cinkye");
    ha->insert(54,"Cinkye");
    ha->insert(0,"Cinkye");
    ha->insert(3,"Cinkye");
    ha->insert(4321,"Cinkye");
    ha->insert(6,"Cinkye");
    ha->insert(53,"Cinkye");
    ha->insert(98,"Cinkye");
    ha->insert(37,"Cinkye");
    ha->insert(35,"Cinkye");
    ha->insert(99,"Cinkye");
    ha->insert(101,"Cinkye");
    ha->insert(38,"Cinkye");

    cout << ha->remove(4321) << endl;
    cout << ha->remove(6) << endl;
    cout << ha->remove(53) << endl;
    cout << ha->remove(98) << endl;
    cout << ha->remove(37) << endl;
    cout << ha->remove(35) << endl;
    cout << ha->remove(99) << endl;
    cout << ha->remove(101) << endl;
    cout << ha->remove(38) << endl;
    cout << ha->remove(5) << endl;
    cout << ha->remove(1) << endl;
    cout << ha->remove(357) << endl;
    cout << ha->remove(2) << endl;
    cout << ha->remove(654) << endl;
    cout << ha->remove(54) << endl;
    cout << ha->remove(0) << endl;
    cout << ha->remove(3) << endl;
}
