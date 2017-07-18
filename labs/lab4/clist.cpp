// Phil Stephenson
#include "clist.h"

void addHead(node*& head, int value)
{
    node* newNode = new node;
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        newNode->next = newNode;
        return;
    }

    node* curr = head;
    while (curr->next != head) {
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->next = head;
    head = newNode;
    return;
}

void myDisplay(node* head)
{
    node* curr = head;
    std::cout << curr->data << " -> ";
    curr = curr->next;
    while (curr != head) {
        std::cout << curr->data << " -> ";
        curr = curr->next;
    }
    std::cout << curr->data << std::endl;
    return;
}
