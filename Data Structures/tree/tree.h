#ifndef TREE
#define TREE
#include "queue.h"

typedef struct TNode {
  int data;
  struct TNode * right;
  struct TNode * left;
} TNode;

TNode * newTNode(int data);
void treeInsert(TNode * root, int data);
int treeHeight(TNode * root);
void printTree(TNode * root);
void treeInvert(TNode * root);
void treeLeftView(TNode * root);
void treeClear(TNode * r);
int treeNodeCount(TNode * root);
void treeInorder(TNode * root, int * arr, int * count);
void treeBalance(TNode ** root);

#endif