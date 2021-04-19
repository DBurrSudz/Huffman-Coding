#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include "Node.h"
#include "PriorityQueue.h"
#include <iostream>
#include <queue>

class HuffmanTree
{
private:
    PriorityQueue q;
    Node create_node(const int frequency, Node* left, Node* right);


public:
    HuffmanTree(PriorityQueue q);
    Node* generate_tree();
    void generate_codes(Node* root, std::string code);
    void print_breadth(Node* root);
};


HuffmanTree::HuffmanTree(PriorityQueue q)
{
    this->q = q;
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

Node* HuffmanTree::generate_tree()
{
    while(this->q.get_size() != 1)
    {
        Node* left = this->q.extract_min();
        Node* right = this->q.extract_min();

        Node parent = create_node(left->frequency + right->frequency, left, right);
        this->q.insert_value(parent);
    }

    return q.peek_top();
}

void HuffmanTree::generate_codes(Node* root, std::string code = "")
{
    if(root->left == NULL && root->right == NULL)
    {
        std::cout << "Symbol: " << root->data << " Code: " << code << std::endl;
        return;
    }
    if(root->left != NULL)
    {
        code.append("0");
        generate_codes(root->left,code);
    }
    if(root->right != NULL)
    {
        code.append("1");
        generate_codes(root->right,code);
    }
}

void HuffmanTree::print_breadth(Node* root)
{
    if(root->left == NULL && root->right == NULL) return;
    else
    {
        std::queue<Node*> qu;
        qu.push(root);
        while(!qu.empty())
        {
            Node* frontv = qu.front();
            qu.pop();
            std::cout << frontv->data << "  " << frontv->frequency << std::endl;
            if(frontv->left != NULL) qu.push(frontv->left);
            if(frontv->right != NULL) qu.push(frontv->right);
        }
    }
}

#endif // BST_H_INCLUDED
