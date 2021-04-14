#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
//Daniel
#include <string>
struct Node {
    std::string data;
    int frequency;
    Node* left;
    Node* right;
};


#endif // NODE_H_INCLUDED
