#include "Queue.h"
#include <cstddef>
#include <new>

Queue::Queue()
{
    front = NULL;
    rear = NULL;
}

bool Queue::is_full() const
{
    NodeType *location;
    try 
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }
}


void Queue::enqueue(int new_item)
{
    if (is_full())
        throw FullStack();
    else
    {
        NodeType *new_node;
        new_node = new NodeType;
        new_node->value = new_item;
        new_node->next = NULL;
        if (rear == NULL)
            front = new_node;
        else
            rear->next = new_node;
        rear = new_node;
    }
}



