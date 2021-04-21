#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include "Node.h"
#include "PriorityQueue.h"
#include <iostream>
#include <map>
#include <fstream>

class HuffmanTree
{
private:
    PriorityQueue q;
    std::map<char,std::string> codes;

public:
    HuffmanTree(PriorityQueue q);
    Node* generate_tree();
    void generate_codes(Node* root, std::string code);
    std::string encode(std::string data);
    std::string decode(Node* root,std::string data);
    bool encode(std::string input_file,std::string output_file);
    bool decode(Node* root,std::string input_file,std::string output_file);
};


HuffmanTree::HuffmanTree(PriorityQueue q)
{
    this->q = q;
}

/**
* @brief Uses the Priority Queue given to generate the Huffman Tree.
* @return A pointer to the root of the newly generated Huffman Tree.
*/
Node* HuffmanTree::generate_tree()
{
    while(this->q.get_size() != 1)
    {
        Node* left = this->q.extract_min();
        Node* right = this->q.extract_min();
        this->q.insert_value('\0',left->frequency + right->frequency, left, right);
    }

    return q.peek_top();
}

/**
* @brief Uses the generated Huffman Tree and prints the assigned codes of the symbols.
* @param root The root of the generated Huffman Tree that was returned.
* @param code The code to be generated for each symbol.
*/
void HuffmanTree::generate_codes(Node* root, std::string code = "")
{

    //This is a leaf node. Stop and print the code.
    if(root->left == NULL && root->right == NULL)
    {
        //std::cout << "Symbol: " << root->symbol << " Code: " << code << std::endl;
        this->codes[root->symbol] = code;
    }
    if(root->left)
    {
        generate_codes(root->left,code + "0");
    }
    if(root->right)
    {
        generate_codes(root->right,code + "1");
    }
}


/**
* @brief Encodes a string using the Huffman codes previously generated.
* @param data The string to be encoded.
* @return The encoded string.
*/
std::string HuffmanTree::encode(std::string data)
{
    std::string encoded;
    for(int unsigned(i) = 0; i < data.size();i++)
    {
        encoded += this->codes.find(data.at(i))->second;
    }
    return encoded;
}


/**
* @brief Encodes a string using the Huffman codes previously generated.
* @param input_file The file containing the string to be encoded.
* @param output_file The file to which the encoded string will be saved.
* @return bool If the operation was successful.
*/
bool HuffmanTree::encode(std::string input_file,std::string output_file)
{
    std::string data;
    std::fstream input;
    input.open(input_file.c_str(),std::ios::in);
    if(input.is_open())
    {
        std::getline(input,data,'\0');
        if(!data.empty())
        {
            std::fstream output;
            output.open(output_file.c_str(),std::ios::out);
            if(output.is_open())
            {
                std::string encoded = encode(data);
                output.write(encoded.c_str(),encoded.size());
                input.close();
                output.close();
                return true;
            }
            output.close();
        }
    }
    input.close();
    return false;
}


/**
* @brief Decodes a previously encoded string.
* @param root The root of the Huffman Tree.
* @param data The string to be decoded.
* @return The decoded string.
*/
std::string HuffmanTree::decode(Node* root, std::string data)
{
    std::string decoded;
    Node* traveller = root;
    for(int unsigned(i) = 0; i < data.size();i++)
    {
        traveller = (data.at(i) == '0') ? traveller->left : traveller->right;
        if(traveller->left == NULL && traveller->right == NULL)
        {
            decoded += traveller->symbol;
            traveller = root;
        }
    }
    return decoded;
}

/**
* @brief Decodes a previously encoded string.
* @param root The root of the Huffman Tree.
* @param input_file File containing the string to be decoded.
* @param output_file File to which the decoded string will be saved.
* @return If the operation was successful.
*/
bool HuffmanTree::decode(Node* root,std::string input_file,std::string output_file)
{
    std::string data;
    std::fstream input;
    input.open(input_file.c_str(),std::ios::in);
    if(input.is_open())
    {
        std::getline(input,data,'\0');
        if(!data.empty())
        {
            std::fstream output;
            output.open(output_file.c_str(),std::ios::out);
            if(output.is_open())
            {
                std::string decoded = decode(root,data);
                output.write(decoded.c_str(),decoded.size());
                input.close();
                output.close();
                return true;
            }
            output.close();
        }
    }
    input.close();
    return false;
}

#endif // BST_H_INCLUDED
