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
    maze() = default;

    ~maze()
    {
        for(auto &i : getRooms())
        {
            delete i.second;
        }
    }

    void prepRooms()
    {

    }

    void addRoom(int key, std::vector<int> flags)
    {
        auto r = new room(flags);
        getRooms().insert({key, r});
    }

    void connectRooms(room* room1, room* room2)
    {
        room1->getAdjList().push_back(room2);
        room2->getAdjList().push_back(room1);
    }

    bool keyExist(int key)
    {
        auto iter = rooms.find(key);
        return iter == rooms.end();
    }

    void solveDFS();

    void solveBFS();

    std::map<int, room *> &getRooms()
    {
        return this->rooms;
    }


private:
    std::map<int, room* > rooms;
};


#endif //RAT_IN_A_MAZE_MAZE_H
