#ifndef STRUCTURES
#define STRUCTURES

typedef struct Node{
  int data;
  struct Node * next;
}Node;

typedef struct {
  Node * back;
  Node * front;
  int size;
}Queue;

typedef struct{
  Node * top;
  int size;
}Stack;

#endif