#include <Windows.h>
#include "queue.h"

#define PATH 0			// 지나갈 수 있는 위치			// 초록
#define WALL 1			// 지나갈 수 없는 위치			// 빨강

void Read_maze();
void Print_maze();
void Textcolor(int, int);
enum ColorType { WHITE = 15, BLACK = 0, RED = 4, BLUE = 9, GREEN = 10}COLOR;    // 흰 검 빨 파 초 

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
			if (Maze[i][j] == 0) { Textcolor(BLACK, GREEN); printf("□"); }		// 갈 수 있는 길 (초록색)
			else if (Maze[i][j] == 1) { Textcolor(BLACK, RED); printf("□"); }	// 갈 수 없는 길 (빨간색)
			else if (Maze[i][j] < 0) { Textcolor(BLACK, BLUE); printf("□"); }	// 지나온 길	(파란색)
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