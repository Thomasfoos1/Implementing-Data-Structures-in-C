// #include <stdio.h>
// #include <stdlib.h>

// typedef struct PNode {
//   int data;
//   int priority;
//   struct PNode * next;
// }PNode;

// typedef struct {
//   PNode * front;
//   int size;
// }PQueue;

// PQueue * newPQueue(){
//   PQueue * queue = malloc(sizeof(PQueue));
//   queue->front = NULL;
//   queue->size = 0; 
//   return queue;
// }

// void printPQueue(PQueue * queue) {
//   PNode * cur = queue->front;
//   printf("Priority Queue: ");
//   while (cur != NULL) {
//     printf("%d ", cur->data);
//     cur = cur->next;
//   }
//   printf("\n");
// }

// void priorityEnqueue(PQueue * pq, int data, int priority) {
//   pq->size++;
  
//   PNode * newNode = malloc(sizeof(PNode));
//   newNode->priority = priority;
//   newNode->data = data;

//   //queue empty
//   if (pq->front == NULL) {
//     newNode->next = NULL;
//     pq->front = newNode;
//     return;
//   }

//   PNode * cur = pq->front;

//   //front edge case
//   if (priority > cur->priority) {
//     newNode->next = cur;
//     pq->front = newNode;
//     return;
//   }

//   //Traverse queue until priority > nextNode or null
//   while (cur->next != NULL) {
//     if (priority > cur->next->priority) {
//       break;
//     }
//     cur = cur->next;
//   }

//   newNode->next = cur->next;
//   cur->next = newNode;
// }

// int priorityDequeue(PQueue * queue) {
//   if (queue->front == NULL) {
//     return -1;
//   }

//   PNode * cur = queue->front;
//   int d = cur->data;
//   queue->front = queue->front->next;
//   free(cur);

//   queue->size--;
//   return d;
// }

// void clearPriorityQueue(PQueue * list) {
//   PNode * cur = list->front;
//   while(cur != NULL) {
//     PNode * next = cur->next;
//     free(cur);
//     cur = next;
//   }
//   list->front = NULL;
//   list->size = 0;
// }

// int main(void) {
//   PQueue * q = newPQueue();
//   priorityEnqueue(q, 1, 2);
//   priorityEnqueue(q, 2, 2);
//   priorityEnqueue(q, 3, 3);
//   priorityEnqueue(q, 4, 3);
//   priorityEnqueue(q, 5, 1);
//   printf("%d\n", priorityDequeue(q));
//   printPQueue(q);
//   clearPriorityQueue(q);
//   printPQueue(q);
// }