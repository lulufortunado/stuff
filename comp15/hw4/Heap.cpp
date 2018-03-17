/*
 * Heap.cpp
 *
 * COMP15
 * Spring 2018
 * 
 *
 */
#include <iostream>
#include "Patient.h"
#include "Heap.h"
using namespace std;

// Default constructor
template<class E>
Heap<E>::Heap()
{
	length = 0;
}

// Destructor
template<class E>
Heap<E>::~Heap()
{

}

// Function: is_full
// Inputs: none
// Returns: bool
// Does: returns true if heap is full, false if not
template<class E>
bool Heap<E>::is_full() const
{
    if (length >= MAX_CAPACITY)
    {
        return true;
    }
 	  return false;
}

// Function: is_empty
// Inputs: none
// Returns: bool
// Does: returns true if heap is empty, false if not
template<class E>
bool Heap<E>::is_empty() const
{
    if (length <= 0)
    {
        return true;
    }
    return false;
}

// Function: insert_item
// Inputs: E
// Returns: nothing
// Does: Inserts new item onto heap and then restores heap properties
// by calling heapify_up. Updates length and checks if heap is full before
// doing an insertion.
template<class E>
void Heap<E>::insert_item(E item)
{
    if (is_full())
    {
    	throw FullHeap();
    }
    else
    {
    	heap[length] = item;
   	 	length++; 
    	heapify_up(length-1);
    }
}

// Function: extract
// Inputs: nothing
// Returns: E
// Does: removes root item of heap, then restores heap properties by 
// calling heapify_down. Updates length and checks if heap is empty before 
// doing removal. Returns root item.
template<class E>
E Heap<E>::extract()
{
    if (is_empty())
    {
    	throw EmptyHeap();
    }
    else
    {
   		E root = heap[0];
   		heap[0] = heap[length-1];
   		length--;
   		heapify_down(0);
   		return root;
   	}
}

// Function: get_parent_index
// Inputs: int
// Returns: int
// Does: returns index of parent of node with passed index
template<class E>
int Heap<E>::get_parent_index(int index) const
{
  if (index == 0)
  {
  	return 0;
  }

  return (index - 1)/2;
}

// Function: get_children_indices
// Inputs: int, int by reference, int by reference
// Returns: nothing
// Does: sets the passed parameters that are passed by reference 
// (leftchild & rightchild), 
// to the indeces of the children of the node with the passed index
template<class E>
void Heap<E>::get_children_indices(int index, int & leftchild, 
												int & rightchild) const
{
 	leftchild = 2*index + 1;
 	rightchild = 2*index + 2;

}

// Function: get_value_at
// Inputs: int
// Returns: value at the passed index unless heap is empty
// If heap is empty throws EmptyHeap exception
template<class E>
E Heap<E>::get_value_at(int index)
{
  if (is_empty())
  {
      throw EmptyHeap();
  }
  else
  {
   		return heap[index];
  }
}


// print the heap and length of heap
template<class E>
void Heap<E>::print()
{
	cout << "length: " << length << endl;

	for (int i = 0; i < length; i++)
	{
		cout << heap[i] << " " << endl;
	}
	cout << endl;
}

// Declare the data types we can use with the template class
template class Heap<Patient>;
template class Heap<int>;
template class Heap<double>;

 