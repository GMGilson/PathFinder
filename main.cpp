//
// Created by grant on 8/2/19.
//

#include <iostream>
#include <fstream>
#include "maze.h"



int main(int argc, char** argv)
{
    if(argc == 2)
    {
        std::fstream mazeFile;
        mazeFile.open(argv[1]);

        maze Maze = maze();
        int key = 0;
        int N;
        mazeFile >> N; //stores the size of the maze

        for (int k = 0; k < (N * N); ++k) {
            std::vector<int> flags;
            for (int i = 0; i < 4; ++i) {
                int temp;
                mazeFile >> temp;
                flags.push_back(temp);
            }
            Maze.addRoom(key, flags);

            key++;
        }

        Maze.generateMaze(N);

        Maze.printMaze(N);

        auto bfsPath = Maze.solveBFS();
        auto dfsPath = Maze.solveDFS();

        Maze.printPath(bfsPath, N);
        std::cout << "Path determined by DFS" << std::endl;
        for(auto &i : dfsPath)
            std::cout << i->getRoomNumber() << " ";
        Maze.printPath(dfsPath , N);

        std::cout << "Path determined by BFS" << std::endl;
        for(auto &i : dfsPath)
            std::cout << i->getRoomNumber() << " ";
        Maze.printPath(bfsPath, N);

        mazeFile.close();
    }

    else if(argc > 2)
    {
        std::cout << "invalid arguments";
        return 69;
    }
    else
    {
        //generate graph with closed doors
        int N;
        std::cout << "Input maze size" << std::endl;
        std::cin >> N;
        maze Maze = maze();
        for (int i = 0; i < (N * N) ; ++i)
        {
            std::vector<int> flags = {1,1,1,1};
            Maze.addRoom(i, flags);
        }
        Maze.prepRooms();
        Maze.linkAdjRooms(N);


        //Maze.getRooms()[0]->isUnvisitedAdjCells();

        Maze.randRoomFlags();
        Maze.generateMaze(N);

        auto dfsPath = Maze.solveDFS();
        auto bfsPath = Maze.solveBFS();

        Maze.printMaze(N);
        std::cout << "Path determined by DFS" << std::endl;
        for(auto &i : dfsPath)
            std::cout << i->getRoomNumber() << " ";
        Maze.printPath(dfsPath , N);

        std::cout << "Path determined by BFS" << std::endl;
        for(auto &i : dfsPath)
            std::cout << i->getRoomNumber() << " ";
        Maze.printPath(bfsPath, N);

    }
    return 100;
}


