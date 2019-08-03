//
// Created by grant on 8/2/19.
//

#include <iostream>
#include <fstream>
#include "maze.h"



int main(int argc, char** argv)
{
    if(argc != 2)
    {
        std::cout << "invalid arguments";
        return 69;
    }

    std::fstream mazeFile;
    mazeFile.open(argv[1]);

    maze Maze = maze();
    int key = 0;
    int N;
    mazeFile >> N; //stores the size of the maze

    for (int k = 0; k <(N*N) ; ++k)
    {
        std::vector<int> flags;
        for (int i = 0; i < 4; ++i)
        {
            int temp;
            mazeFile >> temp;
            flags.push_back(temp);
        }
        Maze.addRoom(key, flags);

        key++;
    }

    for(auto &j : Maze.getRooms())
    {
        //check north
        if(!j.second->getDoors()[0])
            if(j.first - N >= 0)// in case we are checking the top edge of the maze
                Maze.connectRooms(j.second, Maze.getRooms()[j.first - N]);

        //check south
        if(!j.second->getDoors()[1]) // in case we are checking the south edge of the maze
            if(j.first + N < (N * N))
                Maze.connectRooms(j.second, Maze.getRooms()[j.first + N]);

        //check east
        if(!(j.second->getDoors()[2]))
            Maze.connectRooms(j.second, Maze.getRooms()[j.first + 1]);

        //check west
        if(!j.second->getDoors()[3])
            Maze.connectRooms(j.second, Maze.getRooms()[j.first - 1]);
    }



    mazeFile.close();
    return 100;
}