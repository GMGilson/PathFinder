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

    std::vector<int> getDoors()
    {
        return this->doors;
    }

    bool isVisited()
    {
        return visited;
    }


private:
    int roomNumber;
    std::vector<room*> adjList;
    std::vector<int> doors;
    bool visited;

};


#endif //RAT_IN_A_MAZE_ROOM_H
