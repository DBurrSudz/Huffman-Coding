#include <iostream>
#include "PriorityQueue.h"
#include "BST.h"

int main()
{
    Node symbol1 = {"a",23,NULL,NULL};
    Node symbol2 = {"b",89,NULL,NULL};
    Node symbol3 = {"c",2,NULL,NULL};
    Node symbol4 = {"d",24,NULL,NULL};
    Node symbol5 = {"e",24,NULL,NULL};
    Node symbol6 = {"f",10,NULL,NULL};
    Node arr[] = {symbol1,symbol2,symbol3,symbol4,symbol5,symbol6};
    PriorityQueue queue(arr,6);

    HuffmanTree tree(queue);
    Node* root = tree.generate_tree();
    //tree.generate_codes(root);
    tree.print_breadth(root);

    return 0;
}
