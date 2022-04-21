#ifndef __MAZE_H__
#define __MAZE_H__

#define MAX 16
#include <stdio.h>
#include <stdbool.h>

typedef struct Position {
	int x, y;
}Pos;

int Maze[MAX][MAX];

bool Movable(Pos, int);
Pos Move_to(Pos, int);
bool Find_way(Pos);

#endif

