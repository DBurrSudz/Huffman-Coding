#include <iostream>
#include "PriorityQueue.h"

int main()
{
    std::cout << "Hello World" << std::endl;
    Node symbol1 = {"a",23};
    Node symbol2 = {"b",89};
    Node symbol3 = {"c",2};
    Node symbol4 = {"d",32};
    Node symbol5 = {"e",24};
    Node symbol6 = {"f",1};
    PriorityQueue queue;
    queue.insert_value(symbol1);
    queue.insert_value(symbol2);
    queue.insert_value(symbol3);
    queue.insert_value(symbol4);
    queue.insert_value(symbol5);
    queue.insert_value(symbol6);

    for(int i = 0; i < queue.get_size(); i++)
    {
        std::cout << queue.get_value(i).data << std::endl;
    }

    std::cout << "The first smallest value is: " << queue.extract_min().data << std::endl;
    std::cout << "The second smallest value is: " << queue.extract_min().data << std::endl;
    std::cout << "The second smallest value is: " << queue.extract_min().data << std::endl;
    std::cout << queue.get_size();
    return 0;
}
