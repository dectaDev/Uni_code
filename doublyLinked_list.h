#ifndef DLL_H
#define DDL_H

#include <iostream>
using namespace std;

class Dnode
{
    double valu;
    Dnode *next, *befor;

public:
    friend Dnode* newNod(double valu);
    friend void addEnd(Dnode *head, Dnode *newNode);
    friend void Print(Dnode *head);
    friend void addHead(Dnode** head, Dnode* newNod);
    friend void insert(Dnode** head, long index, Dnode* newNod);
    friend long lenList(Dnode* head);
    friend void printPRE(Dnode** head, long index);
    friend void printES(Dnode* head);
    friend void DeleteList(Dnode** head, long index);
};

Dnode* newNod(double valu)
{
    Dnode *output = new (Dnode);
    output->valu = valu;
    output->next = nullptr, output->befor = nullptr;
    
    return output;
}

void addEnd(Dnode* head, Dnode *newNode)
{
    Dnode *curr;
    for (curr = head; curr->next != nullptr; curr = curr->next);
    curr->next = newNode;
    newNode->befor = curr;

    return;
}

void addHead(Dnode** head, Dnode* newNod)
{
    Dnode* curr = (*head);
    newNod->next = (*head);
    *head = newNod;
    curr->befor = *head;
    (*head)->befor = nullptr;
}

void Print(Dnode *head)
{
    Dnode *curr = head;
    cout << "[";
    for (; curr != nullptr; curr = curr->next)
    {
        cout << curr->valu;
        if (curr->next != nullptr)
        {
            cout << ", ";
        }
        else
        {
            cout << "]"
                 << "\n";
        }
    }

    return;
}

long lenList(Dnode* head)
{
    Dnode* curr;
    long index = 0;

    for (curr = head; curr->next != nullptr; curr = curr->next)
    {
        index++;
    }

    return index;
}

void insert(Dnode** head, long index, Dnode* newNod)
{
    Dnode *curr_T, *curr_U;

    if (index > lenList(*head)+1)
    {
        cout << "dont have this index.\n";

    return ;
    }

    if(index == -1)
    {
        Dnode* curr = (*head);
        newNod->next = (*head);
        *head = newNod;
        curr->befor = *head;
        (*head)->befor = nullptr;

    return ;
    }
    
    if (index == lenList(*head))
    {
        for (curr_T = *head; curr_T->next != nullptr; curr_T = curr_T->next);
        curr_T->next = newNod;
        newNod->befor = curr_T;

    return;
    }

    int i = 0;
    for (curr_T = *head; curr_T->next != nullptr, i <= index; curr_T = curr_T->next, i++);
    i = 0;
    for (curr_U = *head; curr_U->next != nullptr, i < index; curr_U = curr_U->next, i++);

    newNod->next = curr_T;
    curr_T->befor = newNod;
    newNod->befor = curr_U;
    curr_U->next = newNod;

    return;
}

void printPRE(Dnode** head, long index)
{
    Dnode *curr = *head;
    if(index > lenList(*head))
    {
        cout << "not exist this index.\n";
        
        return ;
    }

    if(index == 0)
    {
        cout << "nullptr\n";

        return ;
    }

    int i;

    for (i = 0; i < index; i++, curr = curr->next);

    cout << "your valu is : " << curr->befor->valu;

    return;
}

void printES(Dnode* head)
{
    Dnode* curr = head;
    long index = lenList(head);
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }

    cout << "[";
    while (curr != nullptr)
    {
        cout << curr->valu;
        if (curr->befor != nullptr)
        {
            cout << ", ";
        }
        else{
            cout << "]\n";
        }

        curr = curr->befor;
    }

    return;
}

void DeleteList(Dnode** head, long index)
{
    if(index >= lenList(*head))
    {
        return ;
    }

    Dnode* hold;

    if(index == 0)
    {
        hold = (*head);
        (*head) = (*head)->next;
        (*head)->befor = nullptr; 

        delete(hold);

        return ;
    }

    int i;
    Dnode* curr;
    for(curr = *head, i = 0; i < index-1; i++, curr = curr->next);

    hold = curr;
    curr = curr->next;
    curr->befor = hold->befor;

    delete(hold);

    return ;
}

#endif