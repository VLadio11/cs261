#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    node* copy = NULL;
    duplicate(head, copy);
    cout << "Displaying copy:";
    display(copy);
    destroy(copy);

    cout << "Removing all 2's";
    removeTwo(head);

    display(head);
    destroy(head);
    
    return 0;
}
