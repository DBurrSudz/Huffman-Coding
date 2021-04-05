#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED

#include "Node.h"
#include <vector>
class PriorityQueue
{
private:
    std::vector<Node> heap;
    void sift_up(int index);
    void sift_down(int index);
    void heapify();
    bool empty();
    int get_left_child(int curr_indx);
    int get_right_child(int curr_indx);
    int get_parent(int curr_indx);
    bool within_heap_range(int curr_indx);

public:
    PriorityQueue();
    PriorityQueue(int Arr[], const int SIZE);
    void insert_value(Node new_node);
    Node extract_min();
};

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
        int left_child = 2 * curr_indx;
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
        int right_child = (2 * curr_indx) + 1;
        return right_child;
    }

    return -1;
}

void PriorityQueue::sift_up(int index)
{
    //int parent = get_parent(index);
}

void PriorityQueue::insert_value(Node new_value)
{
    int insert_index = heap.size();
    heap[insert_index] = new_value;
    sift_up(insert_index);
}




#endif // PRIORITYQUEUE_H_INCLUDED
