# Huffman Coding Implementation
This is a class project by Group B for the Analysis and Design of Algorithms class for Spring 2021. This project entails the implementation of the infamous data compressing Huffman Coding algorithm.

### Files Included
- PriorityQueue.h
- BST.h
- Node.h
- main.cpp

##### _PriorityQueue.h_
This file holds the PriorityQueue class that implements the PriorityQueue ADT. It implements it with a binary heap to maintain the order of frequencies to be used in the algorithm.

##### _BST.h_
This file holds the HuffmanTree class that builds the Huffman Tree and generates a code for each symbol when the heap is finished. It also allows the encoding and decoding of strings.

##### _Node.h_
This file stores the data type that will be used throughout the algorithm. The Node structure stores four(4) components:
- symbol
- frequency
- a pointer to a left Node
- a pointer to a right Node

##### _main.cpp_
The driver file for the program. It allows users to select between one of two options:
- Encoding and Decoding strings via the command-line
- Encoding and Decoding strings with the use of files

## Instructions on Running the Program
The program can be run in the CodeBlocks IDE by making a project and adding the files to the project and building it (RECOMMENDED). It can be used in Microsoft Visual Studio Code directly, and building and running main.cpp directly from the command-line.

### _Input and Output_
If the user selects to enter information via the command-line, they should first specify the amount of characters they wish to add. After which they add the character and associated frequency with a space in between and press ENTER. At the end of this, the code table is shown and the user can input a string made of the symbols given to see the encoded text. After which they can also enter a binary string to see the decoded text.


If the user selects to submit information with files, they should first provide a complete path to the file that contains the symbols and their associated frequencies. In this file, symbols and their frequency must be listed line by line with a space between them. Refer to frequency.txt for an example.
Subsequently, enter a path to a file that has string containing the symbols given to be encoded, and its output file path. Similarly, to decode, enter a file path to the file with the binary string to be decoded and the file path it will be outputted to.
