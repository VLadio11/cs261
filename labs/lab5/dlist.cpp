// Phil Stephenson
#include "dlist.h"

void duplicate(node* head, node*& newHead)
{
    if (head) {
        newHead = new node;
        newHead->data = head->data;
        newHead->next = NULL;
        newHead->previous = head->previous;
        duplicate(head->next, newHead->next);
    } else {
        newHead = NULL;
    }
}

int removeTwo(node*& head)
{
    return 0;
}

