#include "dlist.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    node* copy = NULL;
    cout << "Copying list...";
    duplicate(head, copy);
    display(copy);
    destroy(copy);

    display(head);
    destroy(head);    
    return 0;
}
