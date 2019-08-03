//
// Created by grant on 8/3/19.
//

#ifndef RAT_IN_A_MAZE_LINKEDLIST_H
#define RAT_IN_A_MAZE_LINKEDLIST_H

#include "node.h"

class linkedList
{
public:
    //empty constructor
    linkedList():head(nullptr), tail(nullptr), len(0){};

    //copy constructor
    linkedList(linkedList& copy)
    {

    }
private:
    node* head;
    node* tail;
    int len;
};


#endif //RAT_IN_A_MAZE_LINKEDLIST_H