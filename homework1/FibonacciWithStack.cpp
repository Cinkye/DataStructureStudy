// Homework 1 exercise 4.16
// Name:Ò¶×Ó·± 201730684427
// Date:2018/09/26
// The upper part is the rewritten edition function with array-based stack
// The main function is used to test it
#include "astack.h"
#include <iostream>
using namespace std;

long fibr(int n)
{
    //fibr(46) is largest value that fits in a long
    long num=1;
    AStack<long> stack(46);
    stack.push(num);
    for(int i = 1;i<n;++i)
        num = stack.topValue() + stack.push(num);       //Change the return type of push from void to E
    return stack.topValue();
}

int main()
{
    int n;
    while(cin >> n)
    cout << "The " << n << "th number of the list is " << fibr(n) << endl;
    return 0;
}

