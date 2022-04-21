#include <Windows.h>
#include "queue.h"

#define PATH 0			// 지나갈 수 있는 위치			// 초록
#define WALL 1			// 지나갈 수 없는 위치			// 빨강
#define WAY 2			// 최종 길						// 노랑

void Read_maze();
void Print_maze();
void Print_final_way(Pos);
void Textcolor(int, int);
enum ColorType { WHITE = 15, BLACK = 0, RED = 4, BLUE = 9, GREEN = 10, YELLOW = 14}COLOR;    // 흰 검 빨 파 초 sh

int main()
{
	Queue queue = Create_queue();
	Pos cur, Save;
	cur.x = 0; cur.y = 0;
	Enqueue(queue, cur);
	
	Read_maze();
	Maze[cur.x][cur.y] = -1;	// 지나온 길 (파란색)

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
			if (Maze[i][j] == 0) { Textcolor(BLACK, GREEN); printf("□"); }		// 갈 수 있는 길 (초록색)
			else if (Maze[i][j] == 1) { Textcolor(BLACK, RED); printf("□"); }	// 갈 수 없는 길 (빨간색)
			else if (Maze[i][j] < 0) { Textcolor(BLACK, BLUE); printf("□"); }	// 지나온 길	(파란색)
			else if (Maze[i][j] == 2) { Textcolor(BLACK, YELLOW); printf("□"); }	// 최종 길 (노란색)
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