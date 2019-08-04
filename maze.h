//
// Created by grant on 8/2/19.
//

#ifndef RAT_IN_A_MAZE_MAZE_H
#define RAT_IN_A_MAZE_MAZE_H


#include <map>
#include <string>
#include "room.h"
//#include "queue.h"
#include "stack.h"
#include <iostream>
#include <queue>
#include <random>
#include <ctime>


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

    //adds roomPtr to maze
    void addRoom(int key, std::vector<int> flags)
    {
        auto r = new room(key , flags);
        getRooms().insert({key, r});
    }

    void addRoom(int key)
    {
        auto r = new room(key);
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

    //will solve the maze using DFS
    std::vector<room*> solveDFS()
    {

        prepRooms();
        std::vector<room*> path;

        std::vector<std::vector<room*>> stack;

        getRooms()[0]->setVisited(true);
        path.push_back(getRooms()[0]);
        stack.push_back(path);
        while(!stack.empty())
        {
            path = stack.back();
            stack.pop_back();
            auto last = path[path.size() - 1 ];

            if (last == getRooms()[getRooms().size() - 1])
                return path;
            for(auto &i : last->getAdjList())
            {
                if (!i->isVisited())
                {
                    i->setVisited(true);
                    std::vector<room*> newPath(path);
                    newPath.push_back(i);
                    stack.push_back(newPath);

                }
            }

        }
        //this case should never happen but is required with -wall - wextra - werror compiler flags
        std::vector<room*> fail;
        return fail;
    }

    //will solve the maze using BFS
    std::vector<room*> solveBFS()
    {
        prepRooms();

        std::vector<room*> path;

        std::queue<std::vector<room*>> q;

        getRooms()[0]->setVisited(true);
        path.push_back(getRooms()[0]);
        q.push(path);
        while (!q.empty())
        {
            path = q.front();
            q.pop();
            auto last = path[path.size() -1];

            if(last == getRooms()[getRooms().size() - 1])
                return path;

            for(auto &i : last->getAdjList())
            {
                if(!i->isVisited())
                {
                    i->setVisited(true);
                    std::vector<room*> newPath(path);
                    newPath.push_back(i);
                    q.push(newPath);
                }
            }
        }
        //this case should never happen but is necessary to compile with -Wall -Wextra -Werror
        std::vector<room*> fail;
        return fail;
    }


    std::map<int, room *> &getRooms()
    {
        return this->rooms;
    }


    //This will inspect the flags of each room
    //Adding rooms to their respective adjacency list
    //This function assumes that flags are properly assigned and
    // that there is no mismatch between rooms and their adjacent room's flags
    //ie room1 has an open north door but room2 which is above it does not have a corresponding south door open
    void generateMaze(int N) 
    {
        ///i feel there should be a better way of doing this 8/1/2019
        for (auto &j : this->getRooms())
        {
            //check north
            if (!j.second->getDoors()[0])
                if (j.first - N >= 0)// in case we are checking the top edge of the maze
                    this->connectRooms(j.second, this->getRooms()[j.first - N]);

            //check south
            if (!j.second->getDoors()[1]) // in case we are checking the south edge of the maze
                if (j.first + N < (N * N))
                    this->connectRooms(j.second, this->getRooms()[j.first + N]);

            //check east
            if (!(j.second->getDoors()[2]))
                this->connectRooms(j.second, this->getRooms()[j.first + 1]);

            //check west
            if (!j.second->getDoors()[3])
                this->connectRooms(j.second, this->getRooms()[j.first - 1]);
        }
    }

    //this function is only used for generating a random maze
    //All rooms will have at least 2 connections and at most 4 connections
    //Visual::
    //    o-o-o-o
    //    | | | |
    //    o-o-o-o
    //    | | | |
    //    o-o-o-o
    //    | | | |
    //    o-o-o-o
    //This does not represent which doORs are open
    //Only links adjacent rooms together so we can randomly open doors later
    void linkAdjRooms(int N)
    {

        //creates links between adjacent rooms for easier traversal for random graph generation
        for (auto &i : this->getRooms()) {
            ///holy fuck i hate this section
            ///I really shot myself in the foot with this fucking class layout 8/4/2019
            ///wHY DID I DECIDE THAT AN ARRAY OF FLAGS TO DENOTE THE WALLS WAS A GOOD IDEA 8/5/2019


            //checks to see if we can link below
            if (i.first + N < (N * N))
                i.second->getAdjRooms().push_back(this->getRooms()[i.first + N]);

            //checks to see if we can link above
            if (i.first - N >= 0)
                i.second->getAdjRooms().push_back(this->getRooms()[i.first - N]);

            //checks to see if we can link left
            if (i.first % N != 0)
                i.second->getAdjRooms().push_back(this->getRooms()[i.first - 1]);

            if (i.first % N != N - 1)
                i.second->getAdjRooms().push_back(this->getRooms()[i.first + 1]);

        }
    }

    bool isComplete()
    {
        ulong count = 1;
        for( auto &i : getRooms())
        {
            if(i.second->isVisited())
                ++count;

        }
        if(count == getRooms().size())
            this->complete = true;

        return this->complete;
    }

    void randRoomFlags(int N)
    {
        prepRooms();
        std::srand(5);
        this->getRooms()[0]->getDoors()[0] = 0; //creates "entry point" for the maze
        this->getRooms()[this->getRooms().size() - 1]->getDoors()[3] = 0; //creates "exit point" for the maze

        this->getRooms()[0]->setVisited(true);
        std::vector<int> stack;
        stack.push_back(0);
        while (!isComplete())
        {
            auto i = stack.back();
            int randAdj = rand() % getRooms()[i]->getAdjRooms().size();
            if (!getRooms()[randAdj]->isVisited())
            {
                stack.push_back(getRooms().find(randAdj).operator*().first);


            }

        }

    }

    void opendoors(room* room1, room* room2)
    {

    }



private:
    std::map<int, room* > rooms;
    bool complete;
};


#endif //RAT_IN_A_MAZE_MAZE_H
