/*
 * MaxHeap.cpp
 *
 * COMP15
 * Spring 2018
 * 
 *
 */
#include <iostream>
#include "Patient.h"
#include "MaxHeap.h"
using namespace std;


// Default constructor
template<class E>
MaxHeap<E>::MaxHeap()
{
	Heap<E>::length = 0;
}

// Destructor
template<class E>
MaxHeap<E>::~MaxHeap()
{

}

// Function heapify_up
// Inputs: int
// Returns: nothing
// Does: It compares the item at the passed index to its 
// parent, and swaps the passed item with its parent if it is larger
// than its parent. The index passed in starts at length-1 of the array
// the heap uses to store its values, and the function recurses up through
// the parent index until we hit the root, at index 0
template<class E>
void MaxHeap<E>::heapify_up(int index)
{
    if (index == 0)
    {
    	return;
    }
    int pindex = Heap<E>::get_parent_index(index);

 	if (Heap<E>::heap[index] > Heap<E>::heap[pindex])
 	{
 		E ptemp = Heap<E>::heap[pindex];
 		Heap<E>::heap[pindex] = Heap<E>::heap[index];
 		Heap<E>::heap[index] = ptemp;
 	}

 	heapify_up(pindex);
 
}

// Function heapify_down
// Inputs: int
// Returns: nothing
// Does: takes an index and compares the value of the item at 
// that index to the values of its children. If the children are larger
// than the parent, the parent is swapped with the larger of the children.
// If the children are both larger than the parent and equal to each other, 
// we always swap witht he left child for consistency.
// The index passed in starts at the root, at 0, and then the function 
// recurses through the children until we hit the last non-leaf node (at
// index length)/2 -1). We also handle length of 2 as a special case when there
// is always eactly one child.
template<class E>
void MaxHeap<E>::heapify_down(int index)
{
	if (index > (Heap<E>::length)/2 -1)
    {
    	return;
    }
    if (Heap<E>::length == 2)
    {
    	E temp = Heap<E>::heap[0];

    	if (Heap<E>::heap[1] > temp)
    	{
    		Heap<E>::heap[0] = Heap<E>::heap[1];
    		Heap<E>::heap[1] = temp;
    	}
    	return;
    }

    int leftchild, rightchild;
    int swapindex = -1;

 	Heap<E>::get_children_indices(index, leftchild, rightchild);


 	if (Heap<E>::heap[leftchild] > Heap<E>::heap[index] ||
 						Heap<E>::heap[rightchild] > Heap<E>::heap[index])

 	{
 		if (Heap<E>::heap[rightchild] == Heap<E>::heap[leftchild])
 		{
 			swapindex = leftchild;
 		}

 		else if (Heap<E>::heap[leftchild] > Heap<E>::heap[rightchild])
 		{
 			swapindex = leftchild;
 		}

 		else if (Heap<E>::heap[rightchild] > Heap<E>::heap[leftchild])
 		{
 			swapindex = rightchild;
 		}

 	}
 	if (swapindex != -1)
 	{
 		E temp = Heap<E>::heap[index];
 		Heap<E>::heap[index] = Heap<E>::heap[swapindex];
 		Heap<E>::heap[swapindex] = temp;
 		heapify_down(swapindex);
 	}
}

// Declare the data types we can use with the template class
template class MaxHeap<Patient>;
template class MaxHeap<int>;
template class MaxHeap<double>;