#include "table.h"
// Phil Stephenson

//Please put the impelementation of the required functions here
int copyToArray(node* root, int intArray[])
{
    if (root == NULL) {
        return 0;
    }
    int index = 0;
    return copyToArray(root, intArray, index);
}

int copyToArray(node* root, int intArray[], int& index)
{
    if (root == NULL) {
        return index;
    }
    copyToArray(root->left, intArray, index);
    intArray[index++] = root->data;
    copyToArray(root->right, intArray, index);
    return index;
}

int countNodes(node* root, int& count)
{
    if (root == NULL) {
        return count;
    }
    count++;
    countNodes(root->left, count);
    countNodes(root->right, count);
    return count;
}

void copyNonLeafRecursive(node* root, node*& newRoot)
{
    if (root && (root->left || root->right)) {
        node* n = new node;
        n->data = root->data;
        n->left = NULL;
        n->right = NULL;
        newRoot = n;
        copyNonLeaf(root->left, newRoot->left);
        copyNonLeaf(root->right, newRoot->right);
    } else {
        newRoot = NULL;
    }
    return;
}

void copyNonLeaf(node* root, node*& newRoot)
{
    if (newRoot != NULL) {
        deleteTree(newRoot);
    }
    copyNonLeafRecursive(root, newRoot);
    return;
}

void deleteTree(node*& root)
{
    if (root == NULL) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = NULL;
    return;
}
    
