#ifndef DATA_STRUCTURES
#define DATA_STRUCTURES

#include "dataTypes.h"

Queue * newQueue();
void printQueue(Queue * queue);
void enqueue(Queue * queue, int data);
int dequeue(Queue * queue);
void clearQueue(Queue * list);

Stack * newStack();
void printStack(Stack * stack);
void push(Stack * stack, int data);
int pop(Stack * stack);
void clearStack(Stack * list);

#endif