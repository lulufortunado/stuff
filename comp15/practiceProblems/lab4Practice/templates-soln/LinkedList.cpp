#include <iostream>
#include "LinkedList.h"
using namespace std;

// Default constructor
template<class E>
LinkedList<E>::LinkedList()
{
    head = NULL;
}

// Destructor
template<class E>
LinkedList<E>::~LinkedList()
{
    NodeType<E> *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// Assignment operator
template<class E>
LinkedList<E> & LinkedList<E>::operator = (const LinkedList<E> &l)
{
    NodeType<E> *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    if (l.head == NULL)
        head = NULL;
    else
    {
        try
        {
            head = new NodeType<E>;
            head->value = l.head->value;
            head->next = NULL;
            NodeType<E> *curr = head;
            NodeType<E> *orig = l.head;
            while (orig->next != NULL)
            {
                curr->next = new NodeType<E>;
                curr->next->value = orig->next->value;
                curr->next->next = NULL;
                orig = orig->next;
                curr = curr->next;
            }
        }
        catch (bad_alloc exception)
        {
            cerr << "Failed to copy list, out of memory\n";
        }
    }
    return *this;
}

// Copy constructor 
template<class E>
LinkedList<E>::LinkedList(const LinkedList<E> &l)
{
    if (l.head == NULL)
        head = NULL;
    else
    {
        try
        {
            head = new NodeType<E>;
            head->value = l.head->value;
            head->next = NULL;
            NodeType<E> *curr = head;
            NodeType<E> *orig = l.head;
            while (orig->next != NULL)
            {
                curr->next = new NodeType<E>;
                curr->next->value = orig->next->value;
                curr->next->next = NULL;
                orig = orig->next;
                curr = curr->next;
            }
        }
        catch (bad_alloc exception)
        {
            cerr << "Failed to copy list, out of memory\n";
        }
    }
}

// Function print
// Parameters: none
// Returns: nothing
// Does: Prints each element of the list,
//       space separated
template<class E>
void LinkedList<E>::print(ostream &out) const
{
    NodeType<E> *temp = head;
    while (temp != NULL)
    {
        out << temp->value << " ";
        temp = temp->next;
    }
    out << endl;
}

// Function delete_value_at
// Input: integer, position to remove
// Returns: nothing
// Does: Removes the element at given position,
//       deallocates memory, and updates pointers
template<class E>
void LinkedList<E>::delete_value_at(int index)
{
    if (get_length() == 0 || index >= get_length()) 
    {
        return;
    }

    NodeType<E> *temp, *current = head;
    int current_index = 1;

    // Special case: delete the head
    if (index == 0)
    {
        temp = current;
        head = head->next;
    }
    else
    {
        while (current_index < index)
        {
            current = current->next;
            current_index++;
        }
        temp = current->next;
        current->next = current->next->next;
    }
    delete temp;
}

// Function get_length, const
// Parameters: None
// Returns: int, the length of the list
template<class E>
int LinkedList<E>::get_length() const
{
    NodeType<E> *current = head;
    int count = 0;
    while (current != NULL) 
    {
        count++;
        current = current->next;
    }
    return count;
}

// Check for empty list (compared head to NULL)
template<class E>
bool LinkedList<E>::is_empty() const
{
    return (head == NULL);
}

// Check for full list
// (attempt to allocate memory)
template<class E>
bool LinkedList<E>::is_full() const
{
    try
    {
        NodeType<E> *temp = new NodeType<E>;
        delete temp;
        return false;
    }
    catch (bad_alloc exception)
    {
        return true;
    }
}

// Function get_value_at, const
// Parameters: int, an index
// Returns: value at that index
//          or FAIL value if not found
template<class E>
E LinkedList<E>::get_value_at(int index) const
{
    if (is_empty())
        throw EmptyList();
    NodeType<E> *current = head;
    int current_index = 0;

    while ((current_index < index) && (current != NULL)) 
    {
        current = current->next;
        current_index++;
    }
    if (current == NULL) 
    {
        return FAIL;
    }

    return current->value;
}

// Function insert
// Input: Integer
// Returns: None
// Does: Creates new NodeType for value, inserts
//       at front of list
template<class E>
void LinkedList<E>::insert(E value)
{
    if (is_full())
        throw FullList();
    NodeType<E> *temp = new NodeType<E>;
    temp->value = value;
    temp->next = head;
    head = temp;
}

// Function make_empty
// Parameters: none
// Returns: none
// Does: iterates through the list, deallocating
//       NodeType elements as we go
template<class E>
void LinkedList<E>::make_empty()
{
    NodeType<E> *temp = head;
    NodeType<E> *next_ptr = head->next;

    while (temp != NULL)
    {
        delete temp;
        temp = next_ptr;

        if (next_ptr != NULL)
            next_ptr = next_ptr->next;
    }
    head = NULL;
}

template class LinkedList<int>;
template class LinkedList<double>;

