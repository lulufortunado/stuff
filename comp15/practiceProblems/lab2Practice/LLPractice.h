#include <iostream>

#ifndef LLPRACTICE_H
#define LLPRACTICE_H

const int FAIL = -1;

struct NodeType {
     int value;
	 NodeType *next;
};

class LLPractice 
{
 public:
    LLPractice();

    void print() const;
    void insert(int index);
    int get_value_at(int index) const;
	void delete_value_at(int index);
	int get_length() const;

  private:
	NodeType *head;
};

#endif
