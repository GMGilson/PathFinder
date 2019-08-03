#!/usr/bin/env bash


valgrind -v --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes --log-file="./memcheck/grindlog.txt" ./cmake-build-debug/Rat-In-A-Maze.out
