#include <iostream>
#include "PriorityQueue.h"
#include "BST.h"

int main()
{
    Node symbol1 = {"a",23};
    Node symbol2 = {"b",89};
    Node symbol3 = {"c",2};
    Node symbol4 = {"d",24};
    Node symbol5 = {"e",24};
    Node symbol6 = {"f",10};
    Node arr[] = {symbol1,symbol2,symbol3,symbol4,symbol5,symbol6};
    PriorityQueue queue(arr,6);

    for(int i = 0; i < queue.get_size(); i++)
    {
        std::cout << queue.get_value(i)->data << std::endl;
    }

    return 0;
}
