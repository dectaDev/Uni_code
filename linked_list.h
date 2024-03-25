#ifndef LL_H
#define LL_H

#include <iostream>
using namespace std;
class node
{
    double valu;
    node *next;
public:
    friend node *newNode(double V);
    friend void addEnd(node *head, node *newNode);
    friend void print(node *head);
    friend void addHead(node **head, node *newNode);
    friend int listLen(node *head);
    friend void insert(node **head, int index, node *newNode);
    friend void deleteList(node **head, long index);
    friend void deletHead(node **head);
    friend int deleteEnd(node *head);
    friend bool searchList(node *head, double valu);
    friend void sortList(node **head);
    friend void deletListFull(node **head);
    friend void reValu(node **head, double valu_h, double valu_w);
    friend void removValue(node **head, double valu);
};

node *newNode(double V)
{
    node* output = new(node);
    output->valu = V;
    output->next = NULL;

    return output;
}

void addEnd(node* head, node* newNode)
{
    node* curr;
    for(curr = head; curr->next != NULL; curr = curr->next);
    curr->next = newNode;
}

void print(node *head)
{
    node *curr;
    cout << "[";
    for (curr = head; curr != nullptr; curr = curr->next)
    {
        cout << curr->valu;
        if (curr->next != nullptr)
        {
            cout << ", ";
        }
        else
        {
            cout << "]" << "\n";
        }
    }
}

void addHead(node** head, node* newNode)
{
    newNode->next = *head;
    *head = newNode;

    return;    
}

int listLen(node* head)
{
    int index = 0;
    node* curr;
    for(curr = head; curr != NULL; curr = curr->next)
    {
        index++;
    }

    return index;
}

void insert(node** head, int index, node* newNode)
{
    if(index > listLen(*head))
    {
        cout << "this array not have number " << index << " part\n";

        return;
    }
    node *curr;
    if(index == 1)
    {
        newNode->next = *head;
        *head = newNode;
        
        return;
    }
    if(index == listLen(*head))
    {
        for (curr = *head; curr->next != NULL; curr = curr->next);
        curr->next = newNode;

        return;
    }

    int i;
    for(curr = *head, i = 2; i < index; i++, curr = curr->next);

    newNode->next = curr->next;
    curr->next = newNode;

    return;
}

void deleteList(node** head, long index)
{
    if(index >= listLen(*head))
    {
        return ;
    }

    node* hold;

    if(index == 0)
    {
        hold = (*head);
        (*head) = (*head)->next;

        delete(hold);

        return ;
    }

    int i;
    node* curr;
    for(curr = *head, i = 0; i < index-1; i++, curr = curr->next);

    hold = curr->next;
    curr->next = curr->next->next;

    delete(hold);

    return ;
}

void deletHead(node** head)
{
    node* hold;
    hold = (*head);
    (*head) = (*head)->next;

    delete(hold);

    return;
}

int deleteEnd(node* head)
{
    int index, i;
    index = listLen(head);
    node* curr, *hold;
    for(curr = head, i = 0; i < index-1; curr = curr->next);
    
    hold = curr->next;
    curr->next = curr->next->next;

    delete (hold);
    return 0;
}

void removValue(node** head, double valu)
{
    if((*head)->valu == valu)
    {
        deletHead(&(*head));

        return ;
    }

    node* curr = *head;
    for(int i = 0; i < listLen(*head); i++, curr = curr->next)
    {
        if(curr->valu == valu)
        {
            deleteList(head, i);

            return ;
        }
    }

    return ;
}

void reValu(node** head, double valu_h, double valu_w)
{
    int i, index;
    node* curr = *head;
    index = listLen((*head));
    for(i = 0; i < index; i++, curr = curr->next)
    {
        if(curr->valu == valu_h)
        {
            curr->valu = valu_w;
        }
    }

    return;
}

void deletListFull(node** head)
{
    node* curr = *head;
    node* hold;
    for(; curr != NULL; curr = curr->next)
    {
        hold = curr;
        curr = curr->next;

        free(hold);
    }
    return;
}

void sortList(node** head)
{
    int V;
    node* curr = *head;
    node* currJ = *head;
    int i, j;
    int n = listLen((*head));
    int m = n;
    for(i = 0; i < n, curr != NULL; i++, curr = curr->next)
    {
        for(int j = 0; j < m, currJ->next != NULL; j++, currJ = currJ->next)
        {
            if(currJ->valu > currJ->next->valu)
            {
                V = currJ->valu;
                currJ->valu = currJ->next->valu;
                currJ->next->valu = V;
            }
        }
        currJ = *head;
    }
    return;
}

bool searchList(node *head, double valu)
{
    node* curr;
    for(curr = head; curr != nullptr; curr = curr->next)
    {
        if(curr->valu == valu)
        {
            return true;
        }
    }

    return false;
}

#endif