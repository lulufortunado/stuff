#include "Survivor.h"

#ifndef TREE_H_
#define TREE_H_

typedef Survivor TreeItem;

struct BinaryNode
{
    TreeItem info;
    BinaryNode *left;
    BinaryNode *right;
};


#endif
