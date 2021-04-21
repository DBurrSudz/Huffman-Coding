#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED

#include "Node.h"
#include <vector>
class PriorityQueue
{
private:
    std::vector<Node*> heap;
    void sift_up(int index);
    Node* create_node(char symbol, int frequency, Node* left, Node* right);
    void sift_down(int index);
    void heapify();
    int get_left_child(int curr_indx);
    int get_right_child(int curr_indx);
    int get_parent(int curr_indx);
    bool within_heap_range(int curr_indx);


public:
    PriorityQueue();
    PriorityQueue(Node* Arr[], const int SIZE);
    void insert_value(char symbol, int frequency, Node* left, Node* right);
    Node* extract_min();
    int get_size();
    Node* get_value(int index);
    Node* peek_top();

};

//Constructors

/**
* @brief Default constructor for the PriorityQueue class
*/
PriorityQueue::PriorityQueue() {}


/**
* @brief Constructor for the PriorityQueue class
* @param Arr An array of Nodes.
* @param The size of the array.
*/
PriorityQueue::PriorityQueue(Node* Arr[], const int SIZE)
{
    for(int i = 0; i < SIZE; i++)
    {
        heap.push_back(Arr[i]);
    }
    heapify();
}


Node* PriorityQueue::create_node(char symbol, int frequency, Node* left, Node* right)
{
    Node* new_node = new Node();
    new_node->symbol = symbol;
    new_node->frequency = frequency;
    new_node->left = left;
    new_node->right = right;
    return new_node;
}



/**
* @brief Checks if a given index is within the range of the heap.
* @param curr_indx The index to be checked.
* @return If the index is in the heap range.
*/
bool PriorityQueue::within_heap_range(int curr_indx)
{
    if(curr_indx >= 0 && unsigned(curr_indx) <= heap.size() - 1) return true;
    else return false;
}


/**
* @brief Gets the parent of a given index.
* @param curr_indx The child index.
* @return The parent index.
*/
int PriorityQueue::get_parent(int curr_indx)
{
    //The index given is the root of the binary heap or it exists outside its range
    if(curr_indx == 0 || (!within_heap_range(curr_indx)))
    {
        return -1;
    }

    int parent = (curr_indx - 1)/2;
    return parent;
}


/**
* @brief Gets the left child of a given parent.
* @param curr_indx Index of the parent.
* @return Index of the left child.
*/
int PriorityQueue::get_left_child(int curr_indx)
{
    if(within_heap_range(curr_indx))
    {
        int left_child = (2 * curr_indx) + 1;
        return left_child;
    }
    return -1;
}


/**
* @brief Gets the right child of a given parent.
* @param curr_indx Index of the parent.
* @return Index of the right child.
*/
int PriorityQueue::get_right_child(int curr_indx)
{
    if(within_heap_range(curr_indx))
    {
        int right_child = (2 * curr_indx) + 2;
        return right_child;
    }

    return -1;
}


/**
* @brief Maintains "min-heap" property by comparing children to their parents.
* @param index Index to be compared with parent.
*/
void PriorityQueue::sift_up(int index)
{
    //Base Case: Stop if its the root.
    if(within_heap_range(index) && index != 0)
    {
        int parent = get_parent(index);

        if (heap[index]->frequency <= heap[parent]->frequency)
        {
            Node* temp = heap[index];
            heap[index] = heap[parent];
            heap[parent] = temp;
            sift_up(parent);
        }
    }
}

/**
* @brief Maintains "min-heap" property by comparing a parent to its children.
* @param index Index to be compared with children.
*/
void PriorityQueue::sift_down(int index)
{
    //Base Case: Stop if its the last element of the list.
    if(within_heap_range(index) && unsigned(index) != heap.size() - 1)
    {
        int left_child = get_left_child(index);
        int right_child = get_right_child(index);
        int min_child;

        //The node has both a left and right child in the binary heap.
        if(within_heap_range(left_child) && within_heap_range(right_child))
        {
            min_child = (heap[left_child]->frequency < heap[right_child]->frequency) ? left_child : right_child;
        }

        //If the there is no right child for this Node, the min child is by default its left child.
        else if(within_heap_range(left_child) && !(within_heap_range(right_child))) min_child = left_child;

        else return; //Both children do not not exist in the heap.

        if(heap[index]->frequency >= heap[min_child]->frequency)
        {
            Node* temp = heap[min_child];
            heap[min_child] = heap[index];
            heap[index] = temp;
            sift_down(min_child);
        }
    }
}


/**
* @brief Converts a given array to a binary heap.
*
*/
void PriorityQueue::heapify()
{
    for(int i = unsigned((heap.size() - 1)/2); i >= 0; i--)
    {
        sift_down(i);
    }
}


/**
* @brief Inserts a value into the heap. Attempts to maintain minheap property after insertion.
* @param new_value The new value to be entered.
*/
void PriorityQueue::insert_value(char symbol, int frequency, Node* left, Node* right)
{
    heap.push_back(create_node(symbol,frequency,left,right));
    int insert_index = heap.size() - 1;
    sift_up(insert_index);
}


/**
* @brief Removes the element of highest priority in the heap. Attempts to maintain minheap property after extraction.
* @return The element having highest priority.
*/
Node* PriorityQueue::extract_min()
{
    if(heap.size() == 0) return NULL;
    Node* data_out;

    if(heap.size() == 1)
    {
        data_out = heap[0];
        heap.pop_back();
    }
    else
    {
        int last_index = heap.size() - 1;
        Node* temp = heap[last_index];
        heap[last_index] = heap[0];
        heap[0] = temp;
        data_out = heap[last_index];
        heap.pop_back();
        sift_down(0);
    }
    return data_out;
}

/**
* @brief Gets the size of the heap.
* @return The size of the heap.
*/
int PriorityQueue::get_size() {return heap.size();}

Node* PriorityQueue::get_value(int index)
{
    if(within_heap_range(index)) return heap[index];
    else return NULL;
}

/**
* @brief Returns the element at the top of the queue. This method does not extract the smallest value
*        so the min-heap property is not violated.
* @return The node at the top of the heap.
*/
Node* PriorityQueue::peek_top()
{
    if(heap.size() == 0) return NULL;
    return heap[0];
}


#endif // PRIORITYQUEUE_H_INCLUDED
