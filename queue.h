#ifndef Q_H
#define Q_H

#define size 15

#include <iostream>
using namespace std;

class que{
    long First, Top;
    long num;
    double A[size];
public:
que(long num);
bool empty();
void add(double value);
void Print();
void pop();
bool full();
void push();
};

que::que(long number)
{
    First = 0, Top = 0;
    num = number;
    A[num];
}
bool que::full()
{
    if(Top == num && First == num)
    {
        return true;
    }

    return false;
}
bool que::empty()
{
    if(Top == 0 or (Top == num && First == num))
    {
        return true;
    }

    return false;
}

void que::add(double value)
{
    if(Top == num)
    {
        cout << "Queue is full" << endl;

        return;
    }
    A[Top] = value;
    Top++;

    return;
}

void que::Print()
{
    if(empty())
    {
        cout << "Queue is empty" << endl;

        return;
    }
    for(int i = First; i < Top; i++)
    {
        cout << A[i];
        if(i != Top-1)
        {
            cout << ", ";
        }
        else
        {
            cout << endl;
        }
    }

    return;
}

void que::pop()
{
    cout << "pop("<< A[First] << ")" << endl;

    return;
}

void que::push()
{
    if(empty())
    {
        cout << "Queue is full.\n";

        return;
    }

    cout << "push("<< A[First++] << ")" << endl;

    return;
}
#endif