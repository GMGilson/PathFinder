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
    room(std::vector<int> doors):doors(doors), visited(false){}

    std::vector<room*> getAdjList()
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





private:
    std::vector<room*> adjList;
    bool visited;
    std::vector<int> doors;
};


#endif //RAT_IN_A_MAZE_ROOM_H
