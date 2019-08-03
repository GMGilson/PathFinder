//
// Created by grant on 8/2/19.
//

#ifndef RAT_IN_A_MAZE_NODE2_H
#define RAT_IN_A_MAZE_NODE2_H

#include "room.h"

class node
{
public:
    node(room* room, node* next):room(room), next(next){};

    node *getNext()
    {
        return this->next;
    }

    room *getRoom()
    {
        return this->room;
    }

    void setNext(node *next)
    {
        this->next = next;
    }


private:
    room* room;
    node* next;
};


#endif //RAT_IN_A_MAZE_NODE2_H
