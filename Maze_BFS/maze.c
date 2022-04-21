#include "queue.h"

bool Movable(Pos cur, int dir)
{
	switch (dir) {
		case 0:	cur.x--; break; // ºÏ
		case 1:	cur.y++; break; // µ¿
		case 2:	cur.x++; break; // ³²
		case 3:	cur.y--; break; // ¼­
	}

	if (cur.x < 0 || cur.y < 0 || cur.x >= MAX || cur.y >= MAX)	// ¹üÀ§ ¹þ¾î³µ´Ù¸é
		return false;
	else if (Maze[cur.x][cur.y] == 1 || Maze[cur.x][cur.y] < 0)	// »¡°£»ö or ÆÄ¶õ»ö
		return false;
	else if (Maze[cur.x][cur.y] == 0)
		return true;

	switch (Maze[cur.x][cur.y]) {
	case 0: return true;	// ÃÊ·Ï»ö
	case 1: return false;	// »¡°£»ö
	case 2
	}

	else if (Maze[cur.x][cur.y] == 0)  
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