//
// Created by grant on 8/2/19.
//

#include <iostream>
#include <fstream>
#include "queue.h"


int main(int argc, char** argv)
{
    if(argc != 2)
    {
        std::cout << "invalid arguments";
        return 69;
    }

    std::fstream mazeFile;
    mazeFile.open(argv[1]);




    mazeFile.close();
    return 100;
}