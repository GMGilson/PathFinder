# Path Finder

[![asciicast](https://asciinema.org/a/Rid4vSw96v76Bs2cdndULwhPX.svg)](https://asciinema.org/a/Rid4vSw96v76Bs2cdndULwhPX)

## DeAnza CIS 22C Summer Term Project

### Objectives
- Create Maze
  - Generate random NxN sized maze where N is specified by the user
  - Read in maze file from system arguments
- Solve Maze using:
  - Depth First Search
  - Breadth First Search

### Random Maze Generation

Assuming rooms are uniquely numbered from left to right, top to bottom.

```
While (S.find(0) != S.find(N - 1)):
  Choose randomly a pair (i, j) of adjacent rooms i and j
  If (S.find(i) != S.find(j)):
    Open the doors connecting rooms i and j in the maze;
    S.union(S.find(i), S.find(j);
   _ _ _ 
| |    _|
| | |_  |
| |_|   |
|_ _ _| |
```

### Maze Solving

* After a maze is generated, we want to solve it using bot Depth First Search and Breadth First Search.
*  We will then print out the path taken to solve the maze and the rooms visited by each algorithm to compare.