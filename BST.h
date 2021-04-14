#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include "Node.h"
#include "PriorityQueue.h"

class HuffmanTree
{
private:
    PriorityQueue q;
    Node* root;
    Node create_node(const int frequency, Node* left, Node* right);


public:
    HuffmanTree(PriorityQueue q);
    void generate_tree();
    void generate_codes();
};


HuffmanTree::HuffmanTree(PriorityQueue q)
{
    this->q = q;
    this->root = NULL;
}

/**
* @brief Creates a new node using left and right as both children and their combined frequencies as the new frequency.
* @param frequency The combined frequencies of the left and right children.
* @param left A pointer to the left child.
* @param right A pointer to the right child.
* @return The newly created node.
*/
Node HuffmanTree::create_node(const int frequency, Node* left, Node* right)
{
    Node new_node = {"\0",frequency,left,right};
    return new_node;
}

void HuffmanTree::generate_tree()
{
    while(this->q.get_size() != 1)
    {
        Node* left = this->q.extract_min();
        Node* right = this->q.extract_min();

        Node parent = create_node(left->frequency + right->frequency, left, right);
        this->q.insert_value(parent);
    }

    this->root = this->q.peek_top();
}


#endif // BST_H_INCLUDED
