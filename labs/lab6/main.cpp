#include "table.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Phil Stephenson - CS261" << endl;
    node * root = NULL;
    build(root);
    display(root);

    /*  PLACE YOUR FUNCTION CALL HERE */
    node* newRoot = NULL;
    cout << endl << "*********** Duplicate tree ************";
    duplicate(root, newRoot);
    display(newRoot);
    cout << "***************************************" << endl;
    destroy(newRoot);

    int leaf_value = get_leaf_value(root);
    cout << "Removing leaf node with value: " << leaf_value << endl;
    remove(root, leaf_value);
    display(root);

    int root_value = get_root_data(root);
    cout << "Removing root node with value: " << root_value << endl;
    remove(root, root_value);

    display(root);
    destroy(root);
    return 0;
}
