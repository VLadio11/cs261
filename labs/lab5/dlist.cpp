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

node* removeTwoRecursive(node*& head)
{
    if (head == NULL) {
        return NULL;
    } else {
        if (head->data == 2) {
            if (head->next == NULL) {
                head = NULL;
                delete head;
                return NULL;
            } else {
                node* tmp = head;
                head = head->next;
                head->previous = tmp->previous;
                delete tmp;
                return removeTwoRecursive(head);
            }
        } else {
            return removeTwoRecursive(head->next);
        }
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
    removeTwoRecursive(head);
    return 0;
}

