#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <string>
struct Node {
    std::string data;
    std::string code;
    int frequency;
    Node* left;
    Node* right;
    Node* parent;
};


#endif // NODE_H_INCLUDED
