#include "dlist.h"

//put the implmenetation of the required functions here
int copyToArray(node* head, int intArray[])
{
    return copyToArray(head, intArray, 0);
}

int copyToArray(node* head, int intArray[], int index)
{
    if (head == NULL) {
        return 0;
    }
    intArray[index] = head->data;
    return copyToArray(head->next, intArray, index + 1) + 1;
}

int getListSize(node* head)
{
    if (head == NULL) {
        return 0;
    }
    return getListSize(head->next) + 1;
}

int removeEnds(node*& head)
{
    if (head == NULL) {
        return 0;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return 1;
    } else {
        node* tmp = head->next;
        delete head;
        head = tmp;
        head->previous = NULL;
    }
    return removeLastNode(head) + 1;
}

int removeLastNode(node*& head)
{
    if (head == NULL) {
        return 0;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return 1;
    }
    return removeLastNode(head->next);
}
