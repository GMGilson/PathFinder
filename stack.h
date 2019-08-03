//
// Created by grant on 8/2/19.
//

#ifndef RAT_IN_A_MAZE_STACK_H
#define RAT_IN_A_MAZE_STACK_H

#include "node.h"
#include "room.h"

class stack
{
public:

    stack():head(nullptr), len(0){}

    void push(room* room)
    {
        auto temp = new node(room, getHead());
        setHead(temp);
        ++this->len;

    }

    room* pop()
    {
        auto temp = getHead();
        auto room = temp->getRoom();

        setHead(temp->getNext());
        delete temp;
        --this->len;
        return room;
    }

    node *getHead()
    {
        return this->head;
    }

    void setHead(node *head)
    {
        this->head = head;
    }


    int getLen()
    {
        return len;
    }

    bool empty() //returns false if queue contains an object
    {
        return this->len == 0;
    }




private:
    node* head;
    int len;

};



#endif //RAT_IN_A_MAZE_STACK_H
