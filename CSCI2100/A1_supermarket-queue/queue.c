/*
 queue.c
 */
#include <stdlib.h>
#include "queue.h"
#include <stdio.h>

struct queueCDT {
    queueElementT Q[10000]; /* max length 10000 */
    int count;
};

queueADT EmptyQueue(){
    queueADT queue = (queueADT)malloc(sizeof(*queue));
    queue->count = 0;
    return queue;
}

void Enqueue(queueADT queue, queueElementT element){
    queue->Q[queue->count++] = element;
}

queueElementT Dequeue(queueADT queue){
    queueElementT result;
    
    if (QueueIsEmpty(queue)) exit(EXIT_FAILURE); /* error */
    
    result = queue->Q[0];
    for (int i=0; i<queue->count; i++) queue->Q[i] = queue->Q[i+1];
    queue->count--;
    return result;
}

int QueueLength(queueADT queue) {
    return queue->count;
}

int QueueIsEmpty(queueADT queue) {
    return  QueueLength(queue) == 0;
}
