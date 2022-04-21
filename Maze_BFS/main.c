#include <Windows.h>
#include "queue.h"

#define PATH 0			// ������ �� �ִ� ��ġ			// �ʷ�
#define WALL 1			// ������ �� ���� ��ġ			// ����
#define WAY 2			// ���� ��						// ���

void Read_maze();
void Print_maze();
void Print_final_way(Pos);
void Textcolor(int, int);
enum ColorType { WHITE = 15, BLACK = 0, RED = 4, BLUE = 9, GREEN = 10, YELLOW = 14}COLOR;    // �� �� �� �� �� sh

int main()
{
	Queue queue = Create_queue();
	Pos cur, Save;
	cur.x = 0; cur.y = 0;
	Enqueue(queue, cur);
	
	Read_maze();
	Maze[cur.x][cur.y] = -1;	// ������ �� (�Ķ���)

	while (!Is_empty(queue)){
		cur = Dequeue(queue);

		if (Find_way(cur)) {
			printf("End.\n");
			break;
		}

		for (int dir = 0; dir < 4; dir++) {
			if (Movable(cur, dir)) {
				Save = Move_to(cur, dir);
				Maze[Save.x][Save.y] = Maze[cur.x][cur.y] - 1;
				Enqueue(queue, Save);
			}
		}

		Print_maze();
	}
	Print_final_way(cur);
	Print_maze();
	int a = 0;
}

void Read_maze()
{
	FILE* fp = NULL;
	fopen_s(&fp, "maze.txt", "r");

	if (fp == NULL) {
		printf("Error in Read_maze\n");
		exit(1);
	}

	for (int i = 0; i < MAX; i++) 
		for (int j = 0; j < MAX; j++)
			fscanf_s(fp, "%d", &Maze[i][j]);

	fclose(fp);
}

void Print_maze()
{
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (Maze[i][j] == 0) { Textcolor(BLACK, GREEN); printf("��"); }		// �� �� �ִ� �� (�ʷϻ�)
			else if (Maze[i][j] == 1) { Textcolor(BLACK, RED); printf("��"); }	// �� �� ���� �� (������)
			else if (Maze[i][j] < 0) { Textcolor(BLACK, BLUE); printf("��"); }	// ������ ��	(�Ķ���)
			else if (Maze[i][j] == 2) { Textcolor(BLACK, YELLOW); printf("��"); }	// ���� �� (�����)
		}
		Textcolor(WHITE, BLACK);
		printf("\n");
	}
	printf("\n");
}

void Print_final_way(Pos cur)
{
	printf("\nFinal way\n");
	while ((cur.x != 0) || (cur.y != 0)) 
		cur = Move_to_low_number(cur);

	Maze[cur.x][cur.y] = 2;
}

void Textcolor(int forground, int background)
{
	int color = forground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}