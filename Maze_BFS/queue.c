#include "queue.h"
#include "maze.h"

typedef struct node* Node;
typedef struct queue* Queue;

void Terminate(const char* message)
{
	printf("%s\n", message);
	exit(1);
}

Node Create_node()
{
	Node new_node = (Node)malloc(sizeof(struct node));
	if (new_node == NULL)
		terminate("Error in Create_node : Node could not be created.");

	new_node->x = 0;
	new_node->y = 0;
	new_node->next = NULL;

	return new_node;
}

Queue Create_queue()
{
	Queue new_queue = (Queue)malloc(sizeof(struct queue));
	if (new_queue == NULL)
		terminate("Error in Create_queue : Queue could not be created.\n");

	new_queue->front = NULL;
	new_queue->rear = NULL;
	new_queue->size = 0;

	return new_queue;
}

void Enqueue(Queue queue, Pos cur)
{
	Node new_node = Create_node();
	new_node->x = cur.x;
	new_node->y = cur.y;

	if (Is_empty(queue)) {
		queue->front = new_node;
		queue->rear = new_node;
	}

	else {
		queue->rear->next = new_node;
		queue->rear = new_node;
	}
	queue->size++;
}

Pos Dequeue(Queue queue)
{
	if (Is_empty(queue))
		terminate("Error in Peek : Queue is empty.");

	Node Front_node = queue->front;
	Node Rear_node = queue->rear;
	Pos old_cur;
	old_cur.x = Front_node->x;
	old_cur.y = Front_node->y;

	queue->front = Front_node->next;
	queue->size--;

	Destroy_node(Front_node);

	// 큐 삭제하고 다시 할당할때 버그....
	if (Is_empty(queue))
		Destroy_queue(queue);

	return old_cur;
}

void Destroy_node(Node Front_node)
{
	free(Front_node);
	Front_node->next = NULL;
	Front_node->x = NULL;
	Front_node->y = NULL;
}

// 큐 삭제할때 버그...
void Destroy_queue(Queue queue)
{
	free(queue);
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
}

Pos Peek(Queue queue)
{
	if (Is_empty(queue))
		terminate("Error in Peek : Queue is empty.");
	Pos cur;
	cur.x = queue->front->x;
	cur.y = queue->front->y;

	return cur;
}

bool Is_empty(Queue queue)
{
	// return queue->size == 0;
	return queue->front == NULL;
}

void Print_queue(Queue queue)
{
	if (Is_empty(queue))
		printf("'queue' is Empty\n\n");
	else {
		Node Front_node = queue->front;
		Node Rear_node = queue->rear;
		Node node = queue->front;

		printf("Front node : (%d, %d)\n", Front_node->x, Front_node->y);
		printf("Rear node : (%d, %d)\n", Rear_node->x, Rear_node->y);

		for (int i = 0; i < queue->size; i++) {
			printf("(%d, %d)", node->x, node->y);
			node = node->next;

			if (i == queue->size - 1)
				printf("\n\n");
			else
				printf(" --> ");
		}
	}
}