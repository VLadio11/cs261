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

int removeTwo(node* head[])
{
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        node* curr = head[i];
        while (curr != NULL && curr->data == 2) {
            head[i] = curr->next;
            delete curr;
            curr = head[i];
            count++;
        }

        node* prev;
        while (curr != NULL) {
            while (curr != NULL && curr->data != 2) {
                prev = curr;
                curr = curr->next;
            }

            if (curr == NULL) {
                return count;
            }
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
            count++;
        }
    }

    return count;
}