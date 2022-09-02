#ifndef QUEUE
#define QUEUE

typedef struct Node{
  void * data;
  struct Node * next;
}Node;

typedef struct {
  Node * back;
  Node * front;
  int size;
}Queue;

void printQueue(Queue * queue);
Queue * newQueue();
void enqueue(Queue * queue, void * data);
void * dequeue(Queue * queue);
void clearQueue(Queue * list);

#endif