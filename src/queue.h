#ifndef QUEUE_H
#define QUEUE_H

#include "bt_basics.h"

typedef struct QueueNode {
    bt_p *data;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;

Queue *createQueue();
void enqueue(Queue *q, bt_p *data);
bt_p *dequeue(Queue *q);
int isQueueEmpty(Queue *q);
void clearQueue(Queue *q);

#endif
