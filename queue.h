//
// Created by grant on 8/2/19.
//

#ifndef RAT_IN_A_MAZE_QUEUE_H
#define RAT_IN_A_MAZE_QUEUE_H

#include "room.h"
#include "node.h"

class queue
{
public:

    queue():head(nullptr), tail(nullptr), len(0){}

    void enqueue(room* room)
    {
        node* temp = new node(room, nullptr);
        getTail()->setNext(temp);
        setTail(temp);
        ++this->len;
    }

    room* dequeue()
    {
        auto node = getHead(); //grab the front of the queue
        auto room = node->getRoom(); //get the room from that node

        setHead(getHead()->getNext()); // set the new head one past the original
        delete node; //delete old head
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

    void setTail(node* tail )
    {
        this->tail = tail;
    }

    int getLen()
    {
        return len;
    }

    node *getTail()
    {
        return tail;
    }

    bool empty() //returns false if queue contains an object
    {
        return this->len == 0;
    }


private:
    node* head;
    node* tail;
    int len;

};






#endif //RAT_IN_A_MAZE_QUEUE_H
