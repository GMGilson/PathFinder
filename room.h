//
// Created by grant on 8/2/19.
//

#ifndef RAT_IN_A_MAZE_ROOM_H
#define RAT_IN_A_MAZE_ROOM_H


#include <string>
#include <vector>


class room
{
public:
    room(int number, std::vector<int> doors):roomNumber(number), doors(doors), visited(false){}

    explicit room(int number):roomNumber(number), visited(false){};

    std::vector<room*> &getAdjList()
    {
        return this->adjList;
    }

    void setVisited(bool visited)
    {
        this->visited = visited;
    }

    bool isAdj(room* room)
    {
        for(auto i : adjList)
        {
            if(i == room)
                return true;
        }
        return false;
    }

    std::vector<int> &getDoors()
    {
        return this->doors;
    }

    bool isVisited()
    {
        return visited;
    }

    std::vector<room*> &getAdjRooms()
    {
        return this->adjRooms;
    }


private:
    int roomNumber;
    std::vector<room*> adjList; // list of adj rooms that have an open door with the current room
    std::vector<int> doors; //an array of flags to denote which doors are open {N, S, E, W}
    bool visited{};
    std::vector<room*> adjRooms; //list of rooms directly adj to the current room

};


#endif //RAT_IN_A_MAZE_ROOM_H
