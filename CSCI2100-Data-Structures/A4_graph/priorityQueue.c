#include <stdlib.h>
#include <stdbool.h>
#include "priorityQueue.h"
#include "graph.h"

struct priorityQueueCDT {
    pQueueElementT heap[1000];
    int numOfElem;
};

priorityQueueADT EmptyPriorityQueue() {
    priorityQueueADT queue;
    queue = (priorityQueueADT)malloc(sizeof(*queue));
    queue->numOfElem = 0;
    return queue;
}

bool PriorityQueueIsEmpty(priorityQueueADT queue) {
    return queue->numOfElem == 0;
}

void PriorityEnqueue(priorityQueueADT queue, pQueueElementT element, GraphADT G) {
    int hole;
    for (hole = (queue->numOfElem)++;
         hole==0 ? false : ArcWeight(G,queue->heap[(hole - 1) / 2]) > ArcWeight(G,element);
         hole = (hole-1)/2 )
        queue->heap[hole] = queue->heap[(hole-1)/2];
    queue->heap[hole] = element;
}

pQueueElementT PriorityDequeue(priorityQueueADT queue,GraphADT G) {
    pQueueElementT result, v;
    int hole, child;
    if (PriorityQueueIsEmpty(queue)) exit(EXIT_FAILURE);
    result = queue->heap[0];
    v = queue->heap[--(queue->numOfElem)];
    for (hole=0; 2*hole+1<queue->numOfElem; hole=child) {
        child = 2*hole+1;
        if (child + 1 < queue->numOfElem && ArcWeight(G,queue->heap[child + 1]) < ArcWeight(G,queue->heap[child]))
            child++;
        if (ArcWeight(G,v) > ArcWeight(G,queue->heap[child]))
            queue->heap[hole] = queue->heap[child];
        else
            break;
    }
    queue->heap[hole] = v;
    return result;
}
