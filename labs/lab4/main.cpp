#include "clist.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    std::cout << "Adding 3 to the head of the list:";
    addHead(head, 3);

    display(head); //resulting list after your function call!
    destroy(head);
    
    return 0;
}
