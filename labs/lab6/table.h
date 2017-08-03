//list.h
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
void duplicate(node* root, node*& newRoot);
void remove(node*& root, int target);

// Helpers
int get_leaf_value(node* root);
int get_root_data(node* root);
void duplicate_recursive(node* root, node*& newRoot);
void delete_tree(node*& root);
node*& get_min_value_node(node*& root);

