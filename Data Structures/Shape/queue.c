#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

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

void enqueue(Queue * queue, void * data){
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

void * dequeue(Queue * queue) {
  if (queue->front == NULL) {
    return -1;
  }

  Node * cur = queue->front;
  void * d = cur->data;
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