#include "queue.h"

bool Movable(Pos cur, int dir)
{
	switch (dir) {
		case 0:	cur.x--; break; // ºÏ
		case 1:	cur.y++; break; // µ¿
		case 2:	cur.x++; break; // ³²
		case 3:	cur.y--; break; // ¼­
	}

	if (Maze[cur.x][cur.y] == 0)  
		return true;
	else 
		return false;
}

void Move_to(Pos cur, int dir)
{

}

bool Find_way(Pos cur)
{
	return cur.x == MAX - 1 && cur.y == MAX - 1;
}