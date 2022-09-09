#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXQUEUE 10

enum
{
	false,
	true
};

typedef struct
{
	long arrive;
	int processtime;
} Item;

typedef struct node
{
	Item item;
	struct node *next;
} Node;

typedef struct queue
{
	Node *front;
	Node *rear;
	int items;
} Queue;

typedef struct
{
	long served;
	long line_wait;
	long sum_line;
	long wait_time;
} Barber;

void InitializeQueue(Queue *pq);

int QueueIsFull(const Queue *pq);
int QueueIsEmpty(const Queue *pq);

int QueueItemCount(const Queue *pq);

int EnQueue(Item item, Queue *pq);

int DeQueue(Item *pitem, Queue *pq);

void EmptyTheQueue(Queue *pq);

#endif
