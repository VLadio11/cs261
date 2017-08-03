#include "table.h"
#include <iostream>

using namespace std;

int main()
{
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

    display(root);
    destroy(root);
    return 0;
}
