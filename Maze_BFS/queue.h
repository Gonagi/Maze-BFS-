#ifndef __QUEUE_H__
#define __QUEUE_H__

#endif
#include <stdio.h>
#include <stdbool.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

typedef struct node* Node;
typedef struct queue* Queue;
typedef int Item;

struct node {
	Item x, y;
	Node next;
};

struct queue {
	Node front;	
	Node rear;	
	int size;
};

void Terminate(const char*);
Node Create_node();
Queue Create_queue();
void Enqueue(Queue, Pos);
Pos Dequeue(Queue);
void Destroy_node(Queue);
void Destroy_queue(Queue);
Pos Peek(Queue queue);
bool Is_empty(Queue);
void Print_queue(Queue);