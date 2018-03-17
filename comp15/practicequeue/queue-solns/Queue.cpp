#include "Queue.h"
#include <cstddef>
#include <new>

Queue::Queue()
{
    front = NULL;
    rear = NULL;
}

Queue::~Queue()
{
    NodeType *temp;

    while (front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
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

bool Queue::is_empty() const
{
    return (front == NULL);
}

void Queue::enqueue(int new_item)
{
    if (is_full())
        throw FullQueue();
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

void Queue::dequeue(int &item)
{
    if (is_empty())
        throw EmptyQueue();
    else
    {
        NodeType *temp;
        temp = front;
        item = front->value;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete temp;
    }
}


