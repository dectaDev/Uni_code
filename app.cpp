#include <iostream>
#include "stack.h"
#include "sparceMatrix.h"
#include "sort.h"
#include "search.h"
#include "queue.h"
#include "matrix.h"
#include "linked_list.h"
#include "doublyLinked_list.h"

using namespace std;

int main(void)
{
    Dnode *head = newNod(1);
    addEnd(head, newNod(3));
    addEnd(head, newNod(89));
    addEnd(head, newNod(67));
    DeleteEnd(head);
    Print(head);
    return 0;
}