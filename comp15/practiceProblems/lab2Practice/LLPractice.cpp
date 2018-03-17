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

// Function insert
// Input: integer, value to insert at head 
// of linked lis
// Returns: nothing
// Does: allocates new NodeType, sets value 
// to given int, updates pointer
// sets head pointer to it 
void LLPractice::insert(int value)
{
    NodeType *temp = new NodeType;
    temp->value = value;
    temp->next = head;
    head = temp;
}

// Function get_value_at
// Input: integer, position of value to return
// Returns: integer
// Does: Returns value at provided index
int LLPractice::get_value_at(int index) const
{
    if(index < 0 || get_length() == 0 || index >= get_length())
    {
        return FAIL;
    }
    
    int current_index = 0;
    NodeType *current = head;
    
    while (current_index < index)
    {
        current = current->next;
        current_index++;
    }
    return current->value

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


