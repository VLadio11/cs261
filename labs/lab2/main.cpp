#include "arr.h"
using namespace std;

int main()
{
    node * head[SIZE] = {0,0,0,0,0};
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    cout << "sum of all integers:" << sum(head) << endl;

    display(head);
    destroy(head);
    
    return 0;
}
