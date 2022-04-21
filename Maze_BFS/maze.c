#include "queue.h"

bool Movable(Pos cur, int dir)
{
	switch (dir) {
		case 0:	cur.x--; break; // ��
		case 1:	cur.y++; break; // ��
		case 2:	cur.x++; break; // ��
		case 3:	cur.y--; break; // ��
	}

	if (cur.x < 0 || cur.y < 0 || cur.x >= MAX || cur.y >= MAX)	// ���� ����ٸ�
		return false;
	else if (Maze[cur.x][cur.y] == 1 || Maze[cur.x][cur.y] < 0)	// ������ or �Ķ���
		return false;
	else if (Maze[cur.x][cur.y] == 0)	// �ʷϻ�
		return true;
}

Pos Move_to(Pos cur, int dir)
{
	switch (dir) {
		case 0:	cur.x--; break; // ��
		case 1:	cur.y++; break; // ��
		case 2:	cur.x++; break; // ��
		case 3:	cur.y--; break; // ��
	}

	return cur;
}

Pos Move_to_low_number(Pos cur) 
{
	int low_num = Maze[cur.x][cur.y]+1;
	Maze[cur.x][cur.y] = 2;	// �����

	if (Maze[cur.x - 1][cur.y] == low_num)	// ��
		cur.x--;
	else if (Maze[cur.x][cur.y + 1] == low_num)	// ��
		cur.y++;
	else if (Maze[cur.x + 1][cur.y] == low_num)	// ��
		cur.x++;
	else if (Maze[cur.x][cur.y - 1] == low_num)	// ��
		cur.y--;
	return cur;
}

bool Find_way(Pos cur)
{
	return cur.x == MAX - 1 && cur.y == MAX - 1;
}
