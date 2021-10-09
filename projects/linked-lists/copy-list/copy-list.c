#include <stdlib.h>

#include "../node.h"

void appendNode(struct node* nodeToAdd,
                struct node** listHeadRef,
                struct node** listTailRef) {
  if (*listHeadRef == NULL) {
    *listHeadRef = nodeToAdd;
  }
  if (*listTailRef) {
    (*listTailRef)->next = nodeToAdd;
  }
  *listTailRef = nodeToAdd;
}

struct node* copyNode(struct node* originalNode) {
  struct node* copy = malloc(sizeof(struct node));
  copy->data = originalNode->data;
  copy->next = NULL;
  return copy;
}

struct node* copyList(struct node* originalHead) {
  struct node* copyHead = NULL;
  struct node* copyTail = NULL;
  struct node* currentNode = originalHead;
  while (currentNode) {
    struct node* nodeCopy = copyNode(currentNode);
    appendNode(nodeCopy, &copyHead, &copyTail);
    currentNode = currentNode->next;
  }
  return copyHead;
}
