#include "queue.h"

bool Movable(Pos cur, int dir)
{
	switch (dir) {
		case 0:	cur.x--; break; // ��
		case 1:	cur.y++; break; // ��
		case 2:	cur.x++; break; // ��
		case 3:	cur.y--; break; // ��
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