#include "table.h"

#include <iostream>

using namespace std;

int main()
{
    node * root = NULL;
    build(root);
    display(root);

    /*  PLACE YOUR FUNCTION CALL HERE */

    int nodes = 0;
    int count = countNodes(root, nodes);
    int intArray[count];
    for (int i = 0; i < count; i++) {
        intArray[i] = 0;
    }
    cout << "Copying the tree into an array..." << endl;
    copyToArray(root, intArray);
    for (int i = 0; i < count; i++) {
        cout << intArray[i] << endl;
    }

    node* newRoot = NULL;
    cout << "Duplicating tree (except for leaf nodes):" << endl;
    copyNonLeaf(root, newRoot);
    display(newRoot);
    destroy(newRoot);

    display(root);
    destroy(root);
    return 0;
}
