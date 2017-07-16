#include "list.h"

void duplicate(node * head, node *& newHead)
{
    if (head) {
        newHead = new node;
        newHead->data = head->data;
        newHead->next = NULL;
        duplicate(head->next, newHead->next);
    } else {
        newHead = NULL;
    }
}

node* removeTwoRecursive(node *& head)
{
    if (head == NULL) {
        return NULL;
    } else {
        if (head->data == 2) {
            node* newHead = head->next;
            delete head;
            return removeTwoRecursive(newHead);
        } else {
            head->next = removeTwoRecursive(head->next);
            return head;
        }
    }
}

int removeTwo(node*& head)
{
    node* curr = head;
    // First, iteratively remove any 2s at the beginning of the list
    while (curr != NULL && curr->data == 2) {
        head = curr->next;
        delete curr;
        curr = head;
    }
    removeTwoRecursive(head);
    return 0;
}
