#ifndef TABLE_H
#define TABLE_H
//table.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;
    node * left;
    node * right;;
};

void build(node * & root);  //supplied
void display(node *  root); //supplied
void destroy(node * & root); //supplied

/* ************** PLACE YOUR PROTOTYPE HERE ***************** */
int copyToArray(node* root, int intArray[]);
int copyToArray(node* root, int intArray[], int& index);
void copyNonLeaf(node* root, node*& newRoot);
void copyNonLeafRecursive(node* root, node*& newRoot);
void deleteTree(node*& root);
int countNodes(node* root, int& count);
 
#endif
