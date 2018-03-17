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
	void delete_value_at(int index);

	void insert(int value);
	int get_value_at(int index) const;
	int get_length() const;
	void make_empty();

  private:
	NodeType *head;
};

#endif
