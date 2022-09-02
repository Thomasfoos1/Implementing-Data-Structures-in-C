#include <stdio.h>
#include "tree.h"

int main() {
  TNode * r = newTNode(1);
  for (int i=2; i<128; i++) {
    treeInsert(r, i);
  }

  treeBalance(&r);
  treeInvert(r);
  printTree(r);
  treeClear(r);
}