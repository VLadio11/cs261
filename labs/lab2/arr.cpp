#include "arr.h"

int sum(node* head[])
{
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        node* curr = head[i];
        while (curr != NULL) {
            sum += curr->data;
            curr = curr->next;
        }
    }
    return sum;
}