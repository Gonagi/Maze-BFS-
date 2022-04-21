#include "queue.h"

bool Movable(Pos cur, int dir)
{
	switch (dir) {
		case 0:	cur.x--; break; // 북
		case 1:	cur.y++; break; // 동
		case 2:	cur.x++; break; // 남
		case 3:	cur.y--; break; // 서
	}

	if (cur.x < 0 || cur.y < 0 || cur.x >= MAX || cur.y >= MAX)	// 범위 벗어났다면
		return false;
	else if (Maze[cur.x][cur.y] == 1 || Maze[cur.x][cur.y] < 0)	// 빨간색 or 파란색
		return false;
	else if (Maze[cur.x][cur.y] == 0)	// 초록색
		return true;
}

Pos Move_to(Pos cur, int dir)
{
	switch (dir) {
		case 0:	cur.x--; break; // 북
		case 1:	cur.y++; break; // 동
		case 2:	cur.x++; break; // 남
		case 3:	cur.y--; break; // 서
	}

	return cur;
}

Pos Move_to_low_number(Pos cur) 
{
	int low_num = Maze[cur.x][cur.y]+1;
	Maze[cur.x][cur.y] = 2;	// 노란색

	if (Maze[cur.x - 1][cur.y] == low_num)	// 북
		cur.x--;
	else if (Maze[cur.x][cur.y + 1] == low_num)	// 동
		cur.y++;
	else if (Maze[cur.x + 1][cur.y] == low_num)	// 남
		cur.x++;
	else if (Maze[cur.x][cur.y - 1] == low_num)	// 서
		cur.y--;
	return cur;
}

bool Find_way(Pos cur)
{
	return cur.x == MAX - 1 && cur.y == MAX - 1;
}
