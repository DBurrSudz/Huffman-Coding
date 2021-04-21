#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include <string>
struct Node {
    char symbol;
    int frequency;
    Node* left;
    Node* right;
};


#endif // NODE_H_INCLUDED
