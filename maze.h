//
// Created by grant on 8/2/19.
//

#ifndef RAT_IN_A_MAZE_MAZE_H
#define RAT_IN_A_MAZE_MAZE_H


#include <map>
#include <string>
#include "room.h"

class maze
{
public:

    ~maze()
    {
        for(auto &i : getRooms())
        {
            delete i.second;
        }
    }

    //sets the visited member to false for all rooms in the maze
    void prepRooms()
    {
        for(auto &i : getRooms())
        {
            i.second->setVisited(false);
        }

    }

    //adds room to maze
    void addRoom(int key, std::vector<int> flags)
    {
        auto r = new room(key , flags);
        getRooms().insert({key, r});
    }

    //establishes a one way link between two rooms
    void connectRooms(room* room1, room* room2)
    {
        room1->getAdjList().push_back(room2);
        //room2->getAdjList().push_back(room1);
    }

    //checks to see a key already exists in the map
    bool keyExist(int key)
    {
        auto iter = rooms.find(key);
        return iter == rooms.end();
    }
//
//    //will solve the maze using DFS
//    void solveDFS();
//
//    //will solve the maze using BFS
//    void solveBFS();

    std::map<int, room *> &getRooms()
    {
        return this->rooms;
    }


private:
    std::map<int, room* > rooms;
};


#endif //RAT_IN_A_MAZE_MAZE_H
