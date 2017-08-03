#include "table.h"

void duplicate(node* root, node*& newRoot)
{
    if (root == NULL) {
        return;
    }
    if (newRoot != NULL) {
        delete_tree(newRoot);
    }
    duplicate_recursive(root, newRoot);
    return;
}

void duplicate_recursive(node* root, node*& newRoot)
{
    if (root) {
        newRoot = new node;
        newRoot->data = root->data;
        newRoot->left = NULL;
        newRoot->right = NULL;
        duplicate_recursive(root->left, newRoot->left);
        duplicate_recursive(root->right, newRoot->right);    
    } else {
        newRoot = NULL;
    }
    return;
}

void delete_tree(node*& root)
{
    if (root == NULL) {
        return;
    }
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
    root = NULL;
    return;
}

void remove(node*& root, int target)
{
    return;
}
