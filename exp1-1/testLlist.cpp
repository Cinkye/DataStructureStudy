#include <iostream>
#include "Llist.h"
#include "Alist.h"
using namespace std;
int main()
{
    List<char>* H = new Llist<char>;

    //依次插入a,b,c,d,e五个元素
    cout << "------------------------Llist test------------------------" << endl << endl;
    cout << "Testing functions append()..." << endl;
    cout << "a,b,c,d,e are appended" << endl;
    H->append('a');
    H->append('b');
    H->append('c');
    H->append('d');
    H->append('e');

    //输出链表
    H->moveToStart();
    cout << "Now list is: ";
    for(int i = 0;i<H->length();++i)
    {
        cout << H->getValue() << " ";
        if(H->currPos()!=H->length()-1)
            H->next();
    }
    cout << endl;

    //输出长度
    cout << endl << "Testing functions length()..." << endl;
    cout << "The length of the list is " << H->length() << endl;

    //判断链表是否为空
    cout << endl << "Testing functions isEmpty()..." << endl;
    cout << "Is the list empty? " << (H->isEmpty()==0 ? "No" : "Yes") << endl;

    //输出第三个元素
    cout << endl << "Testing function moveToPos()..." << endl;
    H->moveToPos(3);
    cout << "The third element is:" << H->getValue() << endl;

    //输出元素a的位置
    cout << endl << "Testing functions getValue(), currPos(), length() and next()..." << endl;
    H->moveToStart();
    while(H->getValue() != 'a' && H->currPos() < H->length())
        H->next();
    if(H->getValue()=='a')
        cout << "The position of element a is " << H->currPos() << endl;
    else
        cout << "element a is not in the list" << endl;

    //在第4个元素上插入f元素
    cout << endl << "Testing functions insert()..." << endl << "Element 'f' inserted" << endl;
    H->moveToPos(4);
    H->insert('f');

    //输出链表
    H->moveToStart();
    cout << "Now list is: ";
    for(int i = 0;i<H->length();++i)
    {
        cout << H->getValue() << " ";
        if(H->currPos()!=H->length()-1)
            H->next();
    }
    cout << endl;

    //删除第3个元素
    cout << endl << "Testing functions remove()..." << endl << "Element on position 3 is removed" << endl;
    H->moveToPos(3);
    H->remove();

    //输出链表
    H->moveToStart();
    cout << "Now list is: ";
    for(int i = 0;i<H->length();++i)
    {
        cout << H->getValue() << " ";
        if(H->currPos()!=H->length()-1)
            H->next();
    }
    cout << endl;
    cin.get();
    return 0;
}
