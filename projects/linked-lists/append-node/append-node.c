#include <stdlib.h>

#include "../node.h"

/*
  Adds a node to the tail of a list.
  This is the inefficient method where instead of keeping track
  of the tail, we just iterate your way down from the head each time.
*/
void appendNode(struct node** listHeadRef, int val) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->data = val;
  newNode->next = NULL;
  if (*listHeadRef == NULL) {
    // the list is empty
    *listHeadRef = newNode;
  } else {
    struct node* nodePtr = *listHeadRef;
    while (nodePtr->next) {
      nodePtr = nodePtr->next;
    }
    nodePtr->next = newNode;
  }
}
