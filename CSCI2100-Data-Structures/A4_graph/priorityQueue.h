/*
 * File: priorityQueue.h
 */
#include <stdbool.h>
#include "graph.h"

typedef struct priorityQueueCDT *priorityQueueADT;

typedef ArcADT pQueueElementT;

priorityQueueADT EmptyPriorityQueue(void);
void PriorityEnqueue(priorityQueueADT, pQueueElementT, GraphADT);
pQueueElementT PriorityDequeue(priorityQueueADT, GraphADT);
bool PriorityQueueIsEmpty(priorityQueueADT);
