#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

TNode * newTNode(int data){
  TNode * t = malloc(sizeof(TNode));
  t->data = data;
  t->right = NULL;
  t->left = NULL;

  return t;
}

void treeInsert(TNode * root, int data) {
  TNode * newNode = newTNode(data);

  TNode * cur = root;
  while(1) {
    if (data >= cur->data){
      if (cur->right == NULL) {
        cur->right = newNode;
        break;
      }
      cur = cur->right;
    }
    else {
      if (cur->left == NULL) {
        cur->left = newNode;
        break;
      }
      cur = cur->left;
    }
  }
}

int max (int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

int treeHeight(TNode * root) {
  if (root == NULL) {
    return 0;
  } else {
    return 1 + max(treeHeight(root->right), treeHeight(root->left));
  }
}

void printTree(TNode * root) {
  Queue * q = newQueue(); //BFS queue
  enqueue(q, root);

  int levelsLeft = treeHeight(root);  //max tree levelsLeft
  int curLevel = 1;               //Num nodes in current level
  int nextLevel = 0;              //Num nodes in next level
  
  //Indent each level right 2^(levelsLeft-1)-1 spaces
  int spaces = (1<<(levelsLeft-1));
  for (int i=0; i < 2*spaces; i++) {
    printf(" ");
  }

  while (q->size != 0) {
    TNode * cur = dequeue(q);
    if (cur->data != -1) {
      printf("%3d", cur->data);
    } else {
      printf("   ");
    }

    //Indent between each node right 2^(levelsLeft)-1 spaces
    spaces = ((1<<levelsLeft) - 1);
    for (int i=0; i < (2*spaces - 1); i++) {
        printf(" ");
    }

    //Check left and right subtree and add nodes to BFS Queue
    //if either are null replace with empty space
    if (cur->left != NULL) {
      enqueue(q, cur->left);
      nextLevel++;
    } else if (levelsLeft > 1) {
      enqueue(q, newTNode(-1));
      nextLevel++;
    }
    if (cur->right != NULL) {
      enqueue(q, cur->right);
      nextLevel++;
    } else if (levelsLeft > 1) {
      enqueue(q, newTNode(-1));
      nextLevel++;
    }

    curLevel--;
    if(curLevel == 0) {   //End of level reached
      curLevel = nextLevel;
      nextLevel = 0;
      levelsLeft--;
      printf("\n\n");

      //indent new level
      spaces = (1<<(levelsLeft-1));
      for (int i=0; i< 2 * spaces; i++) {
        printf(" ");
      }
    }
  }

  printf("\n");
}

void treeInvert(TNode * root) {
  if (root == NULL) {
    return;
  } else {
    TNode * tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    treeInvert(root->left);
    treeInvert(root->right);
  }
}

void treeLeftView(TNode * root) {
  Queue * q = newQueue();
  enqueue(q, root);
  int curLevel = 1;
  int nextLevel = 0;

  printf("Left View: %d ", root->data);

  while (q->size != 0) {
    TNode * cur = dequeue(q);

    if (cur->left != NULL) {
      enqueue(q, cur->left);
      nextLevel++;
    }
    if (cur->right != NULL) {
      enqueue(q, cur->right);
      nextLevel++;
    }

    curLevel--;
    if(curLevel == 0) {
      curLevel = nextLevel;
      nextLevel = 0;
      if (q->front != NULL) {
        TNode * n = (TNode*)q->front;
        printf("%d ", n->data);
      }
    }
  }
  printf("\n");
}

void treeClear(TNode * r) {
  if (r == NULL) {
    return;
  }
  treeClear(r->left);
  treeClear(r->right);
  free(r);
}

int treeNodeCount(TNode * root){
  if (root == NULL){
    return 0;
  } else {
    return 1 + treeNodeCount(root->left) + treeNodeCount(root->right);
  }
}

void treeInorder(TNode * root, int * arr, int * count) {
  if (root == NULL) {
    return;
  }
  treeInorder(root->left, arr, count);
  arr[*count] = root->data;
  *count = *count + 1;
  treeInorder(root->right, arr, count);
}

void addToBalancedTree(TNode * root, int * arr, int l, int h){
  if(l>h) {
    return;
  } else if (l==h) {
    treeInsert
  
(root, arr[l]);
    return;
  }
  int m = (h+l)/2;
  treeInsert
(root, arr[m]);
  addToBalancedTree(root, arr, l, m-1);
  addToBalancedTree(root, arr, m+1, h);
}

void treeBalance(TNode ** root) {
  int numNodes = treeNodeCount(*root);
  int * arr = malloc(sizeof(int) * numNodes);
  int count = 0;
  treeInorder(*root, arr, &count);
  treeClear(*root);
  int m = (numNodes-1)/2;
  TNode * newTree = newTNode(arr[m]);
  addToBalancedTree(newTree, arr, 0, m-1);
  addToBalancedTree(newTree, arr, m+1, numNodes-1);
  *root = newTree;
}