#include <iostream>
#include "PriorityQueue.h"
#include "BST.h"


PriorityQueue q;
int frequency;
char symbol;


int show_menu()
{
    int option;
    std::cout << "Please select one of the following methods of input: " << std::endl;
    std::cout << "1. CMD\n2. File" << std::endl;
    std::cin >> option;
    return option;
}

void cmd_menu()
{
    int total;
    std::string data;
    std::cout << "How many symbols will you be entering? ";
    std::cin >> total;
    std::cout << "Please enter your symbols and their associated frequencies separated by a space." << std::endl;
    for(int i = 0; i < total; i++)
    {
        std::cin >> symbol >> frequency;
        q.insert_value(symbol,frequency,NULL,NULL);
    }
    HuffmanTree tree(q);
    Node* root = tree.generate_tree();
    tree.generate_codes(root);
    std::cout << "Using the symbols given, please enter a string to encode: ";
    std::cin.ignore();
    std::getline(std::cin,data);
    std::string output = tree.encode(data);
    std::cout << "Encoded Data is: " << output;

    std::cout << "\nWell done, now please enter a string to decode: ";
    std::getline(std::cin,data);
    output = tree.decode(root,data);
    std::cout << "Decoded Data is: " << output;
}

void file_menu()
{
    std::string file,input,output;
    std::cout << "Please enter the path to the file with the list of symbols and codes: ";
    std::cin.ignore();
    std::getline(std::cin,file);

    std::fstream frequencies;
    frequencies.open(file.c_str(),std::ios::in);
    if(frequencies.is_open())
    {
        while(frequencies >> symbol >> frequency)
        {
            q.insert_value(symbol,frequency,NULL,NULL);
        }
        HuffmanTree tree(q);
        Node* root = tree.generate_tree();
        tree.generate_codes(root);
        std::cout << "The codes have been generated. File to encode: ";
        std::getline(std::cin,input);
        std::cout << "File to Generate: ";
        std::getline(std::cin,output);

        if(tree.encode(input,output)) std::cout << "Encoding Finished.";

        std::cout << "\nWell done. Now, file to decode: ";
        std::getline(std::cin,input);
        std::cout << "File to Generate: ";
        std::getline(std::cin,output);

        if(tree.decode(root,input,output)) std::cout << "Decoding Finished.";
    }

    frequencies.close();
}


int main()
{

    int choice = show_menu();

    while(choice != 1 && choice != 2)
    {
        std::cout << "Please enter a valid option!" << std::endl;
        std::cin >> choice;
    }

    if(choice == 1) cmd_menu();
    else file_menu();
    return 0;
}
