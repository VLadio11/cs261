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

int get_leaf_value(node* root)
{
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return root->data;
    } else if (root->left == NULL) {
        return get_leaf_value(root->right);
    } else {
        return get_leaf_value(root->left);
    }
}

int get_root_data(node* root)
{
    return root->data;
}

node*& get_min_value_node(node*& root)
{
    if (root->left == NULL) {
        return root;
    }
    return get_min_value_node(root->left);
}

void remove(node*& root, int target)
{
    if (root == NULL) {
        return;
    }
    if (target < root->data) {
        remove(root->left, target);
    } else if (target > root->data) {
        remove(root->right, target);
    } else {
        if (root->left == NULL) {
            node* tmp = root->right;
            delete root;
            root = tmp;
        } else if (root->right == NULL) {
            node* tmp = root->left;
            delete root;
            root = tmp;
        } else {
            node* tmp = get_min_value_node(root->right);
            root->data = tmp->data;
            remove(root->right, target);
        }
        return;
    }
    return;
}

