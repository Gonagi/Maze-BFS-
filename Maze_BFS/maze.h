#ifndef __MAZE_H__
#define __MAZE_H__

#define MAX 16
#include <stdio.h>
#include <stdbool.h>

typedef struct Position {
	int x, y;
}Pos;

int Maze[MAX][MAX];

void Move_to(Pos, int);
bool Find_way(Pos);

#endif

