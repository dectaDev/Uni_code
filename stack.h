#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;
class stack{
    long num;
    long top;
    double array[100];
public :
    stack(long n)
    {
        num = n;
        array[num];
        for(int i = 0; i < n; i++)
        {
            array[i] = 0;
        }
        top = 0;
    }
    friend void Top(stack &a, double valu);
    friend void print(stack a);
    friend void pop(stack &a);
    friend void push(stack &a);
};

void Top(stack &a, double valu)
{
    if (a.top == a.num)
    {
        cout << "Full.\n";

        return ;
    }

    a.top++;
    a.array[a.top] = valu;

    return;
}

void print(stack a)
{
    long top_h = a.top;

    if (a.top == 0)
    {
        cout << "stack is empty.\n";

        return ;
    }
    for(int i = top_h; i > 0; i--)
    {
        cout << a.array[i] << endl;
    }
}

void pop(stack &a)
{
    if (a.top == -1)
    {
        cout << "empty.\n";

        return ;
    }
    a.top--;

    return;
}

void push(stack &a)
{
    if (a.top == -1)
    {
        cout << "empty.\n";

        return ;
    }
    cout << a.array[a.top--] << endl;

    return ;
}

#endif