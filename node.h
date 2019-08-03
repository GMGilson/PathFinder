//
// Created by grant on 8/2/19.
//

#ifndef RAT_IN_A_MAZE_NODE2_H
#define RAT_IN_A_MAZE_NODE2_H

#include "room.h"

class node
{
public:
    node(room* room, node* next): roomPtr(room), next(next){};

    node *getNext()
    {
        return this->next;
    }

    room *getRoom()
    {
        return this->roomPtr;
    }

    void setNext(node *next)
    {
        this->next = next;
    }


private:
    room* roomPtr;
    node* next;
};


#endif //RAT_IN_A_MAZE_NODE2_H
