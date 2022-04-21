#include <Windows.h>
#include "queue.h"

#define PATH 0			// ������ �� �ִ� ��ġ			// �ʷ�
#define WALL 1			// ������ �� ���� ��ġ			// ����

void Read_maze();
void Print_maze();
void Textcolor(int, int);
enum ColorType { WHITE = 15, BLACK = 0, RED = 4, BLUE = 9, GREEN = 10}COLOR;    // �� �� �� �� �� 

int main()
{
	Pos cur;

	Read_maze();
	while (1) {
		if (Find_way(cur)) {
			printf("End.\n");
			break;
		}

		Print_maze();
	}
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
		}
		Textcolor(WHITE, BLACK);
		printf("\n");
	}
}


void Textcolor(int forground, int background)
{
	int color = forground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}