#include <stdio.h>
#include <stdlib.h>
#include "dataTypes.h"

Queue * newQueue(){
  Queue * queue = malloc(sizeof(Queue));
  queue->front = NULL;
  queue->back = NULL;
  queue->size = 0;
  return queue;
}

void printQueue(Queue * queue) {
  Node * cur = queue->front;
  printf("Queue: ");
  while (cur != NULL) {
    printf("%d ", cur->data);
    cur = cur->next;
  }
  printf("\n");
}

void enqueue(Queue * queue, int data){
  queue->size++;
  Node * newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (queue->front == NULL) {
    queue->front = newNode;
    queue->back = newNode;
    return;
  }

  queue->back->next = newNode;
  queue->back = newNode;
}

int dequeue(Queue * queue) {
  if (queue->front == NULL) {
    return -1;
  }

  Node * cur = queue->front;
  int d = cur->data;
  queue->front = queue->front->next;
  free(cur);

  queue->size--;
  return d;
}

void clearQueue(Queue * list){
  Node * cur = list->front;
  while(cur != NULL) {
    Node * next = cur->next;
    free(cur);
    cur = next;
  }
  list->front = NULL;
  list->back = NULL;
  list->size = 0;
}

Stack * newStack(){
  Stack * stack = malloc(sizeof(Stack));
  stack->top = NULL;
  stack->size = 0;
  return stack;
}

void printStack(Stack * stack) {
  Node * cur = stack->top;
  printf("Stack: ");
  while (cur != NULL) {
    printf("%d ", cur->data);
    cur = cur->next;
  }
  printf("\n");
}

void push(Stack * stack, int data) {
  stack->size++;
  Node * newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = stack->top;
  stack->top = newNode;
}

int pop(Stack * stack){
  if (stack->top == NULL) {
    return -1;
  }

  Node * cur = stack->top;
  int d = cur->data;
  stack->top = stack->top->next;
  free(cur);
  
  stack->size--;
  return d;
}

void clearStack(Stack * list){
  Node * cur = list->top;
  while(cur != NULL) {
    Node * next = cur->next;
    free(cur);
    cur = next;
  }
  list->top = NULL;
  list->size = 0;
}