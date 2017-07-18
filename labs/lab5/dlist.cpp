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

void removeTwoFromBeginning(node*& head)
{
    if (head == NULL || head->data != 2) {
        return;
    }
    node* tmp = head;
    head = head->next;
    head->previous = NULL;
    delete tmp;
    removeTwoFromBeginning(head);
}

int removeTwo(node*& head)
{
    removeTwoFromBeginning(head);
    return 0;
}

