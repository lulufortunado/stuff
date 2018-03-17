#include <iostream>
#include "LLPractice.h"
using namespace std;

// Default constructor
LLPractice::LLPractice()
{
    head = NULL;
}

// Function print
// Parameters: none
// Returns: nothing
// Does: Prints each element of the list,
//       space separated
void LLPractice::print() const
{
    NodeType *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function delete_value_at
// Input: integer, position to remove
// Returns: nothing
// Does: Removes the element at given position,
//       deallocates memory, and updates pointers
void LLPractice::delete_value_at(int index)
{
    if (get_length() == 0 || index >= get_length()) 
    {
        return;
    }

    NodeType *temp, *current = head;
    int current_index = 0;

    // Special case: delete the head
    if (index == head->value)
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
int LLPractice::get_length() const
{
    NodeType *current = head;
    int count = 0;
    while (current != NULL) 
    {
        count++;
        current = current->next;
    }
    return count;
}

// Function get_value_at, const
// Parameters: int, an index
// Returns: value at that index
//          or FAIL value if not found
int LLPractice::get_value_at(int index) const
{
    NodeType *current = head;
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
void LLPractice::insert(int value)
{
    NodeType *temp = new NodeType;
    temp->value = value;
    temp->next = head;
    head = temp;
}

// Function make_empty
// Parameters: none
// Returns: none
// Does: iterates through the list, deallocating
//       NodeType elements as we go
void LLPractice::make_empty()
{
    NodeType *temp = head;
    NodeType *next_ptr = head->next;

    while (temp != NULL)
    {
        delete temp;
        temp = next_ptr;

        if (next_ptr != NULL)
        {
            next_ptr = next_ptr->next;
        }
    }
    head = NULL;
}


