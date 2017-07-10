#include "clist.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned


    display(head); //resulting list after your function call!
    destroy(head);
    
    return 0;
}
