/*
 * MaxHeap.h
 *
 * COMP15
 * Spring 2018
 *
 * Derived class for MaxHeap type
 * Inherits from abstract Heap class
 *
 *
 *
 */

#include "Heap.h"

#ifndef MAXHEAP_H_
#define MAXHEAP_H_

template<class E> class MaxHeap : public Heap<E>
{
public:
    MaxHeap();
    ~MaxHeap();
    
    // Overriding purely virtual functions
    void heapify_up(int);
    void heapify_down(int);
};

#endif
