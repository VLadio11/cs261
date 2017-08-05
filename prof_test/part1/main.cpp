#include "dlist.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    int listSize = getListSize(head);
    int intArray[listSize];
    for (int i = 0; i < listSize; i++) {
        intArray[i] = 0;
    }
    cout << "Copying list into intArray...";
    copyToArray(head, intArray);

    cout << "Removing the first and last nodes..." << endl;
    int count = removeEnds(head);
    cout << "Removed " << count << " nodes";

    display(head);
    destroy(head);    
    return 0;
}
